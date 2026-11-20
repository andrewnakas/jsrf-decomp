struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00024480 {
    void func_00024540(unsigned int color, float step);
};

// Passes a colour and a step to object 6, when it exists.
void func_00024620(unsigned int color, float step)
{
    Object_00024480 *object = (Object_00024480 *)data_0022FCE0->func_000128C0(6);
    if (object) {
        object->func_00024540(color, step);
    }
}
