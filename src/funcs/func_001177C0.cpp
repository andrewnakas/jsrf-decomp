extern "C" void *memset(void *destination, int value, unsigned int size);

struct Object_00117510 {
    char unknown_000[0x48];
    int words[0xb4];
    char unknown_318[0xf0];
    int value_408;
    int value_40c;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
void func_001168F0();

// When object 0xea exists: calls func_001168F0, clears the object's 180 words at +0x48 and the word at +0x408,
// and sets +0x40c to -1.
void func_001177C0()
{
    Object_00117510 *object = (Object_00117510 *)data_0022FCE0->func_000128C0(0xea);
    if (object) {
        func_001168F0();
        object->value_408 = 0;
        memset(object->words, 0, sizeof(object->words));
        object->value_40c = -1;
    }
}
