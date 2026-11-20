struct Object_00091380 {
    int func_00091380(int *first, int *second);
};

struct Object_000A1C50 {
    void func_0007FD20();
    void func_0009B3B0();
};

// Calls func_00091380 and drops what it reports, then runs func_0007FD20. The tree declares func_00091380
// under the class Object_00091380 (func_0009B490 calls it the same way), so `this` is passed as one.
void Object_000A1C50::func_0009B3B0()
{
    int first;
    int second;
    ((Object_00091380 *)this)->func_00091380(&first, &second);
    func_0007FD20();
}
