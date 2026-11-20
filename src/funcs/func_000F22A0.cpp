struct Owner_000F2AA0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000F2AA0 {
    int unknown_00;
    Owner_000F2AA0 *owner;
    int state;
    int timer;
    char unknown_10[4];
    int next;
    int busy[4];

    void func_000F22A0();
};

// A handler of the table at 0x21B0F0 (entry at 0x21B13C): when none of the four busy words at 0x18 is set, state 0 while the
// owner has a flag of 0x80002000, else state 1 with 26 at 0x14 and the timer at 120.
void Object_000F2AA0::func_000F22A0()
{
    int idle = 1;
    if (busy[0]) {
        idle = 0;
    }
    if (busy[1]) {
        idle = 0;
    }
    if (busy[2]) {
        idle = 0;
    }
    if (!busy[3] && idle) {
        if (!(owner->flags & 0x80002000)) {
            state = 1;
            next = 0x1a;
            timer = 0x78;
        } else {
            state = 0;
        }
    }
}
