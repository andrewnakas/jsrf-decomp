int func_00145CCB(char *buffer, const char *format, ...);
void func_0006F450(int sound, int first, int flags, int value);

struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

// Texts by language (func_00043700 of 0x1FC724): a table of names, and the format they are shown with.
extern const char **data_0021BC60[];
extern const char *data_0021C570[];

// Formats name `index` of the current language with that language's format and passes the text with `value` to
// func_0006F450.
void func_0006F6D0(unsigned int index, int value)
{
    char text[0x100];
    func_00145CCB(text, data_0021C570[data_001FC724.func_00043700()],
                  data_0021BC60[data_001FC724.func_00043700()][index]);
    func_0006F450((int)text, -1, 0xb000000, value);
}
