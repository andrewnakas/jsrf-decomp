struct Game {
    void *func_000128C0(int id);
};

struct Object_000FDF30 {
    int func_000FE480(int index);
};

extern Game *data_0022FCE0;

// func_000FE480(index) of object 0x1165, or 0 when it does not exist.
int func_000FE620(int index)
{
    int result = 0;
    Object_000FDF30 *object = (Object_000FDF30 *)data_0022FCE0->func_000128C0(0x1165);
    if (object) {
        result = object->func_000FE480(index);
    }
    return result;
}
