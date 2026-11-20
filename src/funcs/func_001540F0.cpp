// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual float __stdcall func_001540F0(float value);  // slot 34

    char unknown_04[0x3c];
    float base;
    char unknown_44[0x14];
    float scale;
};

float __stdcall Object_001E0F00::func_001540F0(float value)
{
    return (value - base) * (scale / value);
}
