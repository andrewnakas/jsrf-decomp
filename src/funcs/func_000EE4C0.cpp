/* sym: ?func_000CD210@Object_000EDC30@@UAEXXZ = 0x000EE4C0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Motion_0005F060;

// The motions at 0xf8.
struct Source_000EDC30 {
    char unknown_00[0x1c];
    Motion_0005F060 *motion_1c;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x50];
    int angles[3];
    char unknown_5c[4];
    float value_60;
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
    char unknown_070[0x38];
    float speeds[4];
    char unknown_0b8[0x28];
    int heading;
    int value_e4;
    char unknown_0e8[8];
    int value_f0;
    char unknown_0f4[4];
    Source_000EDC30 *source;
    char unknown_0fc[0x10];
    float time_10c;
    float time_110;
    float time_114;
    char unknown_118[0x27c];
    Motion_0005F060 *motion;
    float time;
    int effects[2];
    int values[4];
};

// Slot 5: the base's func_000CD210, then levels the owner (its x and z angles 0) keeping its heading at 0xe0, sets
// its 0x60 and the four speeds at 0xa8 to -0.01, the three times at 0x10c to -1, starts the source's motion at 0x1c
// at 0x394, two kind-0x2c effects of object 0xe8 at 0x39c and clears the four values at 0x3a4.
void Object_000EDC30::func_000CD210()
{
    Object_000CD1E0::func_000CD210();
    owner->angles[2] = 0;
    owner->angles[0] = 0;
    heading = owner->angles[1];
    value_e4 = 0;
    speeds[0] = speeds[1] = speeds[2] = speeds[3] = owner->value_60 = -0.01f;
    time_10c = -1.0f;
    time_110 = -1.0f;
    time_114 = -1.0f;
    value_f0 = 0;
    motion = source->motion_1c;
    time = 0.0f;
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        effects[0] = object->func_000651E0(0x2c, 0, 0);
    }
    object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        effects[1] = object->func_000651E0(0x2c, 0, 0);
    }
    memset(values, 0, sizeof(values));
}
