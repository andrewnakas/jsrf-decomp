struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Entry_0003E720;

struct Object_0003E750 {
    Entry_0003E720 *func_0003E720(int id);
    void func_0003F3D0(int id);
    void func_0003F410(int id, int value);
    int func_0003F450(int id);
    void func_0003F490(int id, const Vector3 *point);
};

extern Object_0003E750 data_002314B0;

// The player.
struct Object_000A1C50 {
    char unknown_0000[0xca4];
    Vector3 position;
    char unknown_0cb0[0xc];
    int angles[3];
    char unknown_0cc8[0x374];
    int unknown_103c;
    int entry;
    void func_00089D10();
};

// With +0x103c set and an entry +0x1040 in object 0x2314B0: switches the entry on (func_0003F410 with 1) unless
// func_0003F450 says it is, then hands it the point 25 above the player, turned by the player's angles (half a turn
// about y), after func_0003F3D0.
void Object_000A1C50::func_00089D10()
{
    if (unknown_103c && data_002314B0.func_0003E720(entry)) {
        if (!data_002314B0.func_0003F450(entry)) {
            data_002314B0.func_0003F410(entry, 1);
        }
        Vector3 offset = {0.0f, 25.0f, 0.0f};
        func_001BAA00();
        func_001BAAA0(&position.x);
        func_001BB2E0(angles[0]);
        func_001BB380(angles[2]);
        func_001BB330(angles[1] + 0x8000);
        data_002314B0.func_0003F3D0(entry);
        Vector3 point;
        func_001BAB20(&point, &offset);
        func_001BAA50();
        data_002314B0.func_0003F490(entry, &point);
    }
}
