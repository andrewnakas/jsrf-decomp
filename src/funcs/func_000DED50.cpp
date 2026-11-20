struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000BFF60 {
    int func_000BFF80(Vector3 *position);
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 unknown_7c;
};

extern Object_000BFF60 *data_00257CE0;
extern Object_000C1270 *data_00257CE4;

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x14];
    int area;
    char unknown_68[0x40];
    Vector3 *target;

    void func_000C5B50(int *handle);
};

struct Limits_000CC020 {
    char unknown_00[4];
    int value_04;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE320 (constructor func_000CC620, destructor func_000CC680).
struct Object_000CCE00 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CCE00();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CBF20();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();
    virtual void func_000CC020();

    void func_000CC4B0(int value);
    void func_000CCD10();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
};

// The class whose table is at 0x1CE7B8 (constructor func_000DCBC0, which runs func_000CC620 first).
struct Object_000DCBC0 : Object_000CCE00 {
    char unknown_034[0x18c];
    int next;

    void func_000DE6C0();
    void func_000DED50();
};

// A handler of the table at 0x217A20: 1 at 0x1c0; func_000CC4B0 with the field at 4 of the object at 0x30, then
// func_000CCD10; stores the owner's box (func_000BFF80 of data_00257CE0 on its position) at its 0x64 and, when there
// is one, state 2 and the owner's target at 0xa8 = the point at 0x7c of data_00257CE4; then func_000DE6C0.
void Object_000DCBC0::func_000DED50()
{
    Object_000C5B50 *owner;
    next = 1;
    func_000CC4B0(limits->value_04);
    func_000CCD10();
    this->owner->area = data_00257CE0->func_000BFF80(&this->owner->position);
    owner = this->owner;
    if (owner->area >= 0) {
        state = 2;
        owner->target = &data_00257CE4->unknown_7c;
    }
    func_000DE6C0();
}
