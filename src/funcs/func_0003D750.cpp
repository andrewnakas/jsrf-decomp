struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0003D680 {
    float func_0003D680(float scale, int text);
};

// The width of a text at a scale, from object 0x1166 (func_0003D680); 0 without it.
float func_0003D750(float scale, int text)
{
    float width = 0.0f;
    Object_0003D680 *object = (Object_0003D680 *)data_0022FCE0->func_000128C0(0x1166);
    if (object) {
        width = object->func_0003D680(scale, text);
    }
    return width;
}
