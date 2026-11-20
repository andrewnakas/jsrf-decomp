int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_000265A0 {
    char unknown_0000[0x1900];
    void *buffer;
    int unknown_1904;
    int unknown_1908;
    int unknown_190c;

    int func_000264D0(int value);
};

// Handler 31 of the table at 0x1EC068: releases the memory at +0x1900 (func_00145A5D with 0x8000), if any; keeps `value`
// at +0x1908 and clears +0x1904 and +0x190c. Returns 1.
int Object_000265A0::func_000264D0(int value)
{
    if (buffer) {
        func_00145A5D(buffer, 0, 0x8000);
        buffer = 0;
    }
    unknown_1908 = value;
    unknown_1904 = 0;
    unknown_190c = 0;
    return 1;
}
