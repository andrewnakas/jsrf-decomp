struct Stats {
    char unknown_00[8];
    unsigned int primitives;
    unsigned int draws;
};

extern Stats *data_002650EC;
void __stdcall func_00199300(int type, unsigned int start, unsigned int count);

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_00155C00(unsigned int count);  // slot 13
};

// Draws count primitives of type 6 (a triangle strip) from the current stream and counts them in the device's statistics.
long __stdcall Object_001E10E8::func_00155C00(unsigned int count)
{
    data_002650EC->primitives += count;
    data_002650EC->draws++;
    func_00199300(6, 0, count + 2);
    return 0;
}
