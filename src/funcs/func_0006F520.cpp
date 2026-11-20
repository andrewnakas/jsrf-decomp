int func_00145CCB(char *buffer, const char *format, ...);

struct Object_00047110 {
    int func_00046B60(int kind);
};

extern Object_00047110 data_001F97A8;

struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

struct Sound_001FBCA8 {
    char unknown_00[0xc];
    const char *format;
};

extern Sound_001FBCA8 *data_001FBCA8[];

void func_0006F450(int sound, int argument1, int flags, int argument3);

// Formats the name at +0xc of the current entry of 0x1FBCA8 with func_00046B60 (8) of 0x1F97A8 and plays it
// (func_0006F450 with 0xa8000000 and `value`).
void func_0006F520(int value)
{
    char name[300];
    func_00145CCB(name, data_001FBCA8[data_001FC724.func_00043700()]->format, data_001F97A8.func_00046B60(8));
    func_0006F450((int)name, -1, 0xa8000000, value);
}
