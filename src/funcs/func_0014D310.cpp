void __stdcall func_00199060(int type, unsigned int count, const void *vertices, unsigned int stride);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014D310(const void *vertices, unsigned int count);  // slot 53

    char unknown_04[8];
    unsigned int primitives;
    unsigned int draws;
    char unknown_14[0x54];
    unsigned int stride;
};

// Draws count points from memory (type 1) and counts them.
long __stdcall Object_001E0F00::func_0014D310(const void *vertices, unsigned int count)
{
    unsigned int primitiveCount = count;
    primitives += primitiveCount;
    draws++;
    func_00199060(1, count, vertices, stride);
    return 0;
}
