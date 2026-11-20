// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x5c];
    float value_5c;
    float step;
    char unknown_64[0x40];
    unsigned int flags;

    void func_000C5B50(int *handle);
};

struct Limits_000CC020 {
    int count;
    char unknown_04[0x10];
    float rate;
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
    char unknown_14[4];
    float time;
    char unknown_1c[0x14];
    Limits_000CC020 *limits;
};

// Slot 8: runs the owner's 0x5c down by the rate at 0x14 of the object at 0x30, to 0; with the owner's flag 0x80
// the time at 0x18 advances by its step at 0x60; once the count at 0x10 passes the count of the object at 0x30,
// state 2.
void Object_000CCE00::func_000CBF20()
{
    if (owner->value_5c > 0.0f) {
        owner->value_5c -= limits->rate;
        if (owner->value_5c < 0.0f) {
            owner->value_5c = 0.0f;
        }
    }
    if (owner->flags & 0x80) {
        time += owner->step;
    }
    if (count++ > limits->count) {
        state = 2;
    }
}
