struct Source_000EE930 {
    char unknown_00[0xc];
    int value_0c;
    char unknown_10[8];
    int value_18;
};

struct Object_000EE930 {
    char unknown_00[0xd4];
    Source_000EE930 *source;
    int value_d8;
    int mode;
    char unknown_e0[0x10];
    int value_f0;

    void func_000EE930();
};

// Takes the fields at 0xf0 and 0xd8 from the source at 0xd4 (its 0x18 and 0xc) and sets the mode at 0xdc
// to 2.
void Object_000EE930::func_000EE930()
{
    Source_000EE930 *source = this->source;
    value_f0 = source->value_18;
    mode = 2;
    value_d8 = source->value_0c;
}
