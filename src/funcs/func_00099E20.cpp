struct Data_00093920 {
    char unknown_00[0x5c];
    float total;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xabc];
    float share;
    char unknown_ac0[0x1d0];
    Data_00093920 *data;
    char unknown_c94[0x48];
    int value_cdc;

    void func_00099E20(float total, int steps, unsigned int count);
};

// The share at 0xabc becomes the total at 0x5c of the data at 0xc90 divided by 1 + 2 + ... + count, and 0xcdc is
// cleared. The first two arguments are not read.
void Object_000A1C50::func_00099E20(float total, int steps, unsigned int count)
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < count; i++) {
        sum += i + 1;
    }
    share = data->total / sum;
    value_cdc = 0;
}
