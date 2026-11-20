struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Desc_00060A40;

struct Object_000607B0 {
    int func_00062230(Desc_00060A40 *desc, int parent, Vector3 *direction);
};

// Passes a description, a parent key and a direction to func_00062230 of object 0xe8 and returns its key; 0 when the
// object does not exist.
int func_00062360(Desc_00060A40 *desc, int parent, Vector3 *direction)
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (!object) {
        return 0;
    }
    return object->func_00062230(desc, parent, direction);
}
