struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void __fastcall func_001BAA50();
void func_001BB5E0();
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
int func_0014C7D0(float x, float z);

// The player.
struct Object_000A1C50 {
    int func_0007ED30(int *angles);
};

// The heading of "down" turned by the angles (x first, then z; func_001BB5E0 between): the angle of its x and z
// (func_0014C7D0), or the y angle when it points straight down.
int Object_000A1C50::func_0007ED30(int *angles)
{
    Vector3 down = {0.0f, -1.0f, 0.0f};
    func_001BAA00();
    func_001BB2E0(angles[0]);
    func_001BB380(angles[2]);
    func_001BB5E0();
    Vector3 turned;
    func_001BAC00(&turned, &down);
    func_001BAA50();
    if (turned.x == 0.0f && turned.z == 0.0f) {
        return angles[1];
    }
    return func_0014C7D0(turned.x, turned.z);
}
