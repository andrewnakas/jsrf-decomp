void __stdcall func_001991C0(int type, unsigned int count, const void *indices, const void *vertices, unsigned int stride);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014D270(const void *vertices, unsigned int vertexCount, const void *indices, unsigned int count);  // slot 50

    char unknown_04[8];
    unsigned int primitives;
    unsigned int draws;
    char unknown_14[0x54];
    unsigned int stride;
};

// Draws count / 3 indexed triangles from memory (type 5) and counts them.
long __stdcall Object_001E0F00::func_0014D270(const void *vertices, unsigned int vertexCount, const void *indices, unsigned int count)
{
    unsigned int primitiveCount = count / 3;
    primitives += primitiveCount;
    draws++;
    func_001991C0(5, primitiveCount * 3, indices, vertices, stride);
    return 0;
}
