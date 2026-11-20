struct Object_00116A10 {
    char unknown_00[0x98];
    float volume;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Stores the music volume at +0x98 of object 5, when object 5 exists.
void func_00116930(float volume)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        object->volume = volume;
    }
}
