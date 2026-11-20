struct Owner_000F2AA0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000F2AA0 {
    int unknown_00;
    Owner_000F2AA0 *owner;
    int state;
    int timer;
    char unknown_10[0x20];
    unsigned int count;
    int value_34;

    void func_000F2500(int index);
    void func_000F2920();
};

// A handler of the table at 0x21B0F0: func_000F2500(0) and (1); the count goes up: under 3, state 28 and the owner's
// flag 0x2000000, else state 30; the timer restarts at 120 either way.
void Object_000F2AA0::func_000F2920()
{
    func_000F2500(0);
    func_000F2500(1);
    if (++count < 3) {
        state = 0x1c;
        owner->flags |= 0x2000000;
        timer = 0x78;
    } else {
        state = 0x1e;
        timer = 0x78;
    }
}
