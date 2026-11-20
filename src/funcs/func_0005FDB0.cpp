struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);

// The class whose table is at 0x1CB040.
struct Object_00062390 {
    Vector3 *func_0005FDB0(Vector3 *out, float a, float b, float c);
};

// Puts into `out` (and returns it) a unit vector at right angles to (a, b, c): (1, -a/b, 0) when b is not 0, else
// (1, 0, -a/c) when c is not 0, else (b/a times -0, 1, 0) when a is not 0, else 0 (normalized by func_0014C410).
Vector3 *Object_00062390::func_0005FDB0(Vector3 *out, float a, float b, float c)
{
    Vector3 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    if (b != 0.0f) {
        v.x = 1.0f;
        v.y = a / b * -1.0f;
        v.z = 0.0f;
    } else if (c != 0.0f) {
        v.y = 0.0f;
        v.x = 1.0f;
        v.z = a / c * -1.0f;
    } else if (a != 0.0f) {
        v.y = 1.0f;
        v.x = b / a * (-1.0f * 0.0f);
        v.z = 0.0f;
    }
    func_0014C410(&v, &v);
    *out = v;
    return out;
}
