struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00111BD0 {
    int func_00111BD0(Vector3 *from, Vector3 *to);
};

int func_0014C7D0(float a, float b);

// The heading from one point to another in the x-z plane, by func_0014C7D0. Never reads this.
int Object_00111BD0::func_00111BD0(Vector3 *from, Vector3 *to)
{
    Vector3 delta;
    delta.x = to->x - from->x;
    delta.z = to->z - from->z;
    return func_0014C7D0(delta.x, delta.z);
}
