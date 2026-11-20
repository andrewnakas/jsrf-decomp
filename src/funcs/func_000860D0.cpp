// A record of the tables at 0x20D960, 0x20D974 and 0x20D988.
struct Motion_00085F80 {
    float speed;
    float lift;
    float fall;
    int unknown_0c;
    float unknown_10;
};

extern Motion_00085F80 data_0020D988;

struct Object_00086060 {
    char unknown_000[0x84];
    float speed;
    float lift;
    char unknown_08c[0x8];
    unsigned int delay;
    char unknown_098[0x4];
    unsigned int flags;
    char unknown_0a0[0x4];
    Motion_00085F80 *motion;

    void func_000860D0();
};

// Entry 4 of the table at 0x20D9C8: sets flag 1, waits 10 and moves to the motion at 0x20D988 with its speed and lift.
void Object_00086060::func_000860D0()
{
    flags |= 1;
    delay = 10;
    motion = &data_0020D988;
    speed = data_0020D988.speed;
    lift = data_0020D988.lift;
}
