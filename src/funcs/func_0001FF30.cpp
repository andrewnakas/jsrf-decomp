struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int flags);

// What func_00025700 (5, ...) returns: its motions at +0x18.
struct Sprite_0001FED0 {
    char unknown_00[0x18];
    Motion_0005F060 **motions;
};

struct Info_0001FED0 {
    int unknown_00;
    int slot;
};

struct Entry_0001FED0 {
    char unknown_00[8];
    Info_0001FED0 *info;
    char unknown_0c[0x58];
    float time;
};

struct State_0001FED0 {
    char unknown_00[0x68];
    int *active;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990); its slot 4 (0x23790) runs the member-pointer table
// at 0x1EBCF0 by each entry's kind.
struct Object_00022990 {
    char unknown_00[0xdc];
    State_0001FED0 *state;
    Entry_0001FED0 **entries;

    void func_0001FF30(unsigned int index);
};

// Kind 25 of the table at 0x1EBCF0: for entries after the first two whose slot is active, steps the entry's time
// (+0x64) through motion 1 of the object func_00025700 (5, 0x11) finds, at half speed.
void Object_00022990::func_0001FF30(unsigned int index)
{
    Entry_0001FED0 *entry = entries[index];
    if (index > 1 && state->active[entry->info->slot]) {
        Sprite_0001FED0 *sprite = (Sprite_0001FED0 *)func_00025700(5, 0x11, 0, 0);
        if (sprite)
            func_0005E030(sprite->motions[1], &entry->time, 0.5f, 0);
    }
}
