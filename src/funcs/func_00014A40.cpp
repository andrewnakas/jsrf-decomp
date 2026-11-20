struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000851A0 {
    void func_000851A0(const Vector3 *position);
};

struct Object_00014A80 {
    char unknown_00[0xc];
    Vector3 position;

    void func_00014A40(const Vector3 *position);
};

// Stores a copy of a vector at +0xc and passes it on to func_000851A0 of object 0x50, when it exists.
void Object_00014A80::func_00014A40(const Vector3 *position)
{
    this->position = *position;
    Object_000851A0 *object = (Object_000851A0 *)data_0022FCE0->func_000128C0(0x50);
    if (object) {
        object->func_000851A0(position);
    }
}
