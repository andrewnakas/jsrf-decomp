struct Vector3 {
    float x;
    float y;
    float z;
};

// A queued sound (0x18 bytes): the sound, the key (0 for a plain sound), the position and its distance.
struct Sound_000C1270 {
    int sound;
    unsigned int key;
    Vector3 position;
    float distance;
};

// The object in data_00257CE4: its point at 0x7c, the queued sounds at 0xd8.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 point;
    char unknown_88[0x50];
    Sound_000C1270 sounds[64];
    unsigned int count;

    int func_000C0FE0(int sound);
    void func_000C1270(int handle, void *position);
};

// Finds the entry of the sound among the queued ones; otherwise, while fewer than 64 are queued, adds one (key 0,
// distance 10000). Returns the entry's index, or -1 when the queue is full.
int Object_000C1270::func_000C0FE0(int sound)
{
    Sound_000C1270 *entry = sounds;
    for (unsigned int index = 0; index < count; entry++, index++) {
        if (entry->sound == sound) {
            return index;
        }
    }
    if (count < 64) {
        unsigned int last = count;
        count = last + 1;
        entry = &sounds[last];
        entry->sound = sound;
        entry->key = 0;
        entry->distance = 10000.0f;
        return last;
    }
    return -1;
}
