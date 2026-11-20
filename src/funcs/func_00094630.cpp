struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

struct Object_000A1C50 {
    char unknown_000[0xc90];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float speed;

    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00094630();
};

// Scales the field at 0xcd4 by 2/3, then func_00092FF0(data->value, 1, 1, 0) like the merged
// func_00093920; returns 0.
int Object_000A1C50::func_00094630()
{
    speed *= 0.6666667f;
    func_00092FF0(data->value, 1, 1, 0);
    return 0;
}
