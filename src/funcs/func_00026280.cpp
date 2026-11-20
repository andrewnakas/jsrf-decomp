int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_000265A0 {
    char unknown_0000[0x18fc];
    void *buffer;

    void func_00026280(int argument);
};

// Handler 30 of the table at 0x1EC288: releases the memory at +0x18fc (func_00145A5D with 0x8000), if any.
void Object_000265A0::func_00026280(int)
{
    if (buffer) {
        func_00145A5D(buffer, 0, 0x8000);
        buffer = 0;
    }
}
