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
    int modes[2];
    int slot;

    void func_000F2300();
};

// When the mode the index at 0x30 selects (of the two at 0x28) is 2: state 22, timer 60, and the owner
// gets flag 0x2000000.
void Object_000F2AA0::func_000F2300()
{
    if (modes[slot] == 2) {
        state = 22;
        timer = 60;
        owner->flags |= 0x2000000;
    }
}
