int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
int func_00118BA0(unsigned int id);

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

extern Object_0006E130 data_00252790;

struct Object_000265A0 {
    char unknown_0000[0x1598];
    int sounds[6];
    char unknown_15b0[8];
    void *buffer;
    int unknown_15bc;
    char unknown_15c0[4];
    int unknown_15c4;

    void func_0002C1D0(int argument);
};

// Handler 17 of the table at 0x1EC288: releases the memory at +0x15b8 (func_00145A5D with 0x8000) and then, with
// +0x15c4 set, runs func_00118BA0 (8) and clears it; with +0x15bc set, hands each of the six ids at +0x1598 to
// func_0006E7B0 of 0x252790, clears +0x15bc and runs func_00118BA0 (8).
void Object_000265A0::func_0002C1D0(int)
{
    if (buffer) {
        func_00145A5D(buffer, 0, 0x8000);
        buffer = 0;
        if (unknown_15c4) {
            func_00118BA0(8);
            unknown_15c4 = 0;
        }
    }
    if (unknown_15bc) {
        for (unsigned int i = 0; i < 6; i++) {
            if (sounds[i])
                data_00252790.func_0006E7B0(sounds[i]);
        }
        unknown_15bc = 0;
        func_00118BA0(8);
    }
}
