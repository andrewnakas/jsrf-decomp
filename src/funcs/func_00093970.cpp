struct Entry_002104A0 {
    char unknown_00[0xc];
    int value;
    char unknown_10[0x20];
};

struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

struct Object_000A1C50 {
    char unknown_000[0xc90];
    Data_00093920 *data;

    void func_00092FF0(int value, int kind, int mode, int flag);
    void func_0009E8E0(int first, int second);
    Entry_002104A0 *func_000A0120(int index);
    float func_000A0280(int index);
    int func_00093970();
};

// Entry 0xa4 of the table of func_000A0120: func_0009E8E0 with its value at 0xc and func_000A0280 of that value
// (as an integer), then func_00092FF0(data->value, 0, 1, 0); returns 0.
int Object_000A1C50::func_00093970()
{
    Entry_002104A0 *entry = func_000A0120(0xa4);
    func_0009E8E0(entry->value, (int)func_000A0280(entry->value));
    func_00092FF0(data->value, 0, 1, 0);
    return 0;
}
