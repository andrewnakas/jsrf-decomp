int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_000265A0 {
    char unknown_0000[0x1900];
    void *buffer;

    void func_00026520(int argument);
};

// Handler 31 of the table at 0x1EC288: releases the memory at +0x1900 (func_00145A5D with 0x8000), if any.
void Object_000265A0::func_00026520(int)
{
    if (buffer) {
        func_00145A5D(buffer, 0, 0x8000);
        buffer = 0;
    }
}
