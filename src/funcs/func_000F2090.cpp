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
    int value_14;

    void func_000F2090();
};

// Entry 0 of the member-function table at 0x21b0f0: state 1, 8 at 0x14 when the owner has flag 0x4000000 (2
// otherwise), the timer at 0xc set to 60, and the owner's top flag bit cleared.
void Object_000F2AA0::func_000F2090()
{
    state = 1;
    value_14 = (owner->flags & 0x4000000) ? 8 : 2;
    timer = 60;
    owner->flags &= ~0x80000000;
}
