struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Vector3 velocity;
    float value_5c;
    float step;
    char unknown_64[4];
    int value_68;
    char unknown_6c[0x14];
    Vector3 home;
    Vector3 value_8c;
    char unknown_98[0xc];
    unsigned int flags;
    Vector3 *target;
    char unknown_ac[0x34];
    int value_e0;
    int value_e4;

    void func_000C5B50(int *handle);
};

struct Limits_000CC020 {
    char unknown_00[0x28];
    int value_28;
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

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    Vector3 start;
    char unknown_20[0x10];
    Limits_000CC020 *limits;
    char unknown_34[0x28];
    int value_5c;
};

// Slot 5: puts the owner back at its home (0x80, also kept at 0x14) with its 0x8c at 0x50, clears its speeds, its
// fields at 0x68, 0xe0 and 0xe4, targets the point at 0x7c of data_00257CE4, takes 0x5c from the object at 0x30,
// restarts the count and moves to state 1 with the owner's flags 0x101 set.
void Object_000CCE00::func_000CBCD0()
{
    start = owner->home;
    owner->position = owner->home;
    owner->step = 0.0f;
    owner->value_5c = 0.0f;
    owner->velocity = owner->value_8c;
    owner->value_e4 = 0;
    owner->value_e0 = 0;
    owner->target = &data_00257CE4->unknown_7c;
    value_5c = limits->value_28;
    owner->value_68 = 0;
    count = 0;
    state = 1;
    owner->flags |= 0x101;
}
