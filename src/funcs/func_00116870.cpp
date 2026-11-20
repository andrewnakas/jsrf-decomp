struct Object_00116A10 {
    char unknown_00[0x6c];
    void *handle_6c;
    void *handle_70;
    char unknown_74[0x4c];
    int value_c0;
    int value_c4;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
void func_0013A6B0(void *handle);

// Clears the words at +0xc0 and +0xc4 of object 5 and passes its handles at +0x70 and +0x6c to the ADX
// function func_0013A6B0.
void func_00116870()
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        object->value_c0 = 0;
        object->value_c4 = 0;
        func_0013A6B0(object->handle_70);
        func_0013A6B0(object->handle_6c);
    }
}
