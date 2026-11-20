int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_000265A0 {
    char unknown_0000[0x1910];
    void *buffer;

    void func_000265A0(int unused);
};

void Object_000265A0::func_000265A0(int)
{
    if (buffer) {
        func_00145A5D(buffer, 0, 0x8000);
        buffer = 0;
    }
}
