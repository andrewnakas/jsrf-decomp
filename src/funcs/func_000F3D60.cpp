struct Vector3 {
    float x;
    float y;
    float z;
};

// The child of Node whose table is at 0x1CF058 (constructor func_000F37B0, destructor func_000F38B0): a trail of up
// to 150 points.
struct Object_000F37B0 {
    char unknown_000[0x44];
    Vector3 points[150];
    unsigned int count;
    unsigned int flags;

    void func_000F3D60(const Vector3 *point);
};

// Appends the point while there is room, then clears bit 0 of the flags at 0x750.
void Object_000F37B0::func_000F3D60(const Vector3 *point)
{
    if (count < 150) {
        points[count] = *point;
        count++;
    }
    flags &= ~1;
}
