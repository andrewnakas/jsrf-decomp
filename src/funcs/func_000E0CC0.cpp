struct Source_000E0CC0 {
    char unknown_00[0xc];
    int value_0c;
    char unknown_10[8];
    int value_18;
};

struct Object_000DC160 {
    char unknown_00[0x8c];
    Source_000E0CC0 *source;
    int value_90;
    char unknown_94[0xc];
    int mode;
    char unknown_a4[0x10];
    int value_b4;

    void func_000E0CC0();
};

// A handler of the member-function table at 0x217e00, next to func_000DC160 (whose class it shares). Takes
// the fields at 0xb4 and 0x90 from the source at 0x8c (its 0x18 and 0xc) and sets the mode at 0xa0
// to 2.
void Object_000DC160::func_000E0CC0()
{
    Source_000E0CC0 *source = this->source;
    value_b4 = source->value_18;
    mode = 2;
    value_90 = source->value_0c;
}
