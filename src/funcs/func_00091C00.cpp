struct Object_000A1C50 {
    char unknown_000[0x9d8];
    int value_9d8;

    void func_0007FD20();
    void func_00089E00();
    void func_000A0610(int value);
    void func_00091C00();
};

// Runs func_00089E00 and func_0007FD20, then func_000A0610(1) when the field at 0x9d8 is set.
void Object_000A1C50::func_00091C00()
{
    func_00089E00();
    func_0007FD20();
    if (value_9d8) {
        func_000A0610(1);
    }
}
