void func_0013A6B0(void *handle);

struct Object_00116A10 {
    char unknown_00[0x68];
    void *handles[4];
    char unknown_78[0x28];
    int value_a0;
    char unknown_a4[0x24];
    int value_c8;

    void func_00116200(int channel)
    {
        switch (channel) {
        case 4:
            func_0013A6B0(handles[1]);
            break;
        case 5:
            func_0013A6B0(handles[2]);
            break;
        default:
            func_0013A6B0(handles[channel]);
            break;
        }
    }
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Clears the word at +0xc8 of object 5, stops channel 3 and sets +0xa0 to -1. Retail inlined func_00116200
// (same source file), so it is written here as an inline helper.
void func_001168F0()
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        object->value_c8 = 0;
        object->func_00116200(3);
        object->value_a0 = -1;
    }
}
