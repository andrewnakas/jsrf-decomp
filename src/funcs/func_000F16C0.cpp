struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *value);
    int func_000651E0(int kind, void *data, Vector3 *direction);
    void func_00060810(int key);
};

// The owner at 0x4: its position at 0x44.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
};

struct Item_00016200;
struct Model_000178B0;
struct Motion_0005F060;

struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_000178B0(Model_000178B0 *model, Motion_0005F060 *motion, float time);
};

extern Object_00016200 data_0022FCE8;

// The posed part at 0x78.
struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void func_001BB670(float angle);

extern unsigned int data_0021AFD0[4];
extern Vector3 data_0021B020[4];

// The model item at 0x164: its model comes first.
struct Body_000F1820 {
    Model_000178B0 *model;
};

// The state machine whose table is at 0x1CF02C (constructor func_000F1820), made by func_000F1FC0.
struct Object_000F1820 {
    void *vtable;
    Object_000C5B50 *owner;
    char unknown_008[0x3c];
    int keys_44[4];
    int keys_54[4];
    int keys_64[4];
    char unknown_074[4];
    Object_00047470 *part;
    char unknown_07c[8];
    void **motions;
    char unknown_088[0xdc];
    Body_000F1820 body;

    void func_000F16C0();
};

// Poses the part with motion 20 and puts the owner at the origin of its matrix 0 turned by -250; with object 0xe8,
// drops the keys at 0x44 and 0x54 (func_00060810) when the first of each is set, and moves the four effects at 0x64 to
// the points data_0021B020 on the part's matrices data_0021AFD0 (func_000606C0, or effect 0x34 when there is none).
// Then poses the model at 0x164 with motion 20 (func_000178B0) and queues it (func_00016240).
void Object_000F1820::func_000F16C0()
{
    func_001BA9C0();
    part->func_00047970(motions[20], 0);
    part->func_000480C0(0);
    func_001BA9C0();
    func_001BB670(-250.0f);
    func_001BAB20(&owner->position, 0);
    func_001BAA50();
    Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (target) {
        int i;
        if (keys_44[0]) {
            for (i = 0; i < 4; i++) {
                target->func_00060810(keys_44[i]);
                keys_44[i] = 0;
            }
        }
        if (keys_54[0]) {
            for (i = 0; i < 4; i++) {
                target->func_00060810(keys_54[i]);
                keys_54[i] = 0;
            }
        }
        Vector3 point;
        for (unsigned int j = 0; j < 4; j++) {
            part->func_000480C0(data_0021AFD0[j]);
            func_001BAB20(&point, &data_0021B020[j]);
            if (keys_64[j]) {
                target->func_000606C0(keys_64[j], &point);
            } else {
                keys_64[j] = target->func_000651E0(0x34, &point, 0);
            }
        }
    }
    func_001BAA50();
    data_0022FCE8.func_000178B0(body.model, (Motion_0005F060 *)motions[20], 0.0f);
    data_0022FCE8.func_00016240((Item_00016200 *)&body);
}
