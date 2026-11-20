struct Object_00116A10 {
    char unknown_00[0xbc];
    int value_bc;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Returns the word at +0xbc of object 5, or 0 when object 5 does not exist.
int func_001167F0()
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (!object) {
        return 0;
    }
    return object->value_bc;
}
