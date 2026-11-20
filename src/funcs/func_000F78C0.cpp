struct Game {
    void *func_000128C0(int id);
};

struct Object_000F78C0 {
    char unknown_000[0x10c];
    int value;
};

extern Game *data_0022FCE0;

void func_000F78C0(int value)
{
    Object_000F78C0 *object = (Object_000F78C0 *)data_0022FCE0->func_000128C0(0x1164);
    if (object) {
        object->value = value;
    }
}
