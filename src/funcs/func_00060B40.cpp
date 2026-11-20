struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000607B0 {
    void func_00060730(int key, Vector3 *value);
};

// Passes a key and a vector to func_00060730 of object 0xe8, when it exists.
void func_00060B40(int key, Vector3 *value)
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_00060730(key, value);
    }
}
