struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class. Its position at 0x44, its box at 0x64, its list at
// 0x9c, a point followers aim at (0xac) and its leader and follower at 0xe0 and 0xe4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x14];
    int area;
    int value_68;
    char unknown_6c[4];
    float level;
    char unknown_74[0x28];
    int group;
    char unknown_a0[4];
    unsigned int flags;
    Vector3 *target;
    Vector3 trail;
    char unknown_b8[0x28];
    Object_000C5B50 *leader;
    Object_000C5B50 *follower;

    void func_000C5B50(int *handle);
};

struct Object_00066980;

// A link of the per-list chains of data_00257CE4.
struct Link_000C6150 {
    Object_000C5B50 *object;
    Link_000C6150 *next;
};

// The object in data_00257CE4: the lists at 0x4, its point at 0x7c.
struct Object_000C1270 {
    int unknown_00;
    Link_000C6150 *lists[29];
    Object_00066980 *clock;
    Vector3 point;
};

extern Object_000C1270 *data_00257CE4;

// The behaviour's tuning: two levels at 0x18 and 0x1c.
struct Limits_000CC020 {
    char unknown_00[0x18];
    float nearLevel;
    float farLevel;
};

// The table of boxes at data_00257CE0.
struct Object_000BFF60 {
    int func_000BFF80(Vector3 *position);
};

extern Object_000BFF60 *data_00257CE0;

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
    int func_000C1630();
};

extern Object_00157F10 *data_00257CE8;

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

    void func_000CCE00();
    void func_000CC1A0();
    float func_000CCAE0();
    int func_000CC540();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
};

// Slot 10: an owner without a leader looks for a partner (func_000CC1A0) and counts the try at 0x68. The owner's
// level at 0x70 is set (func_000CCAE0); below 0 or with the target out of the owner's box (func_000BFF80) the
// state is 2 and the owner drops flag 0x40. A follower within the tuning's farLevel level gets flag 0x40, beyond it drops
// it; otherwise, within the nearLevel level and when func_000C1630 allows, state 9, flag 2 and func_000CC540.
void Object_000CCE00::func_000CD060()
{
    if (!owner->leader) {
        func_000CC1A0();
        owner->value_68++;
    }
    owner->level = func_000CCAE0();
    Object_000C5B50 *owner = this->owner;
    if (owner->level < 0.0f || owner->area != data_00257CE0->func_000BFF80(owner->target)) {
        state = 2;
        owner->flags &= ~0x40;
        return;
    }
    if (owner->leader && owner->level <= limits->farLevel) {
        owner->flags |= 0x40;
        return;
    }
    if (owner->leader && owner->level > limits->farLevel) {
        owner->flags &= ~0x40;
        return;
    }
    if (owner->level <= limits->nearLevel && data_00257CE8->func_000C1630()) {
        state = 9;
        this->owner->flags |= 2;
        func_000CC540();
    }
}
