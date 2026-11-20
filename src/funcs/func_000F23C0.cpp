struct Owner_000F2AA0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000F2AA0 {
    int unknown_00;
    Owner_000F2AA0 *owner;
    int state;
    int timer;

    void func_000F23C0();
};

// Counts the timer at 0xc down; when it runs out the state becomes 29 and the owner loses flag 0x2000000.
void Object_000F2AA0::func_000F23C0()
{
    if (--timer <= 0) {
        state = 29;
        owner->flags &= ~0x2000000;
    }
}
