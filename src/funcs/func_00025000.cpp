struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00025000 {
    char unknown_00[0x44];
    int unknown_44;
};

// Clears the word at +0x44 of object 0x1df1, when it exists.
void func_00025000()
{
    Object_00025000 *object = (Object_00025000 *)data_0022FCE0->func_000128C0(0x1df1);
    if (object) {
        object->unknown_44 = 0;
    }
}
