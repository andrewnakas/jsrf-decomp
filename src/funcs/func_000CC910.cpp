struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

// The owner at 0x4: its position at 0x44, speed at 0x5c, tries at 0x68, flags at 0xa4, the point it aims at (0xa8)
// and its leader and follower at 0xe0 and 0xe4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float speed;
    char unknown_60[8];
    int value_68;
    char unknown_6c[0x38];
    unsigned int flags;
    Vector3 *target;
    char unknown_ac[0x34];
    Object_000C5B50 *leader;
    Object_000C5B50 *follower;
};

// The object in data_00257CE4: the box at 0, its point at 0x7c.
struct Object_000C1270 {
    int box;
    char unknown_04[0x78];
    Vector3 point;
};

extern Object_000C1270 *data_00257CE4;

// The behaviour's tuning: a count at 0, a limit at 4, a braking step at 0x14 and the near level at 0x18.
struct Limits_000CC020 {
    int count;
    float limit;
    char unknown_08[0xc];
    float brake;
    float nearLevel;
};

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

    void func_000CC1A0();
    int func_000CC040();
    void func_000CC4B0(float value);
    int func_000CC540();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
};

// Slot 7: with data_00257CE4 on a box, func_000C1630 allowing and the owner nearer its point than the near level,
// state 9, flag 2 and func_000CC540; a led owner then leaves its leader (whose follower is cleared) and aims at the
// point. Otherwise the count at 0x10 steps (state 2 past the tuning's count); when func_000CC040 reports true the
// speed follows the limit (func_000CC4B0) and an owner without a leader counts a try and looks for a partner
// (func_000CC1A0); else the owner brakes by the tuning's step down to 0 and the state is 2.
void Object_000CCE00::func_000CC910()
{
    if (data_00257CE4->box >= 0 && data_00257CE8->func_000C1630()
        && limits->nearLevel > func_0014C530(&data_00257CE4->point, &owner->position)) {
        state = 9;
        owner->flags |= 2;
        func_000CC540();
        if (owner->leader) {
            owner->leader->follower = 0;
            owner->leader = 0;
            owner->target = &data_00257CE4->point;
        }
        return;
    }
    if (count++ > limits->count) {
        state = 2;
    }
    if (func_000CC040()) {
        func_000CC4B0(limits->limit);
        if (!owner->leader) {
            owner->value_68++;
            func_000CC1A0();
        }
        return;
    }
    if (owner->speed > 0.0f) {
        owner->speed -= limits->brake;
        if (owner->speed < 0.0f) {
            owner->speed = 0.0f;
        }
    }
    state = 2;
}
