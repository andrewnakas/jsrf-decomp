struct Owner_000F2AA0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000F2AA0 {
    int unknown_00;
    Owner_000F2AA0 *owner;
    int state;
    int timer;
    char unknown_10[8];
    int modes[4];
    char unknown_28[0x40];
    int slot;

    void func_000F20F0();
};

// When the mode the index at 0x68 selects (of the four at 0x18) is 2: state 4, timer 120, and the owner gets
// flag 0x2000000.
void Object_000F2AA0::func_000F20F0()
{
    if (modes[slot] == 2) {
        state = 4;
        timer = 120;
        owner->flags |= 0x2000000;
    }
}
