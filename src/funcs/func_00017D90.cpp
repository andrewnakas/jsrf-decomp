struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

struct Sphere_00017EC0 {
    Vector3 center;
    float radius;
};

struct Object_00016200 {
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
};

// The box around the points (func_00017CC0), grown by a radius on every side.
void Object_00016200::func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius)
{
    func_00017CC0(box, points, count);
    box->min.x -= radius;
    box->min.y -= radius;
    box->min.z -= radius;
    box->max.x += radius;
    box->max.y += radius;
    box->max.z += radius;
}
