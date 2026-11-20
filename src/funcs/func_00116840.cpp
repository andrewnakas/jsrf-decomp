struct Object_00116A10 {
    char unknown_00[0x6c];
    void *handle_6c;
    char unknown_70[0x5c];
    int value_cc;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
void func_0013A6B0(void *handle);

// Clears the word at +0xcc of object 5 and passes its handle at +0x6c to the ADX function func_0013A6B0.
void func_00116840()
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        object->value_cc = 0;
        func_0013A6B0(object->handle_6c);
    }
}
