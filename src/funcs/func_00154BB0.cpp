// What func_0018D660 fills in (D3DRASTER_STATUS: InVBlank, ScanLine), kept 8-byte aligned.
union Status {
    struct {
        unsigned long first;
        unsigned long second;
    };
    __int64 align;
};

// Reads the raster status (Direct3D 8's GetRasterStatus).
long __stdcall func_0018D660(Status *status);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall func_00154BB0(unsigned long mode);  // slot 12
};

// Slot 12: waits while the first raster status word equals mode; for mode 2, waits until the first word and then
// the second are non-zero.
void __stdcall Object_001E0F00::func_00154BB0(unsigned long mode)
{
    Status status;
    if (mode != 2) {
        do
            func_0018D660(&status);
        while (status.first == mode);
    } else {
        do
            func_0018D660(&status);
        while (!status.first);
        do
            func_0018D660(&status);
        while (!status.second);
    }
}
