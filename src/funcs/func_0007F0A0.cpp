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

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *a, const Vector3 *b);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);

// The player.
struct Object_000A1C50 {
    int func_0007F0A0(const Plane_0007F030 *plane, const Vector3 *points, unsigned int count);
};

// 1 when none of the points lies in front of the face (the offset from the face's point, dotted with its normal, is
// at most 0.01), otherwise 0.
int Object_000A1C50::func_0007F0A0(const Plane_0007F030 *plane, const Vector3 *points, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++) {
        Vector3 offset;
        func_0014C4C0(&offset, &points[i], &plane->point);
        if (func_0014C800(&plane->normal, &offset) > 0.01f)
            return 0;
    }
    return 1;
}
