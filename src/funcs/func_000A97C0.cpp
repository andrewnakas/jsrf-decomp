struct Vector3 {
    float x;
    float y;
    float z;
};

// One entry of the array at 0x44 (0x1cc bytes).
struct Entry_000A9760 {
    char unknown_00[0xd0];
    Vector3 scale;
    char unknown_dc[0xf0];
};

struct Object_000A9760 {
    char unknown_00[0x44];
    Entry_000A9760 *entries;

    void func_000A97C0(int index, int which, Vector3 *scale);
};

// The entry's vector at 0xd0 becomes the given one times 0.8, 0.6 and 0.8. The second argument is not read (the
// caller, func_000AFA90, passes 0).
void Object_000A9760::func_000A97C0(int index, int which, Vector3 *scale)
{
    entries[index].scale.x = scale->x * 0.8f;
    entries[index].scale.y = scale->y * 0.6f;
    entries[index].scale.z = scale->z * 0.8f;
}
