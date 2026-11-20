struct Vector3 {
    float x;
    float y;
    float z;
};

struct Segment_0014B910 {
    char unknown_00[0x38];
    int unknown_38;
};

void func_0014B910(Segment_0014B910 *segment, const Vector3 *start, const Vector3 *end);

struct Object_0001DEF0 {
    void func_0006F890(Segment_0014B910 *segment, const Vector3 *start, const Vector3 *end);
};

// Sets a segment up from two points (func_0014B910) and clears its word at +0x38.
void Object_0001DEF0::func_0006F890(Segment_0014B910 *segment, const Vector3 *start, const Vector3 *end)
{
    func_0014B910(segment, start, end);
    segment->unknown_38 = 0;
}
