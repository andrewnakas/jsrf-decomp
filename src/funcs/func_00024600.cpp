struct Game {
    void *func_000128C0(int id);
};

struct Object_00024480 {
    void func_00024480(int value);
};

extern Game *data_0022FCE0;

void func_00024600(int value)
{
    Object_00024480 *object = (Object_00024480 *)data_0022FCE0->func_000128C0(6);
    if (object) {
        object->func_00024480(value);
    }
}
