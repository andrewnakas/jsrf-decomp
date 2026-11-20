struct Color {
    float red;
    float green;
    float blue;
    float alpha;
};

// A material (Direct3D 8's D3DMATERIAL8: diffuse, ambient, specular and emissive colours, power).
struct Material {
    Color diffuse;
    Color ambient;
    Color specular;
    Color emissive;
    float power;
};

// The colours as kind 0x20 returns them: ARGB words for diffuse, specular, ambient and emissive, then the power.
struct MaterialColors {
    unsigned long diffuse;
    unsigned long specular;
    unsigned long ambient;
    unsigned long emissive;
    float power;
};

struct Entry_50 {
    Material material;
    char unknown_44[0xC];
};

// The device's materials (0x50 bytes each).
extern Entry_50 *data_00264D4C;

// The device's non-polymorphic base at +4 (its statistics); the device calls its colour packers through it.
struct Stats {
    unsigned long unknown_00[8];

    unsigned long func_00156050(const float *color);
    unsigned long func_001560C0(const float *color);
};

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 : Stats {
    virtual long __stdcall func_00150D90(int index, unsigned long kind, unsigned long *value);  // slot 111
};

// Slot 111: reads a part of material index: its diffuse (1, ARGB), specular (2), ambient (4) or emissive (8)
// colour (RGB), its power (0x10), all of them as a MaterialColors (0x20) or the whole material (0x100).
// E_INVALIDARG for another kind.
long __stdcall Object_001E0F00::func_00150D90(int index, unsigned long kind, unsigned long *value)
{
    Material *material = &data_00264D4C[index].material;
    switch (kind) {
    case 1:
        *value = func_00156050(&material->diffuse.red);
        break;
    case 2:
        *value = func_001560C0(&material->specular.red);
        break;
    case 4:
        *value = func_001560C0(&material->ambient.red);
        break;
    case 8:
        *value = func_001560C0(&material->emissive.red);
        break;
    case 0x10:
        *value = *(unsigned long *)&material->power;
        break;
    case 0x20: {
        MaterialColors *colors = (MaterialColors *)value;
        colors->diffuse = func_00156050(&material->diffuse.red);
        colors->specular = func_001560C0(&material->specular.red);
        colors->ambient = func_001560C0(&material->ambient.red);
        colors->emissive = func_001560C0(&material->emissive.red);
        colors->power = material->power;
        break;
    }
    case 0x100:
        *(Material *)value = *material;
        break;
    default:
        return 0x80070057;
    }
    return 0;
}
