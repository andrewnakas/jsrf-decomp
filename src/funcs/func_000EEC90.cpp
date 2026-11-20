struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1E60();
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x5c];
    float value_5c;
    char unknown_60[0x44];
    unsigned int flags;
};

// The motions at 0xf8.
struct Source_000EDC30 {
    char unknown_00[8];
    Motion_0005F060 *motion_08;
    char unknown_0c[0xc];
    Motion_0005F060 *motion_18;
    char unknown_1c[4];
    Motion_0005F060 *motion_20;
};

// The class of func_000EDC30; these are handlers of its table at 0x21A900.
struct Object_000EDC30 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int timer;
    char unknown_014[0xc8];
    int value_0dc;
    char unknown_0e0[8];
    int value_0e8;
    int value_0ec;
    int count;
    char unknown_0f4[4];
    Source_000EDC30 *source;
    char unknown_0fc[4];
    int value_100;
    char unknown_104[8];
    float time_10c;
    float time_110;
    char unknown_114[0x280];
    Motion_0005F060 *motion;
    float time;

    void func_000EE780();
    void func_000EE8D0();
    void func_000EEBE0();
    void func_000EEC90();
};

// A handler of the table at 0x21A900: plays the source's motions at 0x18 and 8 on the times at 0x10c and 0x110 while
// they are not negative, each time going to -1 when its motion ends; then the count at 0xf0 and 0xe8 are cleared,
// 0xdc becomes 5 and 0xec 0x111.
void Object_000EDC30::func_000EEC90()
{
    if (time_10c >= 0.0f && func_0005E030(source->motion_18, &time_10c, 0.5f, 1)) {
        time_10c = -1.0f;
    }
    if (time_110 >= 0.0f && func_0005E030(source->motion_08, &time_110, 0.5f, 1)) {
        time_110 = -1.0f;
    }
    count = 0;
    value_0dc = 5;
    value_0e8 = 0;
    value_0ec = 0x111;
}
