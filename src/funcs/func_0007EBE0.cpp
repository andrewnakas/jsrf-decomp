float func_0014C820(float value);
int func_0014C7D0(float first, float second);

struct Vector3 {
    float x;
    float y;
    float z;
};

// The player object.
struct Object_000A1C50 {
    int func_0007EBE0(const Vector3 *vector);
};

// func_0014C7D0 of the vector's -x and its length in the y/z plane (func_0014C820, the square root). It does not use
// `this`; func_00087200 calls it with the player in ecx.
int Object_000A1C50::func_0007EBE0(const Vector3 *vector)
{
    return func_0014C7D0(-vector->x, func_0014C820(vector->y * vector->y + vector->z * vector->z));
}
