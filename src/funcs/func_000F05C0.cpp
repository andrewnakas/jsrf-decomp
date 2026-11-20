struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;

    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);
};

// The class of func_000EDC30; this is a handler of its table at 0x21A900.
struct Object_000EDC30 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0xd4];
    int value_0dc;
    char unknown_0e0[0x10];
    int count;
    char unknown_0f4[0x18];
    float time_10c;
    float time_110;
    char unknown_114[0x280];
    Motion_0005F060 *motion;
    float time;
    char unknown_39c[0x24];
    int handles[2];

    void func_000F05C0();
};

// A handler of the table at 0x21A900: clears the owner's flag 0x1000000, plays the motion at 0x394 at half speed,
// releases both handles at 0x3c0 that the owner still knows (func_000C5B70, func_000C5B50); when the count at 0xf0
// runs out, clears 0xdc and puts -1 into both times at 0x10c.
void Object_000EDC30::func_000F05C0()
{
    owner->flags &= ~0x1000000;
    func_0005E030(motion, &time, 0.5f, 1);
    if (owner->func_000C5B70(handles[0])) {
        owner->func_000C5B50(&handles[0]);
    }
    if (owner->func_000C5B70(handles[1])) {
        owner->func_000C5B50(&handles[1]);
    }
    if (--count <= 0) {
        value_0dc = 0;
        time_10c = -1.0f;
        time_110 = -1.0f;
    }
}
