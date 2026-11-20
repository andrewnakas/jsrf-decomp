struct Vector3 {
    float x;
    float y;
    float z;
};

struct Segment_0014B910;

void func_0014B910(Segment_0014B910 *segment, const Vector3 *start, const Vector3 *end);

struct Object_00065730 {
    void func_000657E0(Segment_0014B910 *segment, const Vector3 *start, const Vector3 *end);
};

// Sets a segment up from two points (func_0014B910); called on the lists at 0x1FB804 and 0x1FB8E8.
void Object_00065730::func_000657E0(Segment_0014B910 *segment, const Vector3 *start, const Vector3 *end)
{
    func_0014B910(segment, start, end);
}
