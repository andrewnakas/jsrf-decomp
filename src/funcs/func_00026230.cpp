int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_000265A0 {
    char unknown_0000[0x18f4];
    int unknown_18f4;
    int unknown_18f8;
    void *unknown_18fc;

    int func_00026230(int argument);
};

// Handler 30 of the table at 0x1EC068: clears +0x18f4 and +0x18f8 and releases the block at +0x18fc (VirtualFree,
// MEM_RELEASE), when there is one.
int Object_000265A0::func_00026230(int argument)
{
    unknown_18f4 = 0;
    unknown_18f8 = 0;
    if (unknown_18fc) {
        func_00145A5D(unknown_18fc, 0, 0x8000);
        unknown_18fc = 0;
    }
    return 1;
}
