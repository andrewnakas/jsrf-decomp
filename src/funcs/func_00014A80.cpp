struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00014A80 {
    char unknown_00[0xc];
    Vector3 position;

    void func_00014A80(const Vector3 *position);
};

// Stores a copy of the vector at +0xc.
void Object_00014A80::func_00014A80(const Vector3 *position)
{
    this->position = *position;
}
