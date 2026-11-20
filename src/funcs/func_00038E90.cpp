int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_000265A0 {
    char unknown_0000[0x1874];
    void *buffer;
    int unknown_1878;

    void func_00038E90(int argument);
};

// Handler 24 of the table at 0x1EC288: clears +0x1878 and releases the memory at +0x1874 (func_00145A5D with 0x8000).
void Object_000265A0::func_00038E90(int)
{
    unknown_1878 = 0;
    func_00145A5D(buffer, 0, 0x8000);
}
