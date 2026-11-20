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

// A light as slot 3 takes it: the two colours, the position (also taken as the direction), the range, the share
// of the light left at the range, and flags (0x100 for a directional light).
struct LightInfo {
    unsigned long diffuse;
    unsigned long specular;
    Vector3 vector;
    float range;
    float scale;
    unsigned long flags;
};

extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

extern Entry *data_00264E70;
extern unsigned int data_00264E74;

// ARGB to four floats (SSE).
void __fastcall func_00156120(float *rgba, unsigned long color);
// Direct3D 8's SetLight (index, light) and LightEnable (index, enable).
long __stdcall func_0018DC00(unsigned long index, const Light_68 *light);
long __stdcall func_0018DDE0(void *first, unsigned long second);
// The reciprocal (SSE).
float func_00186A90(float value);

// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 {
    virtual long __stdcall func_001533D0(unsigned long index, const LightInfo *info, int enable);  // slot 3
};

// The quadratic attenuation that makes the light fall to the scale's share at its range.
static inline float Attenuation(float range, float scale)
{
    return func_00186A90(range * range * scale);
}

// Slot 3: sets light index + 1 up from info (a directional light with constant attenuation, or a point light
// with quadratic attenuation), keeps a copy in entry index of the table at data_00264E70 and switches it on or
// off; an enabled entry remembers its index. E_INVALIDARG for an index past the table or no info; SetLight's
// failure.
long __stdcall Object_001E12F8::func_001533D0(unsigned long index, const LightInfo *info, int enable)
{
    if (index < data_00264E74 && info) {
        Light_68 light;
        memset(&light, 0, sizeof(light));
        if (info->flags & 0x100) {
            light.type = 3;
            light.attenuation0 = 1.0f;
        } else {
            light.type = 1;
            light.attenuation0 = 0.0f;
            light.attenuation1 = 0.0f;
            light.attenuation2 = Attenuation(info->range, info->scale);
        }
        func_00156120(light.diffuse, info->diffuse);
        func_00156120(light.specular, info->specular);
        light.position.x = info->vector.x;
        light.position.y = info->vector.y;
        light.position.z = info->vector.z;
        light.direction.x = info->vector.x;
        light.direction.y = info->vector.y;
        light.direction.z = info->vector.z;
        light.range = info->range;
        light.falloff = 1.0f;
        long result = func_0018DC00(index + 1, &light);
        if (result < 0)
            return result;
        data_00264E70[index].light = light;
        if (func_0018DDE0((void *)(index + 1), enable) >= 0 && enable) {
            data_00264E70[index].enabled = 1;
            data_00264E70[index].index = index;
        }
        return 0;
    }
    return 0x80070057;
}
