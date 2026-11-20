struct Object_00118CB0 {
    int func_00118330(int first, int second);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Forwards to func_00118330 of object 4; returns -1 when object 4 does not exist.
int func_00118890(int first, int second)
{
    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
    if (object) {
        return object->func_00118330(first, second);
    }
    return -1;
}
