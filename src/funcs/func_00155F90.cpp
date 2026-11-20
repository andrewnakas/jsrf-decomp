struct Stats {
    char unknown_00[8];
    unsigned int primitives;
    unsigned int draws;
};

extern Stats *data_002650EC;
// The current index data, which func_0018E090 sets.
extern unsigned short *data_0019DED4;
void __stdcall func_0018E090(void *indices, unsigned long baseVertex);
void __stdcall func_001993A0(int type, unsigned int count, const unsigned short *indices);

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_00155F90();  // slot 22

    char unknown_04[4];
    void *indices;
    char unknown_0C[0xC];
    unsigned int stripLength;
};

// Draws the object's triangle strip (type 6) from its own indices and counts its triangles in the device's statistics.
long __stdcall Object_001E10E8::func_00155F90()
{
    unsigned int count = stripLength - 2;
    data_002650EC->primitives += count;
    data_002650EC->draws++;
    func_0018E090(indices, 0);
    func_001993A0(6, count + 2, data_0019DED4);
    return 0;
}
