struct Vector3 {
    float x;
    float y;
    float z;
};

// One entry of the array at 0x44 (0x1d0 bytes).
struct Entry_000BCED0 {
    char unknown_00[0xd8];
    Vector3 scale;
    char unknown_e4[0xec];
};

struct Object_000BCED0 {
    char unknown_00[0x44];
    Entry_000BCED0 *entries;

    void func_000BCED0(int index, int which, Vector3 *scale);
};

// The entry's vector at 0xd8 becomes the given one times 0.8, 0.6 and 0.8. The second argument is not read (the
// caller, func_000AFA90, passes 0).
void Object_000BCED0::func_000BCED0(int index, int which, Vector3 *scale)
{
    entries[index].scale.x = scale->x * 0.8f;
    entries[index].scale.y = scale->y * 0.6f;
    entries[index].scale.z = scale->z * 0.8f;
}
