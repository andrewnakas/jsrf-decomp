struct Object_000FC4A0 {
    char unknown_00[0x70];
    float value_70;
    float value_74;
    char unknown_78[8];
    int value_80;
    char unknown_84[4];
    int value_88;
    char unknown_8c[8];
    int mode;

    int func_000FC4A0(int mode);
};

// Sets the mode at 0x94 and returns it; mode 4 also sets 0x74 to 1, 0x70 to 255 and copies 0x88 to 0x80.
// The result: retail keeps the mode in eax to the end and copies 0x88 through edx (0xfc4af-0xfc4c3).
int Object_000FC4A0::func_000FC4A0(int mode)
{
    this->mode = mode;
    if (mode == 4) {
        value_74 = 1.0f;
        value_70 = 255.0f;
        value_80 = value_88;
    }
    return mode;
}
