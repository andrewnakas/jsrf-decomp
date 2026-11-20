struct Entry_001160D0 {
    int id;
    const char *name;
};

// Object 5, the sound player.
struct Object_00116A10 {
    char unknown_000[0x70];
    void *handle_70;
    char unknown_074[0x20];
    float volume;
    char unknown_098[0x28];
    int playing;
    char unknown_0c4[0x34];
    int value_f8;

    const char *func_001164F0(int index);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern const Entry_001160D0 data_001D3A38[];

void func_0013AA70(void *handle, char value);
void func_0013AA60(void *handle, char value);
void func_0013A6B0(void *handle);
void func_0013AEB0(void *handle, const char *name);

// Starts `id` from the table at data_001D3A38 on object 5's ADX handle at +0x70 at full volume (the search is
// func_001160D0's kind 2, inlined; id 1 is entry 0); an unknown id only marks the handle playing.
void func_00117140(int id)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        object->playing = 1;
        object->volume = 1.0f;
        object->value_f8 = 0;
        Object_00116A10 *player = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
        if (player) {
            func_0013AA70(player->handle_70, 1);
        }
        int index = 0;
        if (id != 1) {
            do {
                if (data_001D3A38[index++].id == -1) {
                    index = -1;
                    break;
                }
            } while (data_001D3A38[index].id != id);
        }
        if (index >= 0) {
            func_0013AA60(object->handle_70, 0);
            func_0013A6B0(object->handle_70);
            func_0013AEB0(object->handle_70, object->func_001164F0(index));
        }
    }
}
