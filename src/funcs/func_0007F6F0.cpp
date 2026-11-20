struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void func_001BB460();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *a, const Vector3 *b);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
float func_0014C7F0(float value);

// The player.
struct Object_000A1C50 {
    char unknown_000[0xcc0];
    int angle_cc0;
    char unknown_cc4[0x10];
    float speed_cd4;

    int func_0007F6F0(Vector3 *from, Vector3 *to, int pitch);
};

// Where `to` lies seen from `from` in the frame of the player's heading (+0xcc0) and the pitch: above the speed
// 1.3889 (+0xcd4, func_0014C7F0 for the size) only ahead (3) or behind (7); otherwise mostly sideways 4 or 5, or
// mostly ahead 6 or behind 2.
int Object_000A1C50::func_0007F6F0(Vector3 *from, Vector3 *to, int pitch)
{
    Vector3 offset;
    func_0014C4C0(&offset, to, from);
    Vector3 axisZ = {0.0f, 0.0f, 1.0f};
    func_001BAA00();
    func_001BB330(angle_cc0);
    func_001BB2E0(pitch);
    Vector3 forward;
    func_001BAC00(&forward, &axisZ);
    func_001BB460();
    Vector3 local;
    func_001BAB20(&local, &offset);
    func_001BAA50();
    if (func_0014C7F0(speed_cd4) > 1.3888888f) {
        if (func_0014C800(&forward, &offset) < 0.0f) {
            return 3;
        }
        return 7;
    }
    if (func_0014C7F0(local.x) > func_0014C7F0(local.z)) {
        if (local.x > 0.0f) {
            return 4;
        }
        return 5;
    }
    return local.z > 0.0f ? 6 : 2;
}
