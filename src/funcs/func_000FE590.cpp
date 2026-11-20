struct Game {
    void *func_000128C0(int id);
};

struct Object_000FDF30 {
    void func_000FE190();
};

extern Game *data_0022FCE0;

void func_000FE590()
{
    Object_000FDF30 *object = (Object_000FDF30 *)data_0022FCE0->func_000128C0(0x1165);
    if (object) {
        object->func_000FE190();
    }
}
