struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

extern "C" void *memset(void *, int, unsigned int);

void *func_00025700(unsigned int index, int first, int second, int third);
void func_0005EC20(void *target, int first, int second, int third, int fourth, Motion_0005F060 *blend, float frame,
                   float weight);
float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

// What +0xc of an entry points at.
struct Object_000800D0 {
    void func_000800D0(int value);
    void func_00080110(int first, float value, int second);
    void func_000841C0(float *position, int *angles, float distance, int flag);
};

// What func_00025700 (1 or 2, ...) returns: the model target at +0x8.
struct Sprite_00022530 {
    char unknown_00[8];
    void *target;
};

// What +0x8 of an entry points at: per key at +0x120 the value its object takes (func_000800D0), and the keys that
// end it at +0x124.
struct Info_00022530 {
    int unknown_000;
    int slot;
    int unknown_008;
    char unknown_00c[0x110];
    unsigned int count;
    unsigned int *starts;
    unsigned int *stops;
    int *values;
};

struct Entry_00022530 {
    char unknown_00[8];
    Info_00022530 *info;
    Object_000800D0 *object;
    char unknown_10[0xc];
    Vector3 position;
    Vector3 target;
    char unknown_34[8];
    int angle;
    char unknown_40[4];
    int angleX;
    int turn;
    char unknown_4c[8];
    int motion;
    int blend;
    int argument;
    int frame;
    char unknown_64[8];
    float weight;
    int base;
    char unknown_74[0x18];
    int id;
    char unknown_90[0xc];
    int unknown_9c;
    int current;
    float distance;
};

struct State_00022530 {
    char unknown_000[0x60];
    Motion_0005F060 **motions;
    unsigned int count;
    int *active;
};

extern float data_001C43D0;

// Node child with the table at 0x1C4BA8.
struct Object_00022990 {
    char unknown_00[0x94];
    unsigned int key;
    char unknown_98[0x44];
    State_00022530 *state;
    Entry_00022530 **entries;

    void func_00022200(unsigned int index);
    void func_00022530(unsigned int index);
};

// Called by func_00023790 for every entry: with any slots, the entry's slot active, its kind's +0x8 set and an
// object, places the object (func_000841C0) at the entry's position, turned by its angles, with its distance to the
// target (100 when positive); then with a motion runs it on the object (blended through func_0005EC20 on what
// func_00025700 (1 or 2, +0x8c) finds when +0x58 is set), else, with +0x9c negative, follows the keys of +0x120
// (the found index at +0xa0) and with none current runs func_00022200.
void Object_00022990::func_00022530(unsigned int index)
{
    int angles[3] = {0, 0, 0};
    Entry_00022530 *entry = entries[index];
    Info_00022530 *info = entry->info;
    if (state->count > 0 && state->active[info->slot] && info->unknown_008 && entry->object) {
        angles[0] = entry->angleX;
        angles[1] = entry->turn + entry->angle + 0x8000;
        entry->distance = func_0014C530(&entry->position, &entry->target);
        if (entry->distance > data_001C43D0)
            entry->distance = 100.0f;
        entry->object->func_000841C0(&entry->position.x, angles, entry->distance, 0);
        if (entry->motion >= 0) {
            if (entry->blend < 0) {
                entry->object->func_00080110((int)state->motions[entry->motion], 0.0f, entry->argument);
                return;
            }
            Sprite_00022530 *sprite;
            if (func_00025700(1, entry->id, 0, 0))
                sprite = (Sprite_00022530 *)func_00025700(1, entry->id, 0, 0);
            else if (func_00025700(2, entry->id, 0, 0))
                sprite = (Sprite_00022530 *)func_00025700(2, entry->id, 0, 0);
            if (sprite) {
                func_0005EC20(sprite->target, entry->base, 0, (int)state->motions[entry->blend], entry->frame,
                              state->motions[entry->motion], *(float *)&entry->argument, 1.0f - entry->weight);
                entry->object->func_00080110(entry->base, 0.0f, 0);
            }
        } else if (entry->unknown_9c < 0) {
            if (entry->current < 0) {
                for (unsigned int i = 0; i < info->count; i++) {
                    if (info->starts[i] == key) {
                        entry->current = i;
                        entry->object->func_000800D0(info->values[i]);
                        break;
                    }
                }
            } else if (info->stops[entry->current] == key) {
                entry->current = -1;
            }
            if (entry->current < 0)
                func_00022200(index);
        }
    }
}
