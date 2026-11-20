struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0003EDA0 {
    void func_0003EDA0(int value);
};

// Passes a value to func_0003EDA0 of the object registered under an id, when it exists.
void func_0003EDF0(int id, int value)
{
    Object_0003EDA0 *object = (Object_0003EDA0 *)data_0022FCE0->func_000128C0(id);
    if (object) {
        object->func_0003EDA0(value);
    }
}
