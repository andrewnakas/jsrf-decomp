struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

struct Object_000A1C50 {
    int func_00091EB0();
};

struct Object_00092FF0 {
    char unknown_000[0xc90];
    Data_00093920 *data;

    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093B80();
};

// Runs func_00091EB0, then func_00092FF0(data->value, 1, 1, 1) like its neighbour func_00093920; returns 1.
// The tree declares func_00091EB0 under the class Object_000A1C50, so `this` is passed as one.
int Object_00092FF0::func_00093B80()
{
    ((Object_000A1C50 *)this)->func_00091EB0();
    func_00092FF0(data->value, 1, 1, 1);
    return 1;
}
