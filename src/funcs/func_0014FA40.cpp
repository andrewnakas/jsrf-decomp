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

// Light 0, its direction and the half-way direction with (0, 0, 1), and its diffuse colour.
extern Light_68 data_00264CA0;
extern Vector3 data_00264D08;
extern Vector3 data_00264D18;
extern float data_00264D28[3];

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
void __fastcall func_00156120(float *rgba, unsigned long color);
void __fastcall func_001869E0(float *rgb, unsigned long color);
long __stdcall func_0018DC00(unsigned long index, const Light_68 *light);
long __stdcall func_0018DDE0(void *first, unsigned long second);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual long __stdcall func_0014FA40(unsigned long argument1, unsigned long argument2);  // slot 19
};

// Slot 19: slots 20 and 21 in one: light 0 gets the normalised direction argument1 points at (kept at 0x264D08,
// the half-way direction at 0x264D18) and the colour argument2 as its diffuse and specular colour (the diffuse one
// also kept at 0x264D28); the light is set and lighting switched on when the colour is not 0.
long __stdcall Object_001E0F00::func_0014FA40(unsigned long argument1, unsigned long argument2)
{
    const Vector3 *direction = (const Vector3 *)argument1;
    data_00264CA0.direction.x = direction->x;
    data_00264CA0.direction.y = direction->y;
    data_00264CA0.direction.z = direction->z;
    func_0014C410(&data_00264CA0.direction, &data_00264CA0.direction);
    data_00264D08.x = data_00264CA0.direction.x;
    data_00264D08.y = data_00264CA0.direction.y;
    data_00264D08.z = data_00264CA0.direction.z;
    data_00264D18.x = data_00264CA0.direction.x;
    data_00264D18.y = data_00264CA0.direction.y;
    data_00264D18.z = data_00264CA0.direction.z + 1.0f;
    func_0014C410(&data_00264D18, &data_00264D18);
    func_00156120(data_00264CA0.diffuse, argument2);
    func_001869E0(data_00264CA0.specular, argument2);
    data_00264D28[0] = data_00264CA0.diffuse[0];
    data_00264D28[1] = data_00264CA0.diffuse[1];
    data_00264D28[2] = data_00264CA0.diffuse[2];
    func_0018DC00(0, &data_00264CA0);
    return func_0018DDE0(0, argument2 != 0);
}
