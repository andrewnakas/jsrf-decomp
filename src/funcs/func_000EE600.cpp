/* sym: ?func_000CD850@Object_000EDC30@@UAEXXZ = 0x000EE600 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;


// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    float value_50;
    char unknown_54[4];
    float value_58;
    float value_5c;
    char unknown_60[0x10];
    float height;
    char unknown_74[0x28];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;
};

struct Limits_000CC020 {
    char unknown_00[0x18];
    float range;
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

struct Object_000CD1E0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CD1E0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual float func_000CD440();
    virtual float func_000CD4F0();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    void func_000CD310(float rate);

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int timer;
    Vector3 position;
    char unknown_20[0x10];
    Limits_000CC020 *limits;
    char unknown_34[8];
    int index;
    char unknown_40[0x28];
    int value_68;
};

// The limit at 0xd4.
struct Limit_000EDC30 {
    char unknown_00[8];
    float height;
};

// The class whose table is at 0x1CEFAC (constructor func_000EDC30).
struct Object_000EDC30 : Object_000CD1E0 {
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();

    char unknown_06c[0x68];
    Limit_000EDC30 *limit;
    char unknown_0d8[8];
    int heading_e0;
    int heading_e4;
};

// Slot 7: above the limit's height (0xd4, +8) runs Object_000CD1E0's slot 7; otherwise state 3, func_000CD310(0) and
// slot 11. Then both headings at 0xe0 and 0xe4 turn toward 0 by at most 0x3c (func_000C1450 of data_00257CE8).
void Object_000EDC30::func_000CD850()
{
    if (owner->height > limit->height) {
        Object_000CD1E0::func_000CD850();
    } else {
        state = 3;
        func_000CD310(0.0f);
        func_000CD4F0();
    }
    heading_e0 = data_00257CE8->func_000C1450(heading_e0, 0, 0x3c);
    heading_e4 = data_00257CE8->func_000C1450(heading_e4, 0, 0x3c);
}
