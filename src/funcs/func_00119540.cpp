struct Object_00118CB0 {
    int func_001192E0(int group, int index, void *position);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Forwards to func_001192E0 of object 4; returns 0 when object 4 does not exist.
int func_00119540(int group, int index, void *position)
{
    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
    if (!object) {
        return 0;
    }
    return object->func_001192E0(group, index, position);
}
