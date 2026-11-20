int func_0004EB80(int first, unsigned int second);
void func_000FE4E0(int kind, int first, int second);

struct Object_000A1C50 {
    char unknown_000[0xc9c];
    int value_c9c;
    char unknown_ca0[0x31c];
    int value_fbc;

    void func_0009BCF0();
};

// When func_0004EB80(1, 4) reports true and the field at 0xc9c is clear: func_000FE4E0(0x1e, the value at
// 0xfbc, 0).
void Object_000A1C50::func_0009BCF0()
{
    if (func_0004EB80(1, 4) && !value_c9c) {
        func_000FE4E0(0x1e, value_fbc, 0);
    }
}
