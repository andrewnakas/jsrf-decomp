struct Entry_002104A0 {
    char unknown_00[0xc];
    int value;
    char unknown_10[0x20];
};

struct Object_000A1C50 {
    void func_0009E8E0(int first, int second);
    Entry_002104A0 *func_000A0120(int index);
    float func_000A0280(int index);
    int func_000936A0();
};

// Entry 0xa4 of the table of func_000A0120 to func_0009E8E0 with func_000A0280 of its value at 0xc (as an
// integer); returns 0.
int Object_000A1C50::func_000936A0()
{
    Entry_002104A0 *entry = func_000A0120(0xa4);
    func_0009E8E0(entry->value, (int)func_000A0280(entry->value));
    return 0;
}
