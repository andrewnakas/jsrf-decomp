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
    Vector3 position;
    Vector3 direction;
    float range;
    float falloff;
    float attenuation0;
    float attenuation1;
    float attenuation2;
    float theta;
    float phi;
};

// An entry of the 0x70-byte table at data_00264E70: a light after two words.
struct Entry {
    unsigned long enabled;
    unsigned long index;
    Light_68 light;
};

extern Entry *data_00264E70;
extern unsigned int data_00264E74;

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
long __stdcall func_0018DC00(unsigned long index, const Light_68 *light);

// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 {
    virtual long __stdcall func_00153300(const void *iid, void **object);  // slot 0
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual long __stdcall func_00152FE0(unsigned long argument1);  // slot 8
};

// Slot 8: for the light of entry argument1 (or of every entry for -1) whose type is 1, func_001BAB20 on its
// position with its direction and sets it again as light index + 1 (func_0018DC00). E_INVALIDARG for an index past
// the table or a light of another type.
long __stdcall Object_001E12F8::func_00152FE0(unsigned long argument1)
{
    if (argument1 == (unsigned long)-1) {
        for (unsigned int i = 0; i < data_00264E74; i++) {
            Light_68 *light = &data_00264E70[i].light;
            if (light->type == 1) {
                func_001BAB20(&light->position, &light->direction);
                func_0018DC00(i + 1, light);
            }
        }
        return 0;
    }
    if (argument1 < data_00264E74) {
        Light_68 *light = &data_00264E70[argument1].light;
        if (light->type == 1) {
            func_001BAB20(&light->position, &light->direction);
            return func_0018DC00(argument1 + 1, light);
        }
    }
    return 0x80070057;
}
