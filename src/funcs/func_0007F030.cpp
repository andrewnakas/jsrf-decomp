struct Vector3 {
    float x;
    float y;
    float z;
};

// A face: a point on it, its distance and its normal (+0x10).
struct Plane_0007F030 {
    Vector3 point;
    float distance;
    Vector3 normal;
};

float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
float __fastcall func_0014BD00(Vector3 *out, const Vector3 *point, const Plane_0007F030 *plane);

// The player.
struct Object_000A1C50 {
    int func_0007F030(const Plane_0007F030 *plane, const Plane_0007F030 *other, const Vector3 *points);
};

// 1 when the two faces point the same way (their normals' dot product at least 0.985) and one of the three points
// lies within 0.1 of the first face (func_0014BD00), otherwise 0.
int Object_000A1C50::func_0007F030(const Plane_0007F030 *plane, const Plane_0007F030 *other, const Vector3 *points)
{
    if (func_0014C800(&plane->normal, &other->normal) < 0.985f)
        return 0;
    for (unsigned int i = 0; i < 3; i++) {
        if (func_0014BD00(0, &points[i], plane) < 0.1f)
            return 1;
    }
    return 0;
}
