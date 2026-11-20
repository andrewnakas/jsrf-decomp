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

// Light 0, then its direction and the half-way direction with (0, 0, 1) that the engine keeps after it.
extern Light_68 data_00264CA0;
extern Vector3 data_00264D08;
extern Vector3 data_00264D18;

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
long __stdcall func_0018DC00(unsigned long index, const Light_68 *light);

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
    virtual void __stdcall slot19();
    virtual long __stdcall func_0014FB20(unsigned long argument1);  // slot 20
};

// Slot 20: makes the normalised direction argument1 points at light 0's direction (also kept at 0x264D08), keeps the
// normalised direction plus (0, 0, 1) at 0x264D18 and sets light 0 again (func_0018DC00).
long __stdcall Object_001E0F00::func_0014FB20(unsigned long argument1)
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
    return func_0018DC00(0, &data_00264CA0);
}
