// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual float __stdcall func_00154110(float value);  // slot 35

    char unknown_04[0x50];
    float scale;
};

float __stdcall Object_001E0F00::func_00154110(float value)
{
    return 1.0f / (value * scale);
}
