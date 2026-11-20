struct Vector3 {
    float x;
    float y;
    float z;
};

// The object func_000CF370 and func_000CF4E0 hand two points to.
struct Object_000CFB00 {
    char unknown_00[0x74];
    Vector3 first;
    Vector3 second;

    void func_000CFB00(const Vector3 *from, const Vector3 *to);
};

// Copies the two points into 0x74 and 0x80.
void Object_000CFB00::func_000CFB00(const Vector3 *from, const Vector3 *to)
{
    first = *from;
    second = *to;
}
