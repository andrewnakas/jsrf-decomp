struct Game {
    void *func_000128C0(int id);
};

struct Object_000FE190 {
    void func_000FE190();
};

extern Game *data_0022FCE0;

void func_000FE590()
{
    Object_000FE190 *object = (Object_000FE190 *)data_0022FCE0->func_000128C0(0x1165);
    if (object) {
        object->func_000FE190();
    }
}
