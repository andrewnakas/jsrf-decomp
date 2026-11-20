struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000265A0 {
    int func_00025390(unsigned int index, int argument);
};

// Starts action `index` of object 7.
int func_000256A0(unsigned int index, int argument)
{
    Object_000265A0 *object = (Object_000265A0 *)data_0022FCE0->func_000128C0(7);
    return object->func_00025390(index, argument);
}
