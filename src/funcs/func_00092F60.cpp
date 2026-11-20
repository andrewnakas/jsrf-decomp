// Entries of 0x98 bytes.
struct Data_00093920 {
    char unknown_00[0x18];
    float value_18;
    char unknown_1c[8];
    int value;
    char unknown_28[0x70];
};

struct Object_000A1C50 {
    char unknown_000[0xc90];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float value_cd4;
    char unknown_cd8[0x188];
    int value_e60;
    char unknown_e64[0x304];
    int index;

    int func_00092F60(int unused1, int unused2);
};

// A two-argument handler (entry 9 of the table at 0x215200) that uses neither: clears the field at 0xe60 and
// takes the value at 0x18 of the entry after `index` (0x1168) in the 0x98-byte entries at 0xc90; returns 0.
int Object_000A1C50::func_00092F60(int, int)
{
    value_e60 = 0;
    value_cd4 = data[index + 1].value_18;
    return 0;
}
