struct Object_00118CB0 {
    int func_00117F40(int id, unsigned int index);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Forwards to func_00117F40 of object 4; returns 0 when object 4 does not exist.
int func_001186A0(int id, unsigned int index)
{
    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
    if (!object) {
        return 0;
    }
    return object->func_00117F40(id, index);
}
