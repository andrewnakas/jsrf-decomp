struct Object_000A1C50 {
    void func_000871C0();
    void func_00089D10();
    void func_0008A530();
    void func_00091810();
};

// A handler in the member-function tables of this class (0x20d860): runs func_000871C0, func_0008A530 and
// func_00089D10 in turn.
void Object_000A1C50::func_00091810()
{
    func_000871C0();
    func_0008A530();
    func_00089D10();
}
