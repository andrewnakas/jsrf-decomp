struct Vector3 {
    float x;
    float y;
    float z;
};

extern "C" void *memset(void *, int, unsigned int);

int func_00119540(int sound, int volume, void *data);
int func_001186D0(int handle);
int func_00118BD0(int handle, Vector3 *position);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The model base class (table 0x1CAA8C).
struct Object_00047470 {
    virtual ~Object_00047470();

    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

// The sounds of an entry's kind (at +0xc4 of what +0x8 of an entry points at): per sound the keys that start and
// stop it, the sound (0x39: the block's first word + 100), its second argument, its position, and whether it follows a
// model part (and which).
struct Sounds_00021B20 {
    unsigned int count;
    unsigned int *starts;
    unsigned int *stops;
    int *sounds;
    int *volumes;
    char unknown_14[4];
    Vector3 *positions;
    int *attached;
    unsigned int *parts;
};

struct Info_00021B20 {
    int unknown_00;
    int slot;
    char unknown_08[0xbc];
    Sounds_00021B20 sounds;
};

struct Entry_00021B20 {
    char unknown_00[8];
    Info_00021B20 *info;
    char unknown_0c[0x10];
    Vector3 position;
    char unknown_28[0x10];
    int flag;
    int angle;
    int angleZ;
    int angleX;
    int turn;
    char unknown_4c[4];
    int *handles;
    int motion;
    char unknown_58[4];
    int argument;
};

struct Owner_00021B20 {
    Object_00047470 *model;
};

struct State_00021B20 {
    int unknown_000;
    char unknown_004[0x28];
    int *flags;
    char unknown_030[0x30];
    void **motions;
    char unknown_064[4];
    int *active;
    char unknown_06c[0x30];
    Owner_00021B20 **owners;
};

// Node child with the table at 0x1C4BA8.
struct Object_00022990 {
    char unknown_00[0x94];
    unsigned int key;
    char unknown_98[0x44];
    State_00021B20 *state;
    Entry_00021B20 **entries;

    void func_00021B20(unsigned int index);
};

// Called by func_00023790 for every entry: starts (func_00119540) the sounds of the entry whose start key is +0x94
// and stops (func_001186D0, handle -1) those whose stop key is; then places every sound (func_00118BD0): for entries 2
// and up of an active slot at the sound's position under the slot owner's model at the entry's position and angles
// (posed with the entry's motion and part when the sound follows the model), else where the sound says.
void Object_00022990::func_00021B20(unsigned int index)
{
    Entry_00021B20 *entry = entries[index];
    Sounds_00021B20 *sounds = &entry->info->sounds;
    Vector3 vector;
    int sound;
    for (unsigned int i = 0; i < sounds->count; i++) {
        if (sounds->starts[i] == key) {
            sound = sounds->sounds[i];
            if (sound == 0x39)
                sound = state->unknown_000 + 100;
            entry->handles[i] = func_00119540(sound, sounds->volumes[i], 0);
        }
        if (sounds->stops[i] && sounds->stops[i] == key) {
            func_001186D0(entry->handles[i]);
            entry->handles[i] = -1;
        }
        if (index >= 2) {
            if (state->active[entry->info->slot]) {
                Object_00047470 *model = state->owners[entry->info->slot]->model;
                func_001BAA00();
                func_001BAAA0(&entry->position.x);
                func_001BB330(entry->turn + entry->angle);
                if (state->flags[entry->flag])
                    func_001BB2E0(entry->angleX);
                func_001BB380(entry->angleZ);
                if (sounds->attached[i]) {
                    if (entry->motion < 0)
                        model->func_00047970(0, 0);
                    else
                        model->func_00047970(state->motions[entry->motion], entry->argument);
                    model->func_000480C0(sounds->parts[i]);
                }
                memset(&vector, 0, sizeof(vector));
                func_001BAAA0(&sounds->positions[i].x);
                func_001BAB20(&vector, 0);
                func_00118BD0(entry->handles[i], &vector);
                func_001BAA50();
            }
        } else {
            func_00118BD0(entry->handles[i], &sounds->positions[i]);
        }
    }
}
