struct Object_000A1C50 {
    void func_0007FF30();
    void func_000A0870(int index);
};

extern int (Object_000A1C50::*data_00215260[])();

// Runs the handler the table holds for the index, then func_0007FF30.
void Object_000A1C50::func_000A0870(int index)
{
    (this->*data_00215260[index])();
    func_0007FF30();
}
