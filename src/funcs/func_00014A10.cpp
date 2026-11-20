struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00014A80 {
    char unknown_00[8];
    int type;
    Vector3 position;

    int func_00014A10(Vector3 *position);
};

// Unless the type is 2, copies the vector at +0xc out and returns 1; for type 2 returns 0.
int Object_00014A80::func_00014A10(Vector3 *position)
{
    if (type == 2) {
        return 0;
    }
    *position = this->position;
    return 1;
}
