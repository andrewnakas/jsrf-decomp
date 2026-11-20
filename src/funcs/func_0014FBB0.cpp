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

extern Light_68 data_00264CA0;
extern float data_00264D28[3];
void __fastcall func_00156120(float *rgba, unsigned long color);
void __fastcall func_001869E0(float *rgb, unsigned long color);
long __stdcall func_0018DC00(unsigned long index, const Light_68 *light);
long __stdcall func_0018DDE0(void *first, unsigned long second);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014FBB0(unsigned long color);  // slot 21
};

// Makes the colour the diffuse and specular colour of light 0 (kept at 0x264CA0), keeps the diffuse colour at
// 0x264D28 and switches lighting on when the colour is not 0.
long __stdcall Object_001E0F00::func_0014FBB0(unsigned long color)
{
    func_00156120(data_00264CA0.diffuse, color);
    func_001869E0(data_00264CA0.specular, color);
    data_00264D28[0] = data_00264CA0.diffuse[0];
    data_00264D28[1] = data_00264CA0.diffuse[1];
    data_00264D28[2] = data_00264CA0.diffuse[2];
    func_0018DC00(0, &data_00264CA0);
    return func_0018DDE0(0, color != 0);
}
