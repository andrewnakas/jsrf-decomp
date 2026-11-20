struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A part of a list entry (0x48 bytes): two frame numbers packed in the word at +4.
struct Part_0006CC20 {
    char unknown_00[4];
    unsigned int frames;
    char unknown_08[0x40];
};

struct Entry_0006C610 {
    Part_0006CC20 *parts;
    char unknown_004[0x174];
    int key;
    char unknown_17c[0x10];
    Entry_0006C610 *next;
};

struct Object_000149B0 {
    int unknown_00;
    Entry_0006C610 *entries;
};

extern Object_000149B0 data_0020C750;

// Lane 2's object the ids name.
struct Object_000A6340 {
    void func_000A6270(Vector3 *target, int first, int second);
    void func_000A6340(int newFirst, int newSecond);
};

// The node class whose table is at 0x1CC158 (constructor 0x6C840, destructor 0x6CE00).
struct Object_0006CE00 {
    char unknown_00[0x44];
    int key;
    char unknown_48[0xc];
    unsigned int count;
    int *ids;
    char unknown_5c[4];
    int on;

    void func_0006CC20(Vector3 *target, int on);
};

// Keeps `on` (+0x60) and, with the entry of 0x20C750 whose key is +0x44, sets each node named at +0x58: switched on,
// towards the target with 9 and the high frame of its part plus 1 (func_000A6270); off, 8 and the low frame plus 6
// (func_000A6340).
void Object_0006CE00::func_0006CC20(Vector3 *target, int on)
{
    this->on = on;
    for (Entry_0006C610 *entry = data_0020C750.entries; entry; entry = entry->next) {
        if (entry->key == key) {
            if (on) {
                for (unsigned int i = 0; i < count; i++) {
                    Object_000A6340 *object = (Object_000A6340 *)data_0022FCE0->func_000128C0(ids[i]);
                    if (object) {
                        object->func_000A6270(target, 9, (entry->parts[i].frames >> 16) + 1);
                    }
                }
            } else {
                for (unsigned int i = 0; i < count; i++) {
                    Object_000A6340 *object = (Object_000A6340 *)data_0022FCE0->func_000128C0(ids[i]);
                    if (object) {
                        object->func_000A6340(8, (entry->parts[i].frames & 0xffff) + 6);
                    }
                }
            }
            return;
        }
    }
}
