struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000851A0 {
    char unknown_00[0x44];
    int unknown_44;
    Vector3 first;
    Vector3 second;

    void func_000851A0(const Vector3 *position);
};

// Unless the word at +0x44 is set, stores a copy of a vector at +0x48 and at +0x54.
void Object_000851A0::func_000851A0(const Vector3 *position)
{
    if (!unknown_44) {
        first = *position;
        second = *position;
    }
}
