struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00025000 {
    char unknown_00[0x44];
    int unknown_44;
    int unknown_48;
    unsigned int unknown_4c;
};

// Sets the word at +0x44 of object 0x1df1 and, for a value below 9, stores the value at +0x4c.
void func_00024FD0(unsigned int value)
{
    Object_00025000 *object = (Object_00025000 *)data_0022FCE0->func_000128C0(0x1df1);
    if (object) {
        object->unknown_44 = 1;
        if (value < 9) {
            object->unknown_4c = value;
        }
    }
}
