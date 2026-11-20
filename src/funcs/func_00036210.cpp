int func_00145CCB(char *buffer, const char *format, ...);

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x1d4];
    unsigned int key;

    void func_00036210(char *path, const char *suffix);
};

// Formats the path of the stage file with `suffix` for the key at +0x1d4 (stage digit from its high half, area digit
// from its low half): "D:\Media\Stage\Stg..." or, for stage 4 or area 6 and up, "A:\Media\Stage\Custom\Stg...".
void Object_000265A0::func_00036210(char *path, const char *suffix)
{
    unsigned int stage = (key >> 16) % 10;
    unsigned int area = (key & 0xffff) % 10;
    if (stage != 4 && area < 6)
        func_00145CCB(path, "D:\\Media\\Stage\\Stg%1d%1d_%s", stage, area, suffix);
    else
        func_00145CCB(path, "A:\\Media\\Stage\\Custom\\Stg%1d%1d_%s", stage, area, suffix);
}
