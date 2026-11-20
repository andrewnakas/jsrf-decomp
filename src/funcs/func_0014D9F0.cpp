extern unsigned long data_00264C18;
extern unsigned long data_00264C1C;
void __stdcall func_00190490(unsigned long value);

// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0

    char unknown_04[0x64];
    unsigned int stride;
};

extern Object_001E0F00 *data_002650D8;

// A class whose table is at 0x1E1220 (6 slots).
struct Object_001E1220 {
    virtual long __stdcall func_0014D9F0();  // slot 3

    unsigned long shader;
    char unknown_08[4];
    unsigned int stride;
};

// Makes the object's shader and stride the device's current ones.
long __stdcall Object_001E1220::func_0014D9F0()
{
    data_002650D8->stride = stride;
    data_00264C18 = shader;
    data_00264C1C = shader;
    func_00190490(shader);
    return 0;
}
