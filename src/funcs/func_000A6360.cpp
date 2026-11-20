struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000A6360 {
    char unknown_000[0x5c];
    Vector3 position;
    char unknown_068[0x84c];
    int state_8b4;

    void func_000A6360(Vector3 *position);
};

// Sets the field at 0x8b4 to 3 and takes the position at 0x5c from the argument.
void Object_000A6360::func_000A6360(Vector3 *position)
{
    state_8b4 = 3;
    this->position = *position;
}
