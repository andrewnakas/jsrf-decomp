struct Vector3 {
    float x;
    float y;
    float z;
};

// The 0x18-byte points func_0008FE10 hands over: the second vector is the one read here.
struct Point_0007EF10 {
    Vector3 unknown_00;
    Vector3 position;
};

struct Object_000A1C50 {
    void func_0007EF10(Vector3 *out, Point_0007EF10 *points, int index, int count);
};

// The position of point `index`, clamped to the first and last of `count` points (the player is not used).
void Object_000A1C50::func_0007EF10(Vector3 *out, Point_0007EF10 *points, int index, int count)
{
    if (index < 0)
        *out = points[0].position;
    else if (index >= count)
        *out = points[count - 1].position;
    else
        *out = points[index].position;
}
