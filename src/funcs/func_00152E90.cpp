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

// Everything kind -1 reads: the two colours, the position, the range and the attenuation's scale.
struct LightValues {
    unsigned long diffuse;
    unsigned long specular;
    Vector3 vector;
    float range;
    float scale;
};

extern Entry *data_00264E70;

// The reciprocal (SSE).
float func_00186A90(float value);

// The object's non-polymorphic base at +4, whose member packs a colour (the device has the same base).
struct Stats {
    unsigned long func_001560C0(const float *color);
};

// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 : Stats {
    virtual long __stdcall func_00152E90(unsigned long index, unsigned long kind, unsigned long *value);  // slot 6
};

// The attenuation's scale back from the quadratic attenuation and the range (as slot 5 computes it).
static inline float Attenuation(float range, float scale)
{
    return func_00186A90(range * range * scale);
}

// Slot 6: reads a part of light index (colours 1, position 2, range 3, attenuation scale 4, direction 5, all of
// them -1 as slot 5 takes them).
long __stdcall Object_001E12F8::func_00152E90(unsigned long index, unsigned long kind, unsigned long *value)
{
    const Light_68 *light = &data_00264E70[index].light;
    switch (kind) {
    case 1:
        value[0] = func_001560C0(light->diffuse);
        value[1] = func_001560C0(light->specular);
        break;
    case 2: {
        Vector3 *vector = (Vector3 *)value;
        vector->x = light->position.x;
        vector->y = light->position.y;
        vector->z = light->position.z;
        break;
    }
    case 3:
        *(float *)value = light->range;
        break;
    case 4:
        *(float *)value = Attenuation(light->range, light->attenuation2);
        break;
    case 5: {
        Vector3 *vector = (Vector3 *)value;
        vector->x = light->direction.x;
        vector->y = light->direction.y;
        vector->z = light->direction.z;
        break;
    }
    case (unsigned long)-1: {
        LightValues *values = (LightValues *)value;
        values->diffuse = func_001560C0(light->diffuse);
        values->specular = func_001560C0(light->specular);
        values->vector.x = light->position.x;
        values->vector.y = light->position.y;
        values->vector.z = light->position.z;
        values->range = light->range;
        values->scale = Attenuation(light->range, light->attenuation2);
        break;
    }
    }
    return 0;
}
