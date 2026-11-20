struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void func_00080230(int *angles);

// The player.
struct Object_000A1C50 {
    char unknown_000[0x9e0];
    float unknown_9e0;
    char unknown_9e4[0x8c];
    int unknown_a70;
    char unknown_a74[0x230];
    Vector3 unknown_ca4;
    char unknown_cb0[0xc];
    int angles[3];
    int previous[3];
    float unknown_cd4;
    char unknown_cd8[4];
    int unknown_cdc;

    void func_00083F50(float *position, int *rotation, float value, int mode);
};

// Stores the value (+0xcd4) and mode (+0xa70), clears +0xcdc, transforms +0xca4 by the position and the x/y/z
// rotation, reads the resulting angles back into +0xcbc (func_00080230) and copies them to +0xcc8; +0x9e0 = 1.
void Object_000A1C50::func_00083F50(float *position, int *rotation, float value, int mode)
{
    unknown_cd4 = value;
    unknown_cdc = 0;
    unknown_a70 = mode;
    func_001BAA00();
    func_001BAAA0(position);
    func_001BB2E0(rotation[0]);
    func_001BB330(rotation[1]);
    func_001BB380(rotation[2]);
    func_001BAB20(&unknown_ca4, 0);
    func_00080230(angles);
    func_001BAA50();
    for (int i = 0; i < 3; i++) {
        previous[i] = angles[i];
    }
    unknown_9e0 = 1.0f;
}
