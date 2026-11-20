struct Data_00093920 {
    char unknown_00[0x24];
    int value;
    int value_28;
};

// The object at 0x2a0 of the player: its first word.
struct Object_00094780 {
    int value_00;
};

struct Object_000A1C50 {
    char unknown_000[0x2a0];
    Object_00094780 *object_2a0;
    char unknown_2a4[0x9ec];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float speed;
    char unknown_cd8[0x148];
    int value_e20;
    char unknown_e24[0x34];
    int phase;

    unsigned int func_0007FCC0();
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_000940A0(int index, float value);
    int func_00094150(int index, float value);
};

extern int (Object_000A1C50::*data_0020E20C[])();
extern int (Object_000A1C50::*data_0020E23C[])();

// A two-argument handler: phase 3; with the speed at 0xcd4 above 1.3889 returns 0 at once. Otherwise
// func_00092FF0 with the data's value at 0x28 (0x24 when func_0007FCC0 is clear), then the handler the table at
// 0x20e20c (value above 0.6944) or 0x20e23c holds for the index; the first word of the object at 0x2a0 goes to 0xe20.
int Object_000A1C50::func_000940A0(int index, float value)
{
    phase = 3;
    if (speed > 1.3888888f) {
        return 0;
    }
    if (func_0007FCC0()) {
        func_00092FF0(data->value_28, 1, 1, 1);
    } else {
        func_00092FF0(data->value, 1, 1, 1);
    }
    int result;
    if (value > 0.69444442f) {
        result = (this->*data_0020E20C[index])();
    } else {
        result = (this->*data_0020E23C[index])();
    }
    value_e20 = object_2a0->value_00;
    return result;
}
