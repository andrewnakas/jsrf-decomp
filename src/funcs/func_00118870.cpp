struct Object_00118CB0 {
    char unknown_0000[0x3eb4];
    int value_3eb4;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Stores a word at +0x3eb4 of object 4, when object 4 exists.
void func_00118870(int value)
{
    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
    if (object) {
        object->value_3eb4 = value;
    }
}
