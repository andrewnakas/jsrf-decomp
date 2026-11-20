struct Vector3 {
    float x;
    float y;
    float z;
};

// The owner at 0x4 of the Object_000CC600 family.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x7c];
    float *radius;

    int func_000C5E50(Vector3 *point);
};

// Kind 4's test (data_00216214): true when the point lies within the radius (through the pointer at 0xcc) of the
// position at 0x44, on x and z.
int Object_000C5B50::func_000C5E50(Vector3 *point)
{
    float *reach = radius;
    float dx = point->x - position.x;
    float dz = point->z - position.z;
    if (dz * dz + dx * dx > *reach * *reach)
        return 0;
    return 1;
}
