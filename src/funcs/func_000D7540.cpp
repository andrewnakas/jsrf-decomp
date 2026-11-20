struct Vector3 {
    float x;
    float y;
    float z;
};

struct Segment_0014B910 {
    char unknown_00[0x30];
};

// A segment: its start, its unit direction and its end.
struct Segment_0006F8C0 {
    Vector3 start;
    float unknown_0c;
    Vector3 direction;
    float unknown_1c;
    Vector3 end;
    float unknown_2c;
};

float __fastcall func_0014C580(const Vector3 *a, const Vector3 *b);
void func_0014B910(Segment_0014B910 *segment, const Vector3 *start, const Vector3 *end);
float __fastcall func_0014B860(Vector3 *closest, const Vector3 *point, const Segment_0006F8C0 *segment);
int __fastcall func_0014B800(const Segment_0006F8C0 *segment, const Vector3 *point);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
float func_0014C7F0(float value);

// The object in data_00257CE4.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

// The limits a behaviour reads (at 0x30): a range at 0x28.
struct Limits_000D6350 {
    char unknown_00[0x28];
    float range;
};

// A point of the path at 0x70.
struct Point_000CD440 {
    Vector3 position;
    char unknown_0c[0xc];
};

// The class whose table is at 0x1CE364.
struct Object_000CD1E0 {
    void *vtable;
    void *owner;
    char unknown_08[0xc];
    Vector3 position;
    Vector3 direction;
    char unknown_2c[4];
    Limits_000D6350 *limits;
    char unknown_34[8];
    unsigned int index;
    char unknown_40[0x2c];
    unsigned int count;
    Point_000CD440 *points;

    int func_000D7540(int flags);
};

// Finds the path point nearest the object at data_00257CE4. Returns 1 when that object is within the range at
// limits+0x28 of the point (squared), or of the segment from it to the point before or after it (when the closest
// point lies on the segment). Otherwise, with `flags` set, takes as the index the end of the segment that runs
// closer to the behaviour's direction. Returns 0 then.
int Object_000CD1E0::func_000D7540(int flags)
{
    Vector3 *target = &data_00257CE4->position;
    unsigned int best = 0;
    float nearest = func_0014C580(&points[0].position, target);
    unsigned int i;
    for (i = 1; i < count; i++) {
        float distance = func_0014C580(&points[i].position, target);
        if (distance < nearest) {
            nearest = distance;
            best = i;
        }
    }
    if (nearest < limits->range * limits->range) {
        return 1;
    }
    unsigned int previous = best > 0 ? i - 1 : count - 1;
    Segment_0006F8C0 segment;
    func_0014B910((Segment_0014B910 *)&segment, &points[best].position, &points[previous].position);
    Vector3 closest;
    if (limits->range > func_0014B860(&closest, target, &segment) && func_0014B800(&segment, &closest)) {
        return 1;
    }
    Vector3 heading;
    float before;
    if (flags) {
        func_0014C410(&heading, &direction);
        before = func_0014C800(&heading, &segment.direction);
    }
    unsigned int next = best < count - 1 ? best + 1 : 0;
    func_0014B910((Segment_0014B910 *)&segment, &points[best].position, &points[next].position);
    if (limits->range > func_0014B860(&closest, target, &segment) && func_0014B800(&segment, &closest)) {
        return 1;
    }
    if (flags) {
        float after = func_0014C800(&heading, &segment.direction);
        if (func_0014C7F0(before) >= func_0014C7F0(after)) {
            index = best;
        } else {
            index = next;
        }
    }
    return 0;
}
