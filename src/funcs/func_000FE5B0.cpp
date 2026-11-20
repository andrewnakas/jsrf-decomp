struct Game {
    void *func_000128C0(int id);
};

struct Object_000FDF30 {
    void func_000FE210(int id);
};

extern Game *data_0022FCE0;

// Passes the id on to func_000FE210 of object 0x1165, when it exists.
void func_000FE5B0(int id)
{
    Object_000FDF30 *object = (Object_000FDF30 *)data_0022FCE0->func_000128C0(0x1165);
    if (object) {
        object->func_000FE210(id);
    }
}
