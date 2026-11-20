struct Vector3 {
    float x;
    float y;
    float z;
};

int func_00118BD0(int sound, Vector3 *position);
int func_00119540(int group, int index, void *position);

// A queued sound (0x18 bytes): the sound, or a group in the high and an index in the low half of the key.
struct Sound_000C0F70 {
    int sound;
    union {
        unsigned int key;
        struct {
            unsigned short index;
            unsigned short group;
        } part;
    };
    Vector3 position;
    char unknown_14[4];
};

// The object in data_00257CE4 (only the queue used here).
struct Object_000C1270 {
    char unknown_000[0xd8];
    Sound_000C0F70 sounds[64];
    unsigned int count;

    void func_000C0F70();
};

// Plays the queued sounds at 0xd8 (the count at 0x6d8) at their positions: func_00118BD0 for a sound without a
// key, func_00119540 with the key's halves otherwise; then empties the queue.
void Object_000C1270::func_000C0F70()
{
    Sound_000C0F70 *sound = sounds;
    for (unsigned int i = 0; i < count; i++) {
        if (sound->key == 0) {
            func_00118BD0(sound->sound, &sound->position);
        } else {
            func_00119540(sound->part.group, sound->key & 0xffff, &sound->position);
        }
        sound++;
    }
    count = 0;
}
