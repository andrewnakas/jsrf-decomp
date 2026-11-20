struct Object_000A1C50 {
    char unknown_000[0xa78];
    unsigned char flags_a78;
    char unknown_a79[0xb];
    int unknown_a84;
    char unknown_a88[0x24c];
    float speed;

    int func_0007F9E0();
    int func_000836A0();
};

// With the top bit of +0xa78: whether the speed at +0xcd4 is above 1.1574074 or +0xa84 above 0x1555, unless +0xa84
// is below 0x1555 and func_0007F9E0 answers.
int Object_000A1C50::func_000836A0()
{
    if (flags_a78 & 0x80) {
        if (unknown_a84 < 0x1555 && func_0007F9E0()) {
            return 0;
        }
        if (speed > 1.1574074f || unknown_a84 > 0x1555) {
            return 1;
        }
    }
    return 0;
}
