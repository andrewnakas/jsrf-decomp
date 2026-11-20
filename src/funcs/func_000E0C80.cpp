struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000E0440 {
    char unknown_00[4];
    Object_000C5B50 *owner;
    int state;
    char unknown_0c[4];
    int timer;

    void func_000E0C80();
};

// A handler of the table at 0x217E18 (entry 7): after 120 calls, state 8; from the sixth call on, sets the owner's flag
// 0x8000000.
void Object_000E0440::func_000E0C80()
{
    if (++timer > 120) {
        state = 8;
        return;
    }
    if (!(owner->flags & 0x8000000) && timer > 5) {
        owner->flags |= 0x8000000;
    }
}
