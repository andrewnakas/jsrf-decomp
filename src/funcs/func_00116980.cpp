struct Object_00116A10 {
    char unknown_00[0xc0];
    int value_c0;
    int value_c4;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Returns the word at +0xc4 of object 5 for 0 and the one at +0xc0 otherwise; 0 when object 5 does not exist.
int func_00116980(int which)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (!object) {
        return 0;
    }
    if (!which) {
        return object->value_c4;
    }
    return object->value_c0;
}
