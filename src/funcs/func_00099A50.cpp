struct Object_000A1C50 {
    char unknown_000[0xa9c];
    int value_a9c;

    int func_0007F880();
    void func_00087630();
    void func_00089C10();
    void func_00089D10();
    void func_0008A4A0(int flag);
    void func_0008A530();
    void func_00098DF0();
    void func_00099A50();
};

// Keeps only bit 0 of func_0007F880 in the field at 0xa9c while it is set, then func_00098DF0, func_00087630,
// func_0008A4A0(0), func_00089C10, func_00089D10 and func_0008A530 in turn.
void Object_000A1C50::func_00099A50()
{
    if (value_a9c) {
        value_a9c = func_0007F880() & 1;
    }
    func_00098DF0();
    func_00087630();
    func_0008A4A0(0);
    func_00089C10();
    func_00089D10();
    func_0008A530();
}
