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
    int count;
    char unknown_6c[0x38];
    unsigned int flags;
    Vector3 *target;

    int func_000C59A0();
    int func_000C5B10(int message, void *data);
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
    void func_000DEB40();
};

// A handler of the table at 0x217A20: 7 at 0x1c0 and func_000CC4B0(0); then, unless the owner has flag 0x1000000,
// once its test passes (func_000C59A0) moves to state 7, aims it at the point at 0x7c of data_00257CE4, sets the flag
// and gives it 8 for its position (func_000C5B10); then func_000DE6C0.
void Object_000DCBC0::func_000DEB40()
{
    next = 7;
    func_000CC4B0(0);
    if (!(owner->flags & 0x1000000) && owner->func_000C59A0()) {
        state = 7;
        owner->target = &data_00257CE4->unknown_7c;
        owner->flags |= 0x1000000;
        owner->func_000C5B10(8, &owner->position);
    }
    func_000DE6C0();
}
