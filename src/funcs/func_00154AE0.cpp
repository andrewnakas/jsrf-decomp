void __stdcall func_0018DF10(unsigned long first, void *second);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    void func_00154AE0();
};

// Passes null for 0, 1 and 2 to func_0018DF10.
void Object_001E0F00::func_00154AE0()
{
    func_0018DF10(0, 0);
    func_0018DF10(1, 0);
    func_0018DF10(2, 0);
}
