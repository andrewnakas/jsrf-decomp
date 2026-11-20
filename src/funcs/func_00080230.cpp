struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB380(int angle);
void func_001BB460();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
int func_0014C7D0(float x, float z);
float func_0014C820(float value);

// The three angles of the current matrix: the up axis gives x (func_0014C7D0 of its -z and y, negated) and z (of its
// -x and its length in the y/z plane); the forward axis turned back by those two (inverted, func_001BB460) gives y.
void func_00080230(int *angles)
{
    Vector3 axisY = {0.0f, 1.0f, 0.0f};
    Vector3 up;
    func_001BAC00(&up, &axisY);
    Vector3 axisZ = {0.0f, 0.0f, 1.0f};
    Vector3 forward;
    func_001BAC00(&forward, &axisZ);
    angles[0] = -func_0014C7D0(-up.z, up.y);
    angles[2] = func_0014C7D0(-up.x, func_0014C820(up.z * up.z + up.y * up.y));
    func_001BAA00();
    func_001BB2E0(angles[0]);
    func_001BB380(angles[2]);
    func_001BB460();
    Vector3 local;
    func_001BAC00(&local, &forward);
    func_001BAA50();
    angles[1] = func_0014C7D0(local.x, local.z);
}
