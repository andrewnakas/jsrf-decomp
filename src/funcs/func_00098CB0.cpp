struct Object_000A1C50 {
    char unknown_0000[0xb94];
    int value_b94;

    int func_0007F880();
    void func_00089D10();
    void func_0008A4A0(int flag);
    void func_0008A530();
    void func_00098CB0();
};

// func_00089D10, func_0008A4A0(0) and func_0008A530 in turn; then clears the field at 0xb94 when it is set and
// func_0007F880 reports no 0x10 bit.
void Object_000A1C50::func_00098CB0()
{
    func_00089D10();
    func_0008A4A0(0);
    func_0008A530();
    if (value_b94 && !(func_0007F880() & 0x10)) {
        value_b94 = 0;
    }
}
