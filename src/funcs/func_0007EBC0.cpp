struct Vector3 {
    float x;
    float y;
    float z;
};

int func_0014C7D0(float first, float second);

struct Object_0007EBC0 {
    int func_0007EBC0(const Vector3 *vector);
};

// The angle func_0014C7D0 gives for (-z, y), negated.
int Object_0007EBC0::func_0007EBC0(const Vector3 *vector)
{
    return -func_0014C7D0(-vector->z, vector->y);
}
