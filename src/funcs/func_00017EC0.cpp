struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

struct Sphere_00017EC0 {
    Vector3 center;
    float radius;
};

struct Object_00016200 {
    void func_00017EC0(Sphere_00017EC0 *sphere, const Sphere_00017EC0 *other);
};

// Grows the sphere to hold the other one: unchanged when the other is inside it, the other's copy when it is inside
// the other, otherwise the smallest sphere around both.
void Object_00016200::func_00017EC0(Sphere_00017EC0 *sphere, const Sphere_00017EC0 *other)
{
    float distance = func_0014C530(&sphere->center, &other->center);
    if (distance + other->radius < sphere->radius)
        return;
    if (distance + sphere->radius < other->radius) {
        sphere->center.x = other->center.x;
        sphere->center.y = other->center.y;
        sphere->center.z = other->center.z;
        sphere->radius = other->radius;
        return;
    }
    float radius = (distance + sphere->radius + other->radius) * 0.5f;
    float t = (radius - sphere->radius) / distance;
    sphere->center.x = (other->center.x - sphere->center.x) * t + sphere->center.x;
    sphere->center.y = (other->center.y - sphere->center.y) * t + sphere->center.y;
    sphere->center.z = (other->center.z - sphere->center.z) * t + sphere->center.z;
    sphere->radius = radius;
}
