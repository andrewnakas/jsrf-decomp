struct Source;

struct Description {
    char unknown_00[0x30];
    Source *first;
    Source *second;
};

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual long __stdcall func_00154D70(int kind, Source *source);  // slot 7

    long func_00154E00(const Description *description);
};

// Hands the two sources of the description to slot 7 as kinds 1 and 2; E_INVALIDARG if one is missing.
long Object_001E0F00::func_00154E00(const Description *description)
{
    if (description->first && description->second) {
        long result = func_00154D70(1, description->first);
        if (result < 0)
            return result;
        return func_00154D70(2, description->second);
    }
    return 0x80070057;
}
