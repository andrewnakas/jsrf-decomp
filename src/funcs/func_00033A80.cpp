int func_00145CCB(char *buffer, const char *format, ...);
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

// Object 7 (whose handler tables are at 0x1EC068, 0x1EC178, 0x1EC200 and 0x1EC288): 0x25310 runs entry +0x48 of its
// member-pointer table at 0x1EC0F0 while +0x44 is 1.
struct Object_000265A0 {
    char unknown_0000[0x1804];
    int loaded;
    int step;
    void *data;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    void func_00033920(void *data);
    int func_00033A80();
};

// Entry 23 of the table at 0x1EC0F0: unless already loaded, step 0 starts loading A:\Media\Progress\Progress.dat into
// +0x180c (func_00025DD0), step 1 waits for func_00025400, hands the data to func_00033920 and frees it; then marks
// +0x1804 loaded and returns 1. 0 while waiting or when the load fails.
int Object_000265A0::func_00033A80()
{
    char path[256];
    switch (step) {
    case 0:
        if (loaded)
            return 1;
        func_00145CCB(path, "A:\\Media\\Progress\\Progress.dat");
        if (!func_00025DD0(path, &data))
            return 0;
        step = 1;
    case 1:
        if (!func_00025400())
            return 0;
        func_00033920(data);
        func_00145A5D(data, 0, 0x8000);
        data = 0;
        step = 2;
    case 2:
        loaded = 1;
        return 1;
    default:
        return 0;
    }
}
