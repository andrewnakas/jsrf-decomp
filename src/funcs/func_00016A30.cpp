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

// A capsule: the two ends of its axis and its radius.
struct Capsule_00016A30 {
    Vector3 start;
    Vector3 end;
    float radius;
};

struct Segment_0014B910 {
    char unknown_00[0x30];
};

struct Segment_0006F8C0 {
    Vector3 start;
    float unknown_0c;
    Vector3 direction;
    float unknown_1c;
    Vector3 end;
    float unknown_2c;
};

void func_0014B910(Segment_0014B910 *segment, const Vector3 *start, const Vector3 *end);
float __fastcall func_0014B860(Vector3 *closest, const Vector3 *point, const Segment_0006F8C0 *segment);
int __fastcall func_0014B800(const Segment_0006F8C0 *segment, const Vector3 *point);

struct Object_00016200 {
    int func_000169D0(Sphere_000169D0 *a, Sphere_000169D0 *b, float *depth);
    int func_00016A30(Sphere_000169D0 *sphere, Capsule_00016A30 *capsule, float *depth);
};

// 1 when the sphere touches the capsule: its centre's nearest point on the axis (func_0014B860) is no farther than
// the two radii and lies between the ends (func_0014B800), with that distance as the depth; otherwise the sphere
// is tested against a sphere at each end (func_000169D0). The depth is stored when `depth` is given.
int Object_00016200::func_00016A30(Sphere_000169D0 *sphere, Capsule_00016A30 *capsule, float *depth)
{
    Segment_0006F8C0 segment;
    Vector3 closest;
    Sphere_000169D0 end;
    float distance;
    func_0014B910((Segment_0014B910 *)&segment, &capsule->start, &capsule->end);
    distance = func_0014B860(&closest, &sphere->centre, &segment);
    if (!(distance > sphere->radius + capsule->radius)) {
        if (func_0014B800(&segment, &closest)) {
            if (depth)
                *depth = distance;
            return 1;
        }
        end.centre = capsule->start;
        end.radius = capsule->radius;
        if (func_000169D0(sphere, &end, &distance)) {
            if (depth)
                *depth = distance;
            return 1;
        }
        end.centre = capsule->end;
        end.radius = capsule->radius;
        if (func_000169D0(sphere, &end, &distance)) {
            if (depth)
                *depth = distance;
            return 1;
        }
    }
    return 0;
}
