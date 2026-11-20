struct Stats {
    char unknown_00[8];
    unsigned int primitives;
    unsigned int draws;
};

extern Stats *data_002650EC;
void __stdcall func_00199300(int type, unsigned int start, unsigned int count);

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_00155B80();  // slot 10

    void *object;
    void *resource;
    unsigned long shader;
    unsigned long extra;
    unsigned int vertexCount;
};

// Draws the object's vertexCount vertices as type 6 (a triangle strip) and counts the primitives in the device's statistics.
long __stdcall Object_001E10E8::func_00155B80()
{
    unsigned int primitiveCount = vertexCount - 2;
    data_002650EC->primitives += primitiveCount;
    data_002650EC->draws++;
    func_00199300(6, 0, primitiveCount + 2);
    return 0;
}
