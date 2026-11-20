struct Owner_000E6980 {
    char unknown_00[0x60];
    float step;
    char unknown_64[0x40];
    unsigned int flags;
};

struct Object_000E6590 {
    int unknown_00;
    Owner_000E6980 *owner;
    int state;
    char unknown_0c[0xc];
    float time;
    char unknown_1c[0x14];
    int value_30;
    int mode;

    void func_000E6590();
    void func_000E69A0();
};

// Like func_000E6980: advances the time at 0x18 by the owner's step; in mode 2 it also clears 0x30 and the mode,
// sets state 1 and clears the owner's flag 0x8000; then func_000E6590.
void Object_000E6590::func_000E69A0()
{
    time = owner->step + time;
    if (mode == 2) {
        value_30 = 0;
        mode = 0;
        state = 1;
        owner->flags &= ~0x8000;
    }
    func_000E6590();
}
