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
float func_0014BE90(Vector3 *a, Vector3 *b, const Segment_0006F8C0 *first, const Segment_0006F8C0 *second);
int __fastcall func_0014B800(const Segment_0006F8C0 *segment, const Vector3 *point);

struct Object_00016200 {
    int func_00016A30(Sphere_000169D0 *sphere, Capsule_00016A30 *capsule, float *depth);
    int func_00016DA0(Capsule_00016A30 *a, Capsule_00016A30 *b, float *depth);
};

// 1 when the two capsules touch: the nearest points of their axes (func_0014BE90) are no farther than the two
// radii (that distance is the depth) and lie between the ends (func_0014B800); otherwise each end of one capsule is
// tested as a sphere against the other (func_00016A30).
int Object_00016200::func_00016DA0(Capsule_00016A30 *a, Capsule_00016A30 *b, float *depth)
{
    Sphere_000169D0 end;
    Vector3 nearA;
    Vector3 nearB;
    Segment_0006F8C0 first;
    Segment_0006F8C0 second;
    func_0014B910((Segment_0014B910 *)&first, &a->start, &a->end);
    func_0014B910((Segment_0014B910 *)&second, &b->start, &b->end);
    float distance = func_0014BE90(&nearA, &nearB, &first, &second);
    if (distance > a->radius + b->radius)
        return 0;
    if (depth)
        *depth = distance;
    if (func_0014B800(&first, &nearA) && func_0014B800(&second, &nearB))
        return 1;
    end.centre = a->start;
    end.radius = a->radius;
    if (func_00016A30(&end, b, depth))
        return 1;
    end.centre = a->end;
    end.radius = a->radius;
    if (func_00016A30(&end, b, depth))
        return 1;
    end.centre = b->start;
    end.radius = b->radius;
    if (func_00016A30(&end, a, depth))
        return 1;
    end.centre = b->end;
    end.radius = b->radius;
    if (func_00016A30(&end, a, depth))
        return 1;
    return 0;
}
