struct Owner_000DC1C0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000DC160 {
    int unknown_00;
    Owner_000DC1C0 *owner;
    char unknown_08[0x90];
    int mode;
    char unknown_9c[0x10];
    int timer;

    void func_000DC1C0();
};

// A handler of the tables that hold func_000DC160 and func_000DC1A0: the owner at 4 loses flag 0x2000000,
// and the timer at 0xac counts down; when it runs out the mode at 0x98 is cleared.
void Object_000DC160::func_000DC1C0()
{
    owner->flags &= ~0x2000000;
    if (--timer <= 0) {
        mode = 0;
    }
}
