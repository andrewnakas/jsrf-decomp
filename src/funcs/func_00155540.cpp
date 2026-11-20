int __stdcall func_0014A85B(void *handle);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual void __stdcall func_00155540(void *handle);  // slot 4
};

// Closes the handle unless it is null or -1.
void __stdcall Object_001E0F00::func_00155540(void *handle)
{
    if (handle != 0 && handle != (void *)-1)
        func_0014A85B(handle);
}
