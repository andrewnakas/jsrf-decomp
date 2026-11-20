struct Object_000A1C50 {
    void func_0007FD20();
    int func_00091380(int *first, int *second);
    void func_0009B3B0();
};

// Calls func_00091380 and drops what it reports, then runs func_0007FD20.
void Object_000A1C50::func_0009B3B0()
{
    int first;
    int second;
    func_00091380(&first, &second);
    func_0007FD20();
}
