extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

// Laid out like Direct3D 8's D3DLIGHT8.
struct Light_68 {
    unsigned long type;
    float diffuse[4];
    float specular[4];
    float ambient[4];
    float position[3];
    Vector3 direction;
    float range;
    float falloff;
    float attenuation0;
    float attenuation1;
    float attenuation2;
    float theta;
    float phi;
};

struct Params;

// Light 0, its direction and the half-way direction with (0, 0, 1), its diffuse colour and a second colour; the
// whole block (0xA8 bytes from 0x264CA0) is cleared here.
extern Light_68 data_00264CA0;
extern Vector3 data_00264D08;
extern Vector3 data_00264D18;
extern float data_00264D28[3];
extern float data_00264D38[3];

// Direct3D's state: the dirty flags and the render-state table.
extern unsigned long data_0019DED8;
extern unsigned long data_0019E0E0[];

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
long __stdcall func_0018DC00(unsigned long index, const Light_68 *light);
long __stdcall func_0018DDE0(void *first, unsigned long second);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    long func_0014FC20(const Params *params);
};

// Part of the device set-up (0x155380): light 0 becomes a white directional light along (1, -1, 1) normalised,
// with no ambient colour; it is set and switched on, and render state 105 is cleared.
long Object_001E0F00::func_0014FC20(const Params *params)
{
    memset(&data_00264CA0, 0, 0xA8);
    data_00264CA0.type = 3;
    data_00264CA0.diffuse[0] = 1.0f;
    data_00264CA0.diffuse[1] = 1.0f;
    data_00264CA0.diffuse[2] = 1.0f;
    data_00264CA0.specular[0] = 1.0f;
    data_00264CA0.specular[1] = 1.0f;
    data_00264CA0.specular[2] = 1.0f;
    data_00264CA0.ambient[0] = 0.0f;
    data_00264CA0.ambient[1] = 0.0f;
    data_00264CA0.ambient[2] = 0.0f;
    data_00264CA0.attenuation0 = 1.0f;
    data_00264CA0.direction.x = 1.0f;
    data_00264CA0.direction.y = -1.0f;
    data_00264CA0.direction.z = 1.0f;
    func_0014C410(&data_00264CA0.direction, &data_00264CA0.direction);
    data_00264D08.x = data_00264CA0.direction.x;
    data_00264D08.y = data_00264CA0.direction.y;
    data_00264D08.z = data_00264CA0.direction.z;
    data_00264D18.x = data_00264CA0.direction.x;
    data_00264D18.y = data_00264CA0.direction.y;
    data_00264D18.z = data_00264CA0.direction.z + 1.0f;
    func_0014C410(&data_00264D18, &data_00264D18);
    data_00264D28[0] = 1.0f;
    data_00264D28[1] = 1.0f;
    data_00264D28[2] = 1.0f;
    data_00264D38[0] = 0.0f;
    data_00264D38[1] = 0.0f;
    data_00264D38[2] = 0.0f;
    func_0018DC00(0, &data_00264CA0);
    func_0018DDE0(0, 1);
    data_0019DED8 |= 0x1000;
    data_0019E0E0[105] = 0;
    return 0;
}
