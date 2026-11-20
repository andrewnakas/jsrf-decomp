struct Object_00116A10 {
    char unknown_00[0x68];
    void *handle_68;
    void *handle_6c;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
void func_0013AA80(void *handle, int value);

// Passes a value to the ADX function func_0013AA80 for the handles at +0x68 and +0x6c of object 5.
void func_00116670(int value)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        func_0013AA80(object->handle_68, value);
        func_0013AA80(object->handle_6c, value);
    }
}
