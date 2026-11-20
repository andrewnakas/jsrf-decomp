struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0007E0E0 {
    char unknown_00[0x48];
    int unknown_48;
};

// Sets the word at +0x48 of object 0x1df3 to 1, when it exists.
void func_0007E0E0()
{
    Object_0007E0E0 *object = (Object_0007E0E0 *)data_0022FCE0->func_000128C0(0x1df3);
    if (object) {
        object->unknown_48 = 1;
    }
}
