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

    void func_000DD990();
};

// A handler of the table at 0x217A20 (entry 24): once the timer passes the limit at +0x58, state 0x19, 0x10 at 0x1c0,
// the owner's flag 0x8000000 set and the timer restarted.
void Object_000DCBC0::func_000DD990()
{
    if (++timer > limits->duration) {
        state = 0x19;
        next = 0x10;
        owner->flags |= 0x8000000;
        timer = 0;
    }
}
