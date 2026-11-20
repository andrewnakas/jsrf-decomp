int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

extern Object_0006E130 data_00252790;

struct Object_000265A0 {
    char unknown_0000[0x17a0];
    int sounds[5];
    int unknown_17b4;
    char unknown_17b8[0x24];
    void *buffer;

    void func_00027C70(int argument);
};

// Handler 21 of the table at 0x1EC288: releases the memory at +0x17dc (func_00145A5D with 0x8000), hands each of the
// five ids at +0x17a0 to func_0006E7B0 of 0x252790 and clears it, then clears +0x17b4.
void Object_000265A0::func_00027C70(int)
{
    if (buffer) {
        func_00145A5D(buffer, 0, 0x8000);
        buffer = 0;
    }
    for (unsigned int i = 0; i < 5; i++) {
        if (sounds[i]) {
            data_00252790.func_0006E7B0(sounds[i]);
            sounds[i] = 0;
        }
    }
    unknown_17b4 = 0;
}
