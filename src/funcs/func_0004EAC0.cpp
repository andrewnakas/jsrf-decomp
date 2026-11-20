struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0006A710 {
    void func_0006A710(int value);
};

struct Object_0004EAC0 {
    char unknown_0000[0x1050];
    Object_0006A710 *unknown_1050;
};

// Passes a value to func_0006A710 of the part at +0x1050 of object 9, when both exist.
void func_0004EAC0(int value)
{
    Object_0004EAC0 *object = (Object_0004EAC0 *)data_0022FCE0->func_000128C0(9);
    if (object && object->unknown_1050) {
        object->unknown_1050->func_0006A710(value);
    }
}
