struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;
    int value_11c;

    void func_000987A0();
    void func_00098910();
    int func_0009C690(int mode);
    void func_00099560();
};

// 9 at 0x11c unless 0x118 is set, then func_0009C690(1), func_000987A0 and func_00098910.
void Object_000A1C50::func_00099560()
{
    if (!value_118) {
        value_11c = 9;
    }
    func_0009C690(1);
    func_000987A0();
    func_00098910();
}
