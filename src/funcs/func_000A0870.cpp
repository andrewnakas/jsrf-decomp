struct Object_0007FF30 {
    void func_0007FF30();
    void func_000A0870(int index);
};

extern int (Object_0007FF30::*data_00215260[])();

// Runs the handler the table holds for the index, then func_0007FF30.
void Object_0007FF30::func_000A0870(int index)
{
    (this->*data_00215260[index])();
    func_0007FF30();
}
