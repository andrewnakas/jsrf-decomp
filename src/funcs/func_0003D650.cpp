struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Box_0003D370;

struct Object_0003D370 {
    void func_0003D370(const char *text, Box_0003D370 *box);
};

// Passes a text and a box to func_0003D370 of object 0x1166, when it exists.
void func_0003D650(const char *text, Box_0003D370 *box)
{
    Object_0003D370 *object = (Object_0003D370 *)data_0022FCE0->func_000128C0(0x1166);
    if (object) {
        object->func_0003D370(text, box);
    }
}
