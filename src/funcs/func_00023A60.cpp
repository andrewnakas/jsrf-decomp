struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00023A30 {
    char unknown_00[0xe4];
    Vector3 vector;

    void func_00023A60(const Vector3 *vector);
};

// Stores a copy of a vector at +0xe4.
void Object_00023A30::func_00023A60(const Vector3 *vector)
{
    this->vector.x = vector->x;
    this->vector.y = vector->y;
    this->vector.z = vector->z;
}
