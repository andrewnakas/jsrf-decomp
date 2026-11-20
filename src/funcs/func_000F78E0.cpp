struct Game {
    void *func_000128C0(int id);
};

struct Object_000F78E0 {
    char unknown_000[0x120];
    int value;
};

extern Game *data_0022FCE0;

void func_000F78E0(int value)
{
    Object_000F78E0 *object = (Object_000F78E0 *)data_0022FCE0->func_000128C0(0x1164);
    if (object) {
        object->value = value;
    }
}
