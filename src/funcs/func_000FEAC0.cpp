struct Game {
    void *func_000128C0(int id);
};

// Object 0x1165 (constructor func_000FE740, destructor func_000FDF30).
struct Object_000FDF30 {
    void func_000FE8A0(int index, int value, int first, const char *text, int second, int third);
};

extern Game *data_0022FCE0;

// Passes its arguments on to func_000FE8A0 of object 0x1165, when it exists.
void func_000FEAC0(int index, int value, int first, const char *text, int second, int third)
{
    Object_000FDF30 *object = (Object_000FDF30 *)data_0022FCE0->func_000128C0(0x1165);
    if (object) {
        object->func_000FE8A0(index, value, first, text, second, third);
    }
}
