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

struct Mark_00065ED0 {
    int unknown_00[2];
    Vector3 position;
    Segment_0014B910 segment;
};

struct Object_00039A10 {
    void func_00065ED0(Mark_00065ED0 *mark, const Vector3 *from, const Vector3 *to);
};

// Puts a mark at a point and sets its segment up from where it came from (func_0014B910).
void Object_00039A10::func_00065ED0(Mark_00065ED0 *mark, const Vector3 *from, const Vector3 *to)
{
    mark->position = *to;
    func_0014B910(&mark->segment, from, to);
}
