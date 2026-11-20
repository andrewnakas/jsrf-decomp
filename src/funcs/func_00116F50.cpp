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
    void func_00116AB0(int channel, int track);
};

extern Game *data_0022FCE0;

// Starts `track` on the other music channel of object 5 (func_00116AB0). When that channel is in state 2 (queued
// by func_001166E0), only sets the two channels' fade words (+0xa8) to `fade_in` and `fade_out` and records the
// track at +0xb8. Otherwise makes it current, ramping its volume up from 0 at 1/60 per frame with `fade_in` or at
// full volume in state 1 without, records the track at +0x9c, and ramps the old channel down to 0 with `fade_out`
// or stops it (func_00116200) without.
void func_00116F50(int track, int fade_in, int fade_out)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        int channel = object->current ^ 1;
        if (object->states[channel] == 2) {
            object->func_00116AB0(channel, track);
            object->fading[channel] = fade_in;
            object->fading[object->current] = fade_out;
            object->value_b8 = track;
            return;
        }
        int other = channel ^ 1;
        object->current = channel;
        if (fade_in) {
            object->volumes[channel] = 0.0f;
            int current = object->current;
            object->value_100 = 0;
            object->targets[current] = 1.0f;
            object->rates[current] = 1.0f / 60.0f;
            object->ramps[current] = 1;
        } else {
            object->volumes[channel] = 1.0f;
            object->states[object->current] = 1;
            object->ramps[object->current] = 0;
        }
        object->func_00116AB0(object->current, track);
        object->value_9c = track;
        if (fade_out) {
            object->value_100 = 1;
            object->targets[other] = 0.0f;
            object->rates[other] = 1.0f / 60.0f;
            object->ramps[other] = 1;
        } else {
            object->func_00116200(other);
        }
    }
}
