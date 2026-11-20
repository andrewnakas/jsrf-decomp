struct Game {
    void *func_000128C0(int id);
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000FEC10 {
    void func_000FF090(int value, const Vector3 *position);
};

extern Game *data_0022FCE0;

// Passes the value and the position on to func_000FF090 of object 0x1163, when it exists.
void func_000FEC30(int value, const Vector3 *position)
{
    Object_000FEC10 *object = (Object_000FEC10 *)data_0022FCE0->func_000128C0(0x1163);
    if (object) {
        object->func_000FF090(value, position);
    }
}
