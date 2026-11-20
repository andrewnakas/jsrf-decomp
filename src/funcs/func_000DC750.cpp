/* sym: ?func_000D7880@Object_000DB8F0@@UAEXXZ = 0x000DC750 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1D40.
struct Object_00157F10 {
    int func_000C1D40(int *effect, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

struct Object_0006DB80 {
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    float value_50;
    char unknown_54[4];
    float value_58;
    float value_5c;
    char unknown_60[0x3c];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;

    void func_000C5AD0(int amount);
};

void func_000FEC30(int value, const Vector3 *position);

struct Limits_000CC020 {
    char unknown_00[0x18];
    float range;
};

// A point of the path at 0x70 (24 bytes).
struct Point_000DB8F0 {
    char unknown_00[0xc];
    float value_0c;
    char unknown_10[8];
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

// The class whose table is at 0x1CE780 (constructor func_000DB8F0).
struct Object_000DB8F0 : Object_000CD1E0 {
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000DB8F0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    char unknown_06c[4];
    Point_000DB8F0 *path;
    char unknown_074[0xc0];
    int effect_134;
    int value_138;
    int value_13c;
    int sound_140;
};

// Slot 9: puts the owner at the position at 0x14; unless the owner has flag 0x4000000: when func_000C1D40 of
// data_00257CE8 gives nonzero, the owner gets that flag and func_000C5AD0(1), state 5 and 1 at 0x68, otherwise
// func_000FEC30 with the owner's 0x9c and position; then the sound at 0x140 follows the owner (func_0006DFC0).
void Object_000DB8F0::func_000D7880()
{
    owner->position = position;
    if (!(owner->flags & 0x4000000)) {
        if (data_00257CE8->func_000C1D40(&effect_134, &value_13c, &value_138)) {
            owner->flags |= 0x4000000;
            state = 5;
            owner->func_000C5AD0(1);
            value_68 = 1;
        } else {
            func_000FEC30(owner->value_9c, &owner->position);
        }
        if (sound_140 != -1) {
            data_00251F78.func_0006DFC0(sound_140, &owner->position);
        }
    }
}
