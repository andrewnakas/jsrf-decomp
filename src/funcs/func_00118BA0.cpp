struct Object_00118CB0 {
    int func_001188C0(unsigned int index, int flag);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Calls func_001188C0 of object 4 for an index below 400, with 0; 0 for a larger index or without object 4.
int func_00118BA0(unsigned int index)
{
    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
    if (index >= 400) {
        return 0;
    }
    if (!object) {
        return 0;
    }
    return object->func_001188C0(index, 0);
}
