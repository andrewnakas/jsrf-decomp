struct Source_000EE930 {
    char unknown_00[0xc];
    int value_0c;
    char unknown_10[8];
    int value_18;
};

struct Object_000EE930 {
    char unknown_000[0xd4];
    Source_000EE930 *source;
    int value_d8;
    int mode;
    char unknown_0e0[0x10];
    int value_f0;
    char unknown_0f4[0x2a4];
    int value_398;

    void func_000EEEA0();
};

// A handler next to func_000EE930 in its table: takes 0xf0 and 0xd8 from the source at 0xd4 (its 0x18 and
// 0xc), sets the mode at 0xdc to 7 and clears 0x398.
void Object_000EE930::func_000EEEA0()
{
    Source_000EE930 *source = this->source;
    value_f0 = source->value_18;
    mode = 7;
    value_d8 = source->value_0c;
    value_398 = 0;
}
