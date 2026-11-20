struct Owner_000D16D0 {
    char unknown_00[0x60];
    float step;
};

struct Object_000D27F0 {
    int unknown_000;
    Owner_000D16D0 *owner;
    int state;
    char unknown_00c[0xc];
    float time;
    char unknown_01c[0xf14];
    int value_f30;
    char unknown_f34[4];
    int mode;

    void func_000D16D0();
};

// A handler of the table that holds the merged func_000D1700 (whose class it shares): advances the time at
// 0x18 by the owner's step at 0x60; when the mode at 0xf38 is 2, state 11 and the field at 0xf30 = 8.
void Object_000D27F0::func_000D16D0()
{
    time = owner->step + time;
    if (mode == 2) {
        state = 11;
        value_f30 = 8;
    }
}
