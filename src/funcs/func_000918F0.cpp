struct Data_00093920 {
    char unknown_00[0x6c];
    float limit;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xabc];
    float step;
    char unknown_ac0[0x1d0];
    Data_00093920 *data;
    char unknown_c94[0x48];
    float value_cdc;

    void func_000918F0();
};

// A handler of the player's tables: takes the step at 0xabc from 0xcdc, down to minus the limit at 0x6c of 0xc90.
void Object_000A1C50::func_000918F0()
{
    float floor;
    value_cdc -= step;
    floor = -data->limit;
    if (value_cdc < floor) {
        value_cdc = floor;
    }
}
