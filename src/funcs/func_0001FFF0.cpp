struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

extern Vector3 data_001EBEF0;
extern Vector3 data_001EBEFC;

// A 16-byte record kept by Object_00015D50: a position and a size.
struct Record_00015D10 {
    Vector3 position;
    float size;
};

// An effect (constructor 0x15420, size 0x118).
struct Object_00015D50 {
    virtual ~Object_00015D50();

    void func_00015520();
    void func_00015D10(const Record_00015D10 *record);
};

// The model base class (table 0x1CAA8C).
struct Object_00047470 {
    virtual ~Object_00047470();

    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

// What func_00025700 (5, ...) returns: its motions at +0x18.
struct Sprite_0001FED0 {
    char unknown_00[0x18];
    Motion_0005F060 **motions;
};

struct Owner_0001FFF0 {
    char unknown_00[8];
    Object_00047470 *model;
};

struct Info_0001FED0 {
    int unknown_00;
    int slot;
};

struct Entry_0001FED0 {
    char unknown_00[8];
    Info_0001FED0 *info;
    char unknown_0c[0x10];
    Vector3 position;
    char unknown_28[0x10];
    int flag;
    int angle;
    int angleZ;
    int angleX;
    int turn;
    char unknown_4c[8];
    int motion;
    char unknown_58[4];
    int argument;
    char unknown_60[0x14];
    Object_00015D50 *first;
    Object_00015D50 *second;
};

struct State_0001FED0 {
    char unknown_00[0x2c];
    int *flags;
    char unknown_30[0x30];
    void **motions;
    char unknown_64[4];
    int *active;
    char unknown_6c[0x30];
    Owner_0001FFF0 **owners;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990); its slot 4 (0x23790) runs the member-pointer table
// at 0x1EBCF0 by each entry's kind.
struct Object_00022990 {
    char unknown_00[0xcc];
    float times[4];
    State_0001FED0 *state;
    Entry_0001FED0 **entries;

    void func_0001FFF0(unsigned int index);
};

// Kinds 20 and 24 of the table at 0x1EBCF0: for an entry whose slot is active and that has a motion (+0x54), draws
// the slot owner's model at the entry's position and angles (the Y angle only with the flag of +0x38) with that
// motion, parts 10, 1, 2 and 9 with the entry's effects between them (the second one at two points of the model);
// then steps the four times at +0xcc through motions 0 to 3 of the object func_00025700 (5, 20) finds, at half speed.
void Object_00022990::func_0001FFF0(unsigned int index)
{
    Entry_0001FED0 *entry = entries[index];
    State_0001FED0 *slots = state;
    Sprite_0001FED0 *sprite = (Sprite_0001FED0 *)func_00025700(5, 0x14, 0, 0);
    if (slots->active[entry->info->slot]) {
        Object_00047470 *model = slots->owners[entry->info->slot]->model;
        if (entry->motion != -1) {
            func_001BA9C0();
            func_001BAAA0(&entry->position.x);
            func_001BB330(entry->turn + entry->angle);
            if (state->flags[entry->flag])
                func_001BB2E0(entry->angleX);
            func_001BB380(entry->angleZ);
            model->func_00047970(slots->motions[entry->motion], entry->argument);
            model->func_000480C0(10);
            entry->first->func_00015520();
            model->func_000480C0(1);
            Record_00015D10 record;
            func_001BAB20(&record.position, &data_001EBEFC);
            record.size = 3.1603f;
            entry->second->func_00015D10(&record);
            model->func_000480C0(2);
            func_001BAB20(&record.position, &data_001EBEF0);
            record.size = 3.4805f;
            entry->second->func_00015D10(&record);
            model->func_000480C0(9);
            entry->second->func_00015520();
            func_001BAA50();
        }
        if (sprite) {
            for (unsigned int i = 0; i < 4; i++)
                func_0005E030(sprite->motions[i], &times[i], 0.5f, 0);
        }
    }
}
