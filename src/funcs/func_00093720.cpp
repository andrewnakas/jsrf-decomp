struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;

    void func_0008D1E0();
    void func_000A1FC0();
    void func_000A23D0();
    int func_00093720();
};

// Runs func_0008D1E0, func_000A23D0 and func_000A1FC0, sets the field at 0x118; returns 0.
int Object_000A1C50::func_00093720()
{
    func_0008D1E0();
    func_000A23D0();
    func_000A1FC0();
    value_118 = 1;
    return 0;
}
