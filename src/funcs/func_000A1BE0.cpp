struct Object_000A1C50 {
    void func_000873F0();
    void func_00089A60();
    void func_00089C10();
    void func_00089D10();
    void func_0008A4A0(int flag);
    void func_0008A530();
    void func_000A0F10();
    void func_000A1BE0();
};

// A handler of the member-function tables of this class (0x20d838 and 0x20d83c): runs func_000A0F10,
// func_000873F0, func_0008A4A0(1), func_00089C10, func_00089D10, func_0008A530 and func_00089A60 in turn.
void Object_000A1C50::func_000A1BE0()
{
    func_000A0F10();
    func_000873F0();
    func_0008A4A0(1);
    func_00089C10();
    func_00089D10();
    func_0008A530();
    func_00089A60();
}
