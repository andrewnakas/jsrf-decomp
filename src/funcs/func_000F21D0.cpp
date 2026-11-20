struct Owner_000F2AA0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000F2AA0 {
    int unknown_00;
    Owner_000F2AA0 *owner;
    int state;
    int timer;

    void func_000F21D0();
};

// Counts the timer at 0xc down; when it runs out the state becomes 11 and the owner loses flag 0x2000000.
void Object_000F2AA0::func_000F21D0()
{
    if (--timer <= 0) {
        state = 11;
        owner->flags &= ~0x2000000;
    }
}
