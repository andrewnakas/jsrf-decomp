struct Object_0007FAF0 {
    char unknown_000[0x88];
    float unknown_88;
    char unknown_08c[0xa8];
    int unknown_134;

    void func_0007FAF0();
};

// Sets the flag at +0x134 when the value at +0x88 is zero.
void Object_0007FAF0::func_0007FAF0()
{
    if (unknown_88 == 0.0f) {
        unknown_134 = 1;
    }
}
