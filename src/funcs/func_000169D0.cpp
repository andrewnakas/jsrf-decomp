struct Vector3 {
    float x;
    float y;
    float z;
};

// A sphere: centre and radius.
struct Sphere_000169D0 {
    Vector3 centre;
    float radius;
};

int __fastcall func_0014B7A0(float *distance, const Sphere_000169D0 *a, const Sphere_000169D0 *b);
float func_0014C820(float value);

struct Object_00016200 {
    int func_000169D0(Sphere_000169D0 *a, Sphere_000169D0 *b, float *depth);
};

// 1 when the two spheres touch (func_0014B7A0, which also gives the squared distance of their centres), with the
// depth they overlap by (the sum of the radii less the distance, func_0014C820) when `depth` is given; otherwise 0.
// It does not use `this`.
int Object_00016200::func_000169D0(Sphere_000169D0 *a, Sphere_000169D0 *b, float *depth)
{
    float distance;
    if (func_0014B7A0(&distance, a, b)) {
        if (depth)
            *depth = a->radius + b->radius - func_0014C820(distance);
        return 1;
    }
    return 0;
}
