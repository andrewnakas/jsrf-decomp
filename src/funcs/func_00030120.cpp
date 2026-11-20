int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x1588];
    void **misc;
    void **loading;
    int step;
    void *data;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    void func_0002F6B0(void *data, void **misc);
    void func_0002F7F0(void *data, void **misc);
    int func_00030120();
};

// Entry 11 of the table at 0x1EC0F0: loads "D:\Media\Misc\Misc.bin" into the record at +0x158c and sets it up
// (func_0002F6B0), then loads "D:\Media\Misc\Misc.dat" into +0x1594, applies it (func_0002F7F0) and frees it
// (func_00145A5D); the record moves to +0x1588. Steps at +0x1590; returns 1 once done. (func_0002F6B0 and
// func_0002F7F0 are open; declared `void (void *, void **)` from these calls.)
int Object_000265A0::func_00030120()
{
    switch (step) {
    case 0:
        if (!func_00025DD0("D:\\Media\\Misc\\Misc.bin", loading))
            break;
        step = 1;
    case 1:
        if (!func_00025400())
            break;
        func_0002F6B0(*loading, loading);
        step = 2;
    case 2:
        if (!func_00025DD0("D:\\Media\\Misc\\Misc.dat", &data))
            break;
        step = 3;
    case 3:
        if (!func_00025400())
            break;
        func_0002F7F0(data, loading);
        func_00145A5D(data, 0, 0x8000);
        data = 0;
        misc = loading;
        loading = 0;
        step = 4;
    case 4:
        return 1;
    }
    return 0;
}
