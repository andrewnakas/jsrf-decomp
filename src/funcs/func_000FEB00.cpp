struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0x1163.
struct Object_000FEDB0 {
    void func_000FF390(unsigned int mask, int value, int flag);
};

// Passes its arguments on to func_000FF390 of object 0x1163, when it exists.
void func_000FEB00(unsigned int mask, int value, int flag)
{
    Object_000FEDB0 *object = (Object_000FEDB0 *)data_0022FCE0->func_000128C0(0x1163);
    if (object) {
        object->func_000FF390(mask, value, flag);
    }
}
