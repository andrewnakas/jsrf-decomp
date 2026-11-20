struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Limits_000CC020 {
    char unknown_00[0x58];
    int duration;
};

struct Object_000DCBC0 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int timer;
    char unknown_014[0x1c];
    Limits_000CC020 *limits;
    char unknown_034[0x18c];
    int next;

    void func_000DD930();
};

// A handler of the table at 0x217A20 (entry 19): once the timer passes the limit at +0x58, state 0x14, 0xc at 0x1c0,
// the owner's flag 0x8000000 set and the timer restarted.
void Object_000DCBC0::func_000DD930()
{
    if (++timer > limits->duration) {
        state = 0x14;
        next = 0xc;
        owner->flags |= 0x8000000;
        timer = 0;
    }
}
