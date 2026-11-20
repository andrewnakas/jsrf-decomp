struct Source_000D5390 {
    char unknown_00[0xb0];
    int value_b0;
};

struct Object_000D5390 {
    char unknown_000[0xf00];
    Source_000D5390 *source;
    int value_f04;
    char unknown_f08[0x14];
    int value_f1c;
    char unknown_f20[0x10];
    int value_f30;

    void func_000D5390();
};

// Takes the field at 0xf04 from the source at 0xf00 and clears the fields at 0xf1c and 0xf30.
void Object_000D5390::func_000D5390()
{
    value_f04 = source->value_b0;
    value_f1c = 0;
    value_f30 = 0;
}
