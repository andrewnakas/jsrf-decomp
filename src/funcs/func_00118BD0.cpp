struct Vector3;

struct Object_00118CB0 {
    int func_00118A60(int sound, Vector3 *position);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Forwards to func_00118A60 of object 4; returns 0 when object 4 does not exist.
int func_00118BD0(int sound, Vector3 *position)
{
    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
    if (!object) {
        return 0;
    }
    return object->func_00118A60(sound, position);
}
