struct Entry_001160D0 {
    int id;
    const char *name;
};

// Object 5, the sound player.
struct Object_00116A10 {
    char unknown_000[0x74];
    void *handle_74;
    char unknown_078[0x28];
    int sound;
    char unknown_0a4[0x24];
    int playing;

    int func_001160D0(int kind, int id);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern const Entry_001160D0 data_001D4DB0[];

void func_0013AA70(void *handle, char value);
void func_0013AA60(void *handle, char value);
void func_0013A6B0(void *handle);
void func_0013AEB0(void *handle, const char *name);

// Switches object 5's sound at +0xA0 to `sound` unless it is already playing: marks it playing, sets the flag of
// its ADX handle at +0x74, and for a sound known to kind 3 of func_001160D0 restarts the handle on the sound's file.
void func_001171F0(int sound)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object && object->sound != sound) {
        object->playing = 1;
        Object_00116A10 *player = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
        if (player) {
            func_0013AA70(player->handle_74, 1);
        }
        int index = object->func_001160D0(3, sound);
        if (index >= 0) {
            func_0013AA60(object->handle_74, 1);
            func_0013A6B0(object->handle_74);
            func_0013AEB0(object->handle_74, data_001D4DB0[index].name);
        }
        object->sound = sound;
    }
}
