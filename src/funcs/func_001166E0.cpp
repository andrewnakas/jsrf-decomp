struct Game {
    void *func_000128C0(int id);
};

struct Object_00116A10 {
    char unknown_00[0x68];
    void *handles[4];
    int current;
    int states[4];
    float volumes[4];
    int value_9c;
    char unknown_a0[8];
    int fading[4];
    int value_b8;
    char unknown_bc[0x14];
    float rates[4];
    float targets[4];
    int ramps[4];
    int value_100;

    void func_00116200(int channel);
    void func_00116290(int channel, char value);
};

extern Game *data_0022FCE0;

// Switches object 5 to its other music channel: with a `track`, only starts it there (func_00116290) in state 2.
// Otherwise makes that channel current, at volume 0 ramping up at 1/60 per frame when its word at +0xa8 is set or
// at full volume in state 1, starts it, copies +0xb8 to +0x9c, then ramps the old channel likewise when its word at
// +0xa8 is set and stops it (func_00116200) otherwise.
void func_001166E0(int track)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        if (track) {
            int channel = object->current ^ 1;
            object->func_00116290(channel, track);
            object->states[channel] = 2;
            return;
        }
        object->current ^= 1;
        int other = object->current ^ 1;
        if (object->fading[object->current]) {
            object->volumes[object->current] = 0.0f;
            int channel = object->current;
            object->value_100 = 0;
            object->targets[channel] = 1.0f;
            object->rates[channel] = 1.0f / 60.0f;
            object->ramps[channel] = 1;
        } else {
            object->volumes[object->current] = 1.0f;
            object->states[object->current] = 1;
            object->ramps[object->current] = 0;
        }
        object->func_00116290(object->current, 0);
        object->value_9c = object->value_b8;
        if (object->fading[other]) {
            object->value_100 = 1;
            object->ramps[other] = 1;
            object->targets[other] = 1.0f;
            object->rates[other] = 1.0f / 60.0f;
        } else {
            object->func_00116200(other);
        }
    }
}
