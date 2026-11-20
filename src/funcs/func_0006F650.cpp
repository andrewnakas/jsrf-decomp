int func_00145CCB(char *buffer, const char *format, ...);

struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

struct Sound_001FBCA8 {
    char unknown_00[0xc];
    const char *format;
    char unknown_10[0x24];
    const char *name;
};

extern Sound_001FBCA8 *data_001FBCA8[];

void func_0006F450(int sound, int argument1, int flags, int argument3);

// Formats the name at +0x34 of the current entry of 0x1FBCA8 with `value` + 1 and plays it (func_0006F450 with
// 0x300000 and `value`).
void func_0006F650(int value)
{
    char name[256];
    func_00145CCB(name, data_001FBCA8[data_001FC724.func_00043700()]->name, value + 1);
    func_0006F450((int)name, -1, 0x300000, value);
}
