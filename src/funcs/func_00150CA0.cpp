// ARGB to four floats (red, green, blue, alpha) and to three (red, green, blue).
void __fastcall func_00186A30(float *rgba, unsigned long color);
void __fastcall func_001869E0(float *rgb, unsigned long color);

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

// The colours as kind 0x20 passes them: ARGB words for diffuse, specular, ambient and emissive, then the power.
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

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150CA0(int index, unsigned long kind, unsigned long value);  // slot 110
};

// Slot 110: sets a part of material index: its diffuse (1), specular (2), ambient (4) or emissive (8) colour from
// an ARGB word, its power (0x10), all of them from a MaterialColors (0x20) or the whole material (0x100).
// E_INVALIDARG for another kind.
long __stdcall Object_001E0F00::func_00150CA0(int index, unsigned long kind, unsigned long value)
{
    Material *material = &data_00264D4C[index].material;
    switch (kind) {
    case 1:
        func_00186A30(&material->diffuse.red, value);
        break;
    case 2:
        func_001869E0(&material->specular.red, value);
        break;
    case 4:
        func_001869E0(&material->ambient.red, value);
        break;
    case 8:
        func_001869E0(&material->emissive.red, value);
        break;
    case 0x10:
        *(unsigned long *)&material->power = value;
        break;
    case 0x20: {
        const MaterialColors *colors = (const MaterialColors *)value;
        func_00186A30(&material->diffuse.red, colors->diffuse);
        func_001869E0(&material->ambient.red, colors->ambient);
        func_001869E0(&material->specular.red, colors->specular);
        func_001869E0(&material->emissive.red, colors->emissive);
        material->power = colors->power;
        break;
    }
    case 0x100:
        *material = *(const Material *)value;
        break;
    default:
        return 0x80070057;
    }
    return 0;
}
