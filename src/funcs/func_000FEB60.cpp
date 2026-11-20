struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0x1163.
struct Object_000FEC10 {
    void func_000FEE20(int kind, int first, int second, int third);
};

// Passes its arguments on to func_000FEE20 of object 0x1163, when it exists.
void func_000FEB60(int kind, int first, int second, int third)
{
    Object_000FEC10 *object = (Object_000FEC10 *)data_0022FCE0->func_000128C0(0x1163);
    if (object) {
        object->func_000FEE20(kind, first, second, third);
    }
}
