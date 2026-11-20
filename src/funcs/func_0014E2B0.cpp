void __stdcall func_00190380(unsigned long shader);

// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    long func_00154F80(void *resource);
};

extern Object_001E0F00 *data_002650D8;

// A class whose table is at 0x1E1220 (6 slots).
struct Object_001E1220 {
    virtual long __stdcall func_0014E200(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014E1F0();  // slot 1
    virtual unsigned long __stdcall func_0014E2B0();  // slot 2
    virtual long __stdcall func_0014D9F0();  // slot 3
    virtual void __stdcall func_0014DA20();  // slot 4
    virtual long __stdcall func_0014DB70(unsigned long first, unsigned long second, unsigned long third);  // slot 5

    ~Object_001E1220() {}

    unsigned long shader;
    char unknown_08[0xC];
    unsigned long references;
};

// Release: the last reference hands the shader to func_00190380, takes this object off the device's list and
// deletes it.
unsigned long __stdcall Object_001E1220::func_0014E2B0()
{
    if (--references == 0) {
        func_00190380(shader);
        data_002650D8->func_00154F80(this);
        delete this;
        return 0;
    }
    return references;
}
