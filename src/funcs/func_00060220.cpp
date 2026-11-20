float __fastcall func_0014C620(int angle);
float __fastcall func_0014C640(int angle);
float func_0014C820(float value);

// A rotation as a quaternion: w first.
struct Quaternion_00060220 {
    float w;
    float x;
    float y;
    float z;
};

// The class whose table is at 0x1CB040.
struct Object_00062390 {
    Quaternion_00060220 *func_00060220(Quaternion_00060220 *out, float x, float y, float z, float degrees);
};

// Puts into `out` (and returns it) the rotation by `degrees` about the axis (x, y, z): half the angle in the game's
// units (65536 a turn) through func_0014C640 and func_0014C620, normalized.
Quaternion_00060220 *Object_00062390::func_00060220(Quaternion_00060220 *out, float x, float y, float z,
                                                     float degrees)
{
    float half = degrees * 0.5f;
    int angle = (int)(half * 182.04445f);
    Quaternion_00060220 q;
    q.w = func_0014C640(angle);
    q.x = func_0014C620(angle) * x;
    q.y = func_0014C620(angle) * y;
    q.z = func_0014C620(angle) * z;
    float scale = 1.0f / func_0014C820(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
    q.w *= scale;
    q.x *= scale;
    q.y *= scale;
    q.z *= scale;
    *out = q;
    return out;
}
