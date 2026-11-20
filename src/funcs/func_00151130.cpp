extern float data_00264D54[4];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    long func_00151130(void *parameters);
};

// Resets the colour at 0x264D54 to (0, 0, 0, 0.5).
long Object_001E0F00::func_00151130(void *parameters)
{
    data_00264D54[0] = 0.0f;
    data_00264D54[1] = 0.0f;
    data_00264D54[2] = 0.0f;
    data_00264D54[3] = 0.5f;
    return 0;
}
