int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

// Releases a block that func_00024390 reserved.
void func_000243B0(void *address)
{
    func_00145A5D(address, 0, 0x8000);
}
