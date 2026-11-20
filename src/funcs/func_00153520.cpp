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

// Everything kind -1 sets: the two colours, the position (point lights) or direction, the range and the scale
// of the attenuation.
struct LightValues {
    unsigned long diffuse;
    unsigned long specular;
    Vector3 vector;
    float range;
    float scale;
};

extern Entry *data_00264E70;

// ARGB to four floats (SSE).
void __fastcall func_00156120(float *rgba, unsigned long color);
// Direct3D 8's SetLight (index, light).
long __stdcall func_0018DC00(unsigned long index, const Light_68 *light);
// The reciprocal (SSE).
float func_00186A90(float value);

// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 {
    virtual long __stdcall func_00153520(unsigned long index, unsigned long kind, unsigned long value);  // slot 5
};

// The quadratic attenuation that makes the light fall to the scale's share at its range.
static inline float Attenuation(float range, float scale)
{
    return func_00186A90(range * range * scale);
}

// Slot 5: changes a part of light index (colours 1, position and direction 2 or 5, range 3, attenuation 4, all
// of them -1) and sets the light again as light index + 1.
long __stdcall Object_001E12F8::func_00153520(unsigned long index, unsigned long kind, unsigned long value)
{
    Light_68 *light = &data_00264E70[index].light;
    switch (kind) {
    case 1: {
        const unsigned long *colors = (const unsigned long *)value;
        func_00156120(light->diffuse, colors[0]);
        func_00156120(light->specular, colors[1]);
        break;
    }
    case 2:
    case 5: {
        const Vector3 *vector = (const Vector3 *)value;
        light->position.x = vector->x;
        light->position.y = vector->y;
        light->position.z = vector->z;
        light->direction.x = vector->x;
        light->direction.y = vector->y;
        light->direction.z = vector->z;
        break;
    }
    case 3:
        light->range = *(float *)&value;
        break;
    case 4:
        light->attenuation2 = Attenuation(light->range, *(float *)&value);
        break;
    case (unsigned long)-1: {
        const LightValues *values = (const LightValues *)value;
        func_00156120(light->diffuse, values->diffuse);
        func_00156120(light->specular, values->specular);
        if (light->type == 1) {
            light->position.x = values->vector.x;
            light->position.y = values->vector.y;
            light->position.z = values->vector.z;
        } else {
            light->direction.x = values->vector.x;
            light->direction.y = values->vector.y;
            light->direction.z = values->vector.z;
        }
        light->range = values->range;
        light->attenuation2 = Attenuation(values->range, values->scale);
        break;
    }
    }
    return func_0018DC00(index + 1, light);
}
