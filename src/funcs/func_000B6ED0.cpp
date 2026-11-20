struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

struct Model_000178B0;
struct Motion_0005F060;

struct Item_00016200 {
    char unknown_00[4];
};

struct Object_00016200 {
    void func_0001D940(void **list);
    void func_00016240(Item_00016200 *item);
    void func_000178B0(Model_000178B0 *model, Motion_0005F060 *motion, float time);
};

extern Object_00016200 data_0022FCE8;

struct Object_0006A960 {
    int func_0006AAA0(Vector3 *position, int index);
    float func_0006AC40(Vector3 *position, int index);
};

extern Object_0006A960 data_0020C6C0;

struct Object_00047470 {
    virtual ~Object_00047470();

    void *surface;
    void *frames;
    char unknown_0c[0x4];
    int mode;
    char unknown_14[0x8];
    unsigned int count;
    Matrix_001BA950 *matrices;

    void func_00047970(void *data, int argument);
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BB270(float *scale);
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);

// Animation data: the number of frames at +0x2.
struct Animation_000B6ED0 {
    short unknown_0;
    short count;
};

// One of the node's entries (0x248 bytes).
struct Entry_000B5CC0 {
    int used;
    char unknown_004[8];
    int state;
    int kind;
    char unknown_014[0x18];
    float scale[3];
    char unknown_038[0xc];
    int sound;
    char unknown_048[0x6c];
    int cell;
    float height;
    char unknown_0bc[4];
    Vector3 position;
    int angles[3];
    char unknown_0d8[0x18];
    Object_00047470 *object;
    char unknown_0f4[0x50];
    Motion_0005F060 *motion;
    float time;
    char unknown_14c[4];
    Animation_000B6ED0 *animations[2];
    float frames[2];
    int frame;
    char unknown_164[4];
    float speeds[2];
    char unknown_170[0xc8];
    int registered;
    Model_000178B0 *model;
    Item_00016200 item;
    char unknown_244[4];
};

// One of 17 direct children of Node that share slots 4, 6, 12 and 15 (table 0x1CD910).
struct Object_000B5CC0 {
    char unknown_000[0x44];
    Entry_000B5CC0 *entries;
    unsigned int count;

    void func_000B6ED0(int index);
};

// The handler of kind-1 entries (data_00215D60): keeps the first animation's frame at 0x160 and the second's at
// 0x148. State 0 clears 0x148, moves to state 3 and, with a sound (0x44) and once registered (0x238), hands the
// model at 0x23c to data_0022FCE8 twice under the entry's matrix; then takes the cell and height of the position from
// data_0020C6C0. In state 3 (and after state 0) both frames run on by their speeds and wrap to 0 at their animation's
// last frame. Every frame: poses the object at 0xf0 with the first animation, draws the model with the motion at
// 0x144 (func_000178B0) under the entry's matrix, and hands the item at 0x240 to data_0022FCE8.
void Object_000B5CC0::func_000B6ED0(int index)
{
    entries[index].frame = *(int *)&entries[index].frames[0];
    entries[index].time = entries[index].frames[1];
    switch (entries[index].state) {
    case 0:
        entries[index].time = 0.0f;
        entries[index].state = 3;
        if (entries[index].sound != -1 && entries[index].registered) {
            func_001BAA00();
            func_001BAAA0(&entries[index].position.x);
            func_001BAC50(entries[index].angles, 0);
            func_001BB270(entries[index].scale);
            data_0022FCE8.func_0001D940((void **)entries[index].model);
            data_0022FCE8.func_0001D940((void **)entries[index].model);
            func_001BAA50();
        }
        entries[index].cell = data_0020C6C0.func_0006AAA0(&entries[index].position, entries[index].cell);
        entries[index].height = data_0020C6C0.func_0006AC40(&entries[index].position, entries[index].cell);
    case 3:
        for (int i = 0; i < 2; i++) {
            entries[index].frames[i] += entries[index].speeds[i];
            if (entries[index].frames[i] >= entries[index].animations[i]->count - 1.0f) {
                entries[index].frames[i] = 0.0f;
            }
        }
        break;
    }
    func_001BAA00();
    func_001BAAA0(&entries[index].position.x);
    func_001BAC50(entries[index].angles, 0);
    func_001BB270(entries[index].scale);
    entries[index].object->func_00047970(entries[index].animations[0], entries[index].frame);
    func_001BA8F0(entries[index].object->matrices);
    data_0022FCE8.func_000178B0(entries[index].model, entries[index].motion, entries[index].time);
    func_001BAA50();
    data_0022FCE8.func_00016240(&entries[index].item);
}
