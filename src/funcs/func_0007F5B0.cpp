struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
float func_0014C7F0(float value);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void func_001BB460();

struct Object_000A1C50 {
    char unknown_000[0xcbc];
    int angles[3];
    char unknown_cc8[0xc];
    float value_cd4;

    int func_0007F5B0(Vector3 *to, Vector3 *from);
};

// Which side of the object the way from `from` to `to` lies on: with the object turned (angles at +0xcbc, +0xcc4,
// +0xcc0), while +0xcd4 is above the limit 3 or 7 by the sign against the turned up direction; otherwise 4 or 5 by
// the turned x when it is the larger across, else 6 or 2 by the turned z.
int Object_000A1C50::func_0007F5B0(Vector3 *to, Vector3 *from)
{
    Vector3 delta;
    func_0014C4C0(&delta, from, to);
    Vector3 up;
    up.x = 0.0f;
    up.y = 0.0f;
    up.z = 1.0f;
    func_001BAA00();
    func_001BB2E0(angles[0]);
    func_001BB380(angles[2]);
    func_001BB330(angles[1]);
    Vector3 turned;
    func_001BAC00(&turned, &up);
    func_001BB460();
    Vector3 local;
    func_001BAB20(&local, &delta);
    func_001BAA50();
    if (func_0014C7F0(value_cd4) > 1.3888888f) {
        if (func_0014C800(&turned, &delta) < 0.0f) {
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
    if (local.z > 0.0f) {
        return 6;
    }
    return 2;
}
