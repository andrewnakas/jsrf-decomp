struct Game {
    void *func_000128C0(int id);
};

struct Object_000FEDB0 {
    char unknown_000[0x148];
    int value;
};

extern Game *data_0022FCE0;

int func_000FEC10()
{
    Object_000FEDB0 *object = (Object_000FEDB0 *)data_0022FCE0->func_000128C0(0x1163);
    if (object) {
        return object->value;
    }
    return 0;
}
