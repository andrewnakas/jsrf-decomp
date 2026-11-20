struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00118CB0 {
    int func_001192E0(int group, int index, void *position);
};

struct Object_00070530 {
    void func_00070960(int index);
};

// Passes an index of group 8 to func_001192E0 of object 4, when it exists.
void Object_00070530::func_00070960(int index)
{
    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
    if (object) {
        object->func_001192E0(8, index, 0);
    }
}
