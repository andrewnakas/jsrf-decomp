struct Object_00117510 {
    void func_00117560(int first, int second, float x, float y);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Passes its arguments to func_00117560 of object 0xea, the two coordinates scaled by 10.
void func_00117770(int first, int second, float x, float y)
{
    Object_00117510 *object = (Object_00117510 *)data_0022FCE0->func_000128C0(0xea);
    if (object) {
        object->func_00117560(first, second, x * 10.0f, y * 10.0f);
    }
}
