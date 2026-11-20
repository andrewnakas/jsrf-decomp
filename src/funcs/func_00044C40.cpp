struct Vector3 {
    float x;
    float y;
    float z;
};

float func_0014C820(float value);

struct Object_00044AE0 {
    void func_00044C40(Vector3 *vector);
};

// Scales a vector to length 1 (func_0014C820 of the sum of squares); called from func_00046340, ignores `this`.
void Object_00044AE0::func_00044C40(Vector3 *vector)
{
    float scale = 1.0f / func_0014C820(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
    vector->x *= scale;
    vector->y *= scale;
    vector->z *= scale;
}
