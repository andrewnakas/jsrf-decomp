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
    char unknown_18[0x10];
    int busy_28;
    int busy_2c;

    void func_000F2350();
};

// A handler of the table at 0x21B0F0 (entry 25): unless +0x28 or +0x2c is set, state 0 while the owner has a flag
// of 0x80002000, else state 1 with 2 at 0x14 and the timer at 240.
void Object_000F2AA0::func_000F2350()
{
    if (busy_28 || busy_2c) {
        return;
    }
    if (!(owner->flags & 0x80002000)) {
        state = 1;
        next = 2;
        timer = 0xf0;
    } else {
        state = 0;
    }
}
