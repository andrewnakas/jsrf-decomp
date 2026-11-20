struct Motion_0005F060;

// One row of data_0020E910 (0x18 bytes): the motion and the alternative motion (-1 for none).
struct Row_000A0280 {
    int motion;
    int alternative;
    char unknown_08[0x10];
};

extern Row_000A0280 data_0020E910[];

struct Data_00093920 {
    char unknown_00[0x20];
    int limit;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x47c];
    Motion_0005F060 *motions[0x205];
    Data_00093920 *data;
    char unknown_c94[0x304];
    int count;
    char unknown_f9c[0x1d8];
    int value_1174;

    int func_000A01A0(int index);
};

// The motion of row `index` (-1 for a negative index): the alternative one when there is one, unless the count at
// 0xf98 has reached the limit at 0x20 of 0xc90 and 0x1174 is not positive.
int Object_000A1C50::func_000A01A0(int index)
{
    if (index >= 0) {
        if ((count < data->limit || value_1174 > 0) && data_0020E910[index].alternative >= 0) {
            return data_0020E910[index].alternative;
        }
        return data_0020E910[index].motion;
    }
    return -1;
}
