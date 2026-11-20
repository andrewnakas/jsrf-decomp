/* sym: ?func_000CD800@Object_000EDC30@@UAEXXZ = 0x000EE5A0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The object in data_00257CE8; func_00157F10 is the engine's (it returns 0).
struct Object_00157F10 {
    int func_00157F10(void *point, int value);
};

extern Object_00157F10 *data_00257CE8;

struct Object_0006DB80 {
    void func_0006DEB0(int key, int value);
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
};

struct Limits_000CC020 {
    char unknown_00[0x14];
    int value_14;
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

// The class whose table is at 0x1CEFAC (constructor func_000EDC30).
struct Object_000EDC30 : Object_000CD1E0 {
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();

    unsigned int count;
    char unknown_070[0x50];
    char point_0c0[0x2b8];
    int key_378;
};

// Slot 6: once func_00157F10 of data_00257CE8 no longer holds the point at 0xc0, the owner loses flags 0x100 and 1,
// the state becomes 2 (4 while 0x6c is at most 2) and the key at 0x378 goes to func_0006DEB0 of data_00251F78.
void Object_000EDC30::func_000CD800()
{
    if (!data_00257CE8->func_00157F10(point_0c0, limits->value_14)) {
        owner->flags &= ~0x101;
        state = count > 2 ? 2 : 4;
        if (key_378 != -1) {
            data_00251F78.func_0006DEB0(key_378, 1);
        }
    }
}
