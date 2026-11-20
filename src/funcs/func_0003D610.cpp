struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0003D680 {
    void func_0003D210(float first, float second, float scale, unsigned int value, float x, float y, int last);
};

// Passes its arguments on to func_0003D210 of object 0x1166, when it exists.
void func_0003D610(float first, float second, float scale, unsigned int value, float x, float y, int last)
{
    Object_0003D680 *object = (Object_0003D680 *)data_0022FCE0->func_000128C0(0x1166);
    if (object) {
        object->func_0003D210(first, second, scale, value, x, y, last);
    }
}
