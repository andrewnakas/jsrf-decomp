// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001540D0(float value);  // slot 33
    long func_00153EC0();

    char unknown_04[0x48];
    float value_4c;
};

long __stdcall Object_001E0F00::func_001540D0(float value)
{
    value_4c = value;
    return func_00153EC0();
}
