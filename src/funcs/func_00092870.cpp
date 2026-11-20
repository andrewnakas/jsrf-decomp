struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The object at data_001EB938.
struct Object_00014A80 {
    void func_00014CE0(int id, int index, void *position, Vector3 *up, void *target, int kind);
};

extern Object_00014A80 data_001EB938;

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x13c];
    char target[0xb60];
    int id;
    char unknown_ca0[0x1c];
    int angles[3];
    char unknown_cc8[0xa8];
    char position[0x244];
    int value_fb4;

    void func_00092870();
};

// When 0xfb4 is 10: turns the z axis by the player's angles at 0xcbc (x, z, y), hands it with the id at 0xc9c and the
// points at 0xd70 and 0x13c to func_00014CE0 of data_001EB938 (kind 3), and sets 0xfb4 to -1.
void Object_000A1C50::func_00092870()
{
    Vector3 axis;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    if (value_fb4 == 10) {
        func_001BAA00();
        func_001BB2E0(angles[0]);
        func_001BB380(angles[2]);
        func_001BB330(angles[1]);
        Vector3 up;
        func_001BAC00(&up, &axis);
        func_001BAA50();
        data_001EB938.func_00014CE0(id, -1, position, &up, target, 3);
        value_fb4 = -1;
    }
}
