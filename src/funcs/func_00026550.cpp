int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_000265A0 {
    char unknown_0000[0x1910];
    void *buffer;
    int unknown_1914;
    int unknown_1918;
    int unknown_191c;

    int func_00026550(int value);
};

// Handler 32 of the table at 0x1EC068: releases the memory at +0x1910 (func_00145A5D with 0x8000), if any; keeps `value`
// at +0x1918 and clears +0x1914 and +0x191c. Returns 1.
int Object_000265A0::func_00026550(int value)
{
    if (buffer) {
        func_00145A5D(buffer, 0, 0x8000);
        buffer = 0;
    }
    unknown_1918 = value;
    unknown_1914 = 0;
    unknown_191c = 0;
    return 1;
}
