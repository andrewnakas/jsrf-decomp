struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00039A10 {
    void func_00066AB0(Vector3 *out, const Vector3 *in);
};

// Copies a vector.
void Object_00039A10::func_00066AB0(Vector3 *out, const Vector3 *in)
{
    *out = *in;
}
