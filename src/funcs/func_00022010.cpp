struct Vector3 {
    float x;
    float y;
    float z;
};

extern "C" void *memset(void *, int, unsigned int);

struct Desc_00060A40;

int func_00062360(Desc_00060A40 *desc, Vector3 *position, Vector3 *direction);
void func_00060B10(int id, Vector3 *position);
void func_00060B40(int id, Vector3 *direction);
void func_00060B70(int id);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The model base class (table 0x1CAA8C).
struct Object_00047470 {
    virtual ~Object_00047470();

    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

// The effects of an entry's kind (at +0xf8 of what +0x8 of an entry points at): per effect the keys that start and
// stop it, its descriptor, whether it follows a model part (and which), and its position and direction.
struct Effects_00022010 {
    unsigned int count;
    unsigned int *starts;
    unsigned int *stops;
    int *descs;
    int *attached;
    unsigned int *parts;
    Vector3 *positions;
    Vector3 *directions;
};

struct Info_00022010 {
    int unknown_00;
    int slot;
    char unknown_08[0xf0];
    Effects_00022010 effects;
};

struct Entry_00022010 {
    char unknown_00[8];
    Info_00022010 *info;
    char unknown_0c[0x10];
    Vector3 position;
    char unknown_28[0x10];
    int flag;
    int angle;
    int angleZ;
    int angleX;
    int turn;
    int *ids;
    char unknown_50[4];
    int motion;
    char unknown_58[4];
    int argument;
};

struct Owner_00022010 {
    Object_00047470 *model;
};

struct Pair_00022010 {
    Desc_00060A40 *desc;
    int unknown_04;
};

struct State_00022010 {
    char unknown_000[0x2c];
    int *flags;
    char unknown_030[0x30];
    void **motions;
    char unknown_064[0x38];
    Owner_00022010 **owners;
    char unknown_0a0[0x10c];
    Pair_00022010 *descs;
};

// Node child with the table at 0x1C4BA8.
struct Object_00022990 {
    char unknown_00[0x94];
    unsigned int key;
    char unknown_98[0x44];
    State_00022010 *state;
    Entry_00022010 **entries;

    void func_00022010(unsigned int index);
};

// Called by func_00023790 for every entry: starts (func_00062360) the effects of the entry whose start key is +0x94
// and stops (func_00060B70) those whose stop key is; then places every effect (func_00060B10 / func_00060B40): for
// entries 2 and up at the effect's position and direction under the slot owner's model at the entry's position and
// angles (posed with the entry's motion and part when the effect follows the model), else where the effect says.
void Object_00022990::func_00022010(unsigned int index)
{
    Entry_00022010 *entry = entries[index];
    Effects_00022010 *effects = &entry->info->effects;
    Vector3 vector;
    for (unsigned int i = 0; i < effects->count; i++) {
        if (effects->starts[i] == key) {
            entry->ids[i] = func_00062360(state->descs[effects->descs[i]].desc, 0, 0);
        }
        if (effects->stops[i] == key) {
            func_00060B70(entry->ids[i]);
        }
        if (index >= 2) {
            Object_00047470 *model = state->owners[entry->info->slot]->model;
            if (model) {
                func_001BAA00();
                func_001BAAA0(&entry->position.x);
                func_001BB330(entry->turn + entry->angle);
                if (state->flags[entry->flag])
                    func_001BB2E0(entry->angleX);
                func_001BB380(entry->angleZ);
                if (effects->attached[i]) {
                    if (entry->motion < 0)
                        model->func_00047970(0, 0);
                    else
                        model->func_00047970(state->motions[entry->motion], entry->argument);
                    model->func_000480C0(effects->parts[i]);
                }
                memset(&vector, 0, sizeof(vector));
                func_001BAAA0(&effects->positions[i].x);
                func_001BAB20(&vector, 0);
                func_00060B10(entry->ids[i], &vector);
                func_001BAC00(&vector, &effects->directions[i]);
                func_00060B40(entry->ids[i], &vector);
                func_001BAA50();
            }
        } else {
            func_00060B10(entry->ids[i], &effects->positions[i]);
            func_00060B40(entry->ids[i], &effects->directions[i]);
        }
    }
}
