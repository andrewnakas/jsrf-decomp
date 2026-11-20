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
    char unknown_28[0xc];
    int slot;

    void func_000F21A0();
};

// When the mode the index at 0x34 selects (of the four at 0x18) is 2: state 10, timer 60, and the owner gets
// flag 0x2000000.
void Object_000F2AA0::func_000F21A0()
{
    if (modes[slot] == 2) {
        state = 10;
        timer = 60;
        owner->flags |= 0x2000000;
    }
}
