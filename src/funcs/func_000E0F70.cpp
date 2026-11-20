struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060810(int key);
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

struct Object_000E0440 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0x98];
    int value_0a0;
    char unknown_0a4[0x10];
    int timer;
    char unknown_0b8[0x28];
    float value_0e0;
    char unknown_0e4[0x3c];
    int sounds[2];
    char unknown_128[8];
    int handle_130;
    int handle_134;

    void func_000E0F70();
};

// Entry 12 of the handler table at 0x217DFC: stops the two sounds at 0x120 that are set through object 0xe8
// (func_00060810) and marks them -1; when the timer at 0xb4 runs out, clears 0xa0 and sets 0xe0 to -1; then hands
// the handles at 0x130 and 0x134 to the owner (func_000C5B50).
void Object_000E0440::func_000E0F70()
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        for (int i = 0; i < 2; i++) {
            if (sounds[i] >= 0) {
                object->func_00060810(sounds[i]);
                sounds[i] = -1;
            }
        }
    }
    if (--timer <= 0) {
        value_0a0 = 0;
        value_0e0 = -1.0f;
    }
    owner->func_000C5B50(&handle_130);
    owner->func_000C5B50(&handle_134);
}
