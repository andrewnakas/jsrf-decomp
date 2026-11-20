struct Owner_000F2AA0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000F2AA0 {
    int unknown_00;
    Owner_000F2AA0 *owner;
    int state;
    int timer;
    char unknown_10[0x18];
    int mode;

    void func_000F2390();
};

// When the mode at 0x28 is 2: state 28 with the timer at 60, and the owner gets flag 0x2000000.
void Object_000F2AA0::func_000F2390()
{
    if (mode == 2) {
        state = 28;
        timer = 60;
        owner->flags |= 0x2000000;
    }
}
