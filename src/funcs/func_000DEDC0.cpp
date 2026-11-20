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
    char unknown_00[8];
    float limit_08;
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

    void func_000CC4B0(float value);
    float func_000CCAE0();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
};

extern int data_0021798C;
extern int data_00217998;
extern int data_002179A4;

// The class whose table is at 0x1CE7B8 (constructor func_000DCBC0, which runs func_000CC620 first).
struct Object_000DCBC0 : Object_000CCE00 {
    char unknown_034[0xd4];
    int value_108;
    char unknown_10c[0xb4];
    int next;

    void func_000DE6C0();
    void func_000DEDC0();
};

// A handler of the table at 0x217A20: the first time (the owner's count at 0x68 is 0) gives the owner 12 for its
// position (func_000C5B10), sets its count to 1, takes data_00217998 at 0x108 and 3 at 0x1c0. Counts the owner on;
// once the count had reached data_0021798C, moves to state 10 and sets the count to data_002179A4. Then runs
// func_000CC4B0 with the field at 8 of the object at 0x30, func_000CCAE0 and func_000DE6C0.
void Object_000DCBC0::func_000DEDC0()
{
    Object_000C5B50 *current = owner;
    if (current->count == 0) {
        current->func_000C5B10(12, &current->position);
        owner->count = 1;
        value_108 = data_00217998;
        next = 3;
    }
    if (owner->count++ >= data_0021798C) {
        state = 10;
        owner->count = data_002179A4;
    }
    func_000CC4B0(limits->limit_08);
    func_000CCAE0();
    func_000DE6C0();
}
