// Object 5, the sound player.
struct Object_00116A10 {
    char unknown_000[0x68];
    void *handles[4];
    char unknown_078[0x18];
    float volume_90;
    float volume_94;
    char unknown_098[0x28];
    int flag_c0;
    int flag_c4;
    char unknown_0c8[0x2c];
    int value_f4;
    int value_f8;

    void func_00116240(int channel, int value);
    void func_00116AB0(int channel, int track);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern const int data_001D7770[];

void func_0013A6B0(void *handle);

// Plays `track` on object 5's player for `slot` (its channel from data_001D7770): stops the channel's ADX handle
// (func_00116200, inlined), restarts it (func_00116240) and starts the track (func_00116AB0); then sets the flag
// at +0xc4 for slot 0 (+0xc0 otherwise), both volumes to 1 and clears +0xf4 and +0xf8.
void func_00117280(int slot, int track)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        switch (data_001D7770[slot]) {
        case 4:
            func_0013A6B0(object->handles[1]);
            break;
        case 5:
            func_0013A6B0(object->handles[2]);
            break;
        default:
            func_0013A6B0(object->handles[data_001D7770[slot]]);
            break;
        }
        object->func_00116240(data_001D7770[slot], 1);
        object->func_00116AB0(data_001D7770[slot], track);
        if (slot == 0) {
            object->flag_c4 = 1;
        } else {
            object->flag_c0 = 1;
        }
        object->volume_90 = 1.0f;
        object->volume_94 = 1.0f;
        object->value_f4 = 0;
        object->value_f8 = 0;
    }
}
