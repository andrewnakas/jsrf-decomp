void *func_0014CAF0();
void *func_001BB750();

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014CF00();  // slot 1
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void *__stdcall func_00154DC0(int kind);  // slot 8
};

// Kind 0: the device itself (with a reference); 1 and 2: what func_0014CAF0 and func_001BB750 give.
void *__stdcall Object_001E0F00::func_00154DC0(int kind)
{
    switch (kind) {
    case 0:
        func_0014CF00();
        return this;
    case 1:
        return func_0014CAF0();
    case 2:
        return func_001BB750();
    }
    return 0;
}
