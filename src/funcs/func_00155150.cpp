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

// Laid out like Direct3D 8's D3DMATERIAL8 (the start of each 0x50-byte material entry).
struct Material_44 {
    float diffuse[4];
    float ambient[4];
    float specular[4];
    float emissive[4];
    float power;
};

struct Entry_50 {
    char unknown_00[0x50];
};

// Direct3D's state: data_002650DC is set while the device is running, data_002650D4 while it holds the push
// buffer.
extern unsigned long data_002650DC;
extern unsigned long data_002650D4;

// Light 0, its direction and the half-way direction with (0, 0, 1), its diffuse colour and the colour of the
// ambient light; the current material entry; the table of data_00264F70 entries at data_00264F68.
extern Light_68 data_00264CA0;
extern Vector3 data_00264D08;
extern Vector3 data_00264D18;
extern float data_00264D28[3];
extern float data_00264D38[3];
extern Entry_50 *data_00264D48;
extern void **data_00264F68;
extern int data_00264F70;

void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __stdcall func_0018CDD0();
long __stdcall func_0018D620(int index, unsigned long type, void **surface);
long __stdcall func_0018DA70(void **surface);
unsigned long __stdcall func_00192950(void *object);
unsigned long __stdcall func_00192990(void *object);

// The device's non-polymorphic base at +4 (its statistics); the device calls its colour packers through it.
struct Stats {
    unsigned long func_001560C0(const float *color);
};

struct Params;
struct Source;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 : Stats {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014CF00();  // slot 1
    virtual unsigned long __stdcall func_0014CF80();  // slot 2
    virtual long __stdcall func_00155A60(unsigned long argument1);  // slot 3
    virtual void __stdcall func_00155540(void *handle);  // slot 4
    virtual long __stdcall func_00155560(unsigned long argument1, unsigned long argument2, unsigned long argument3);  // slot 5
    virtual long __stdcall func_00155380(Params *params);  // slot 6
    virtual long __stdcall func_00154D70(int kind, Source *source);  // slot 7
    virtual void *__stdcall func_00154DC0(int kind);  // slot 8
    virtual long __stdcall func_00155150(unsigned long argument1, unsigned long argument2);  // slot 9

    char unknown_04[0x3C];
    unsigned long value_40;
    unsigned long value_44;
    unsigned long value_48;
    unsigned long unknown_4C;
    unsigned long value_50;
};

// Slot 9: answers a question about Direct3D's state; value is an index or where to copy the answer to.
// 0 is whether Direct3D runs, 1 whether it holds the push buffer (after func_0018CDD0); 2 and 3 a surface (back
// and front buffer, without keeping a second reference); 4 entry value of the table at data_00264F68; 5 to 8
// light 0, the material, the light's direction and the half-way direction (copied to value if given); 9 and 10
// the light's colour and the ambient colour times two as 0xRRGGBB; 11 to 14 device words.
long __stdcall Object_001E0F00::func_00155150(unsigned long kind, unsigned long value)
{
    void *surface = 0;
    switch (kind) {
    case 0:
        return data_002650DC;
    case 1:
        func_0018CDD0();
        return data_002650D4;
    case 2:
        func_0018D620(0, 0, &surface);
        if (func_00192950(surface) >= 2)
            func_00192990(surface);
        return (long)surface;
    case 3:
        if (func_0018DA70(&surface) < 0)
            break;
        if (func_00192950(surface) >= 2)
            func_00192990(surface);
        return (long)surface;
    case 4:
        if (value < (unsigned long)data_00264F70) {
            void *entry = data_00264F68[value];
            func_00192950(entry);
            return (long)entry;
        }
        break;
    case 5:
        if (value)
            *(Light_68 *)value = data_00264CA0;
        return (long)&data_00264CA0;
    case 6:
        if (value)
            *(Material_44 *)value = *(Material_44 *)data_00264D48;
        return (long)data_00264D48;
    case 7:
        if (value)
            *(Vector3 *)value = data_00264D08;
        return (long)&data_00264D08;
    case 8:
        if (value)
            *(Vector3 *)value = data_00264D18;
        return (long)&data_00264D18;
    case 9:
        return func_001560C0(data_00264D28);
    case 10: {
        float color[4];
        func_0014C370((Vector3 *)color, (const Vector3 *)data_00264D38, 2.0f);
        return func_001560C0(color);
    }
    case 11:
        *(unsigned long *)value = value_40;
        break;
    case 12:
        *(unsigned long *)value = value_44;
        return 0;
    case 13:
        *(unsigned long *)value = value_50;
        return 0;
    case 14:
        return value_48;
    }
    return 0;
}
