/* const: 0x200000 */
int func_00145CCB(char *buffer, const char *format, ...);
void func_0006F450(int sound, int first, int flags, int value);

struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

// The table of texts by language: the format at +0x28.
struct Sound_001FBCA8 {
    char unknown_00[0x28];
    const char *format;
};

extern Sound_001FBCA8 *data_001FBCA8[];

// Formats number `index` + 1 with the format of the current language (func_00043700 of 0x1FC724) and passes the text
// with `index` to func_0006F450.
void func_0006F5B0(int index)
{
    char text[0x100];
    func_00145CCB(text, data_001FBCA8[data_001FC724.func_00043700()]->format, index + 1);
    func_0006F450((int)text, -1, 0x200000, index);
}
