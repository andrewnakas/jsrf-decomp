struct Object_00116A10 {
    char unknown_00[0x70];
    void *handle_70;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
void func_0013AA80(void *handle, int value);

// Passes a value to the ADX function func_0013AA80 for the handle at +0x70 of object 5, when object 5 exists.
void func_001166B0(int value)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        func_0013AA80(object->handle_70, value);
    }
}
