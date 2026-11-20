extern "C" void *memset(void *destination, int value, unsigned int size);
extern unsigned long data_0019DED8;
extern unsigned long data_0019E0E0[];
// Laid out like Direct3D 8's D3DLIGHT8.
struct Light_68 {
    unsigned long type;
    float diffuse[4];
    float specular[4];
    float ambient[4];
    float position[3];
    float direction[3];
    float range;
    float falloff;
    float attenuation0;
    float attenuation1;
    float attenuation2;
    float theta;
    float phi;
};

// Light 0. The device keeps colours after it, up to 0x264D48.
extern Light_68 data_00264CA0;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    void func_0014FD70();
};

// Marks flags 0x1200 dirty and clears entry 92 of the render-state table and light 0 and the colours kept after it.
void Object_001E0F00::func_0014FD70()
{
    data_0019DED8 |= 0x1200;
    data_0019E0E0[92] = 0;
    memset(&data_00264CA0, 0, 0xA8);  // light 0 and the colours after it
}
