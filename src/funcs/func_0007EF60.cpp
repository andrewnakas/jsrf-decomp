struct Vector3 {
    float x;
    float y;
    float z;
};

int func_0014C7D0(float first, float second);

struct Object_0007EF60 {
    int func_0007EF60(const Vector3 *vector);
};

// The angle func_0014C7D0 gives for (x, z).
int Object_0007EF60::func_0007EF60(const Vector3 *vector)
{
    return func_0014C7D0(vector->x, vector->z);
}
