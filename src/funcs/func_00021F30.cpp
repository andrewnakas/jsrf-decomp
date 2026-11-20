struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0x1ddc.
struct Object_000239D0 {
    void func_00023AD0(int value);
    void func_00023B90(int value, float scale);
};

// A list of the block at +0xdc (at +0x188): per key a length, whether it fades out and whether it is white.
struct Fades_00021F30 {
    unsigned int count;
    unsigned int *keys;
    unsigned int *lengths;
    int *out;
    int *white;
};

struct State_00021F30 {
    char unknown_000[0x188];
    Fades_00021F30 fades;
};

struct Object_00022990 {
    char unknown_00[0x94];
    unsigned int key;
    char unknown_98[0x44];
    State_00021F30 *state;

    void func_00021F30();
};

// Called by func_00023790: for each fade of the block at +0xdc whose key is +0x94, sets object 0x1ddc fading (its
// func_00023AD0 and func_00023B90) from opaque to clear or back, black or white, over the fade's length.
void Object_00022990::func_00021F30()
{
    Fades_00021F30 *fades = &state->fades;
    Object_000239D0 *object = (Object_000239D0 *)data_0022FCE0->func_000128C0(0x1ddc);
    for (unsigned int i = 0; i < fades->count; i++) {
        if (key == fades->keys[i]) {
            float step = 1.0f / fades->lengths[i];
            unsigned char from;
            unsigned char to;
            if (fades->out[i] == 0) {
                from = 0xff;
                to = 0;
            } else {
                from = 0;
                to = 0xff;
            }
            if (fades->white[i] == 0) {
                object->func_00023AD0(from << 24);
                object->func_00023B90(to << 24, step);
            } else {
                object->func_00023AD0(from << 24 | 0xffffff);
                object->func_00023B90(to << 24 | 0xffffff, step);
            }
        }
    }
}
