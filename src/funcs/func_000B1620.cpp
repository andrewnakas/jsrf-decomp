struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BB270(float *scale);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BADB0(Vector3 *vector);
void func_001BAA00();
void func_001BB460();

// The model of an entry: its matrix at 0x20.
struct Model_00101A70 {
    char unknown_00[0x20];
    Matrix_001BA950 *matrix;
};

unsigned int func_000B9B50(Model_00101A70 *model, float *time);

struct Object_00047470 {
    void func_00047970(void *data, int value);
};

// One of the node's entries (0x1e0 bytes).
struct Entry_000B1620 {
    int unknown_000;
    int kind;
    char unknown_008[0x70];
    int dirty;
    char unknown_07c[0x10];
    Model_00101A70 *model;
    void *data;
    int unknown_094;
    int value_098;
    char unknown_09c[0xc];
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_0cc[0x24];
    int yaw;
    char unknown_0f4[4];
    Matrix_001BA950 matrix;
    unsigned int state;
    float time;
    char unknown_140[0xa0];
};

struct Node {
    virtual ~Node();

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD838).
struct Object_000B1130 : Node {
    char unknown_040[4];
    Entry_000B1620 *entries;
    unsigned int count;

    void func_000B1620(unsigned int index);
};

// Builds entry `index`'s frame from its position, angles, yaw (0xf0) and scale and poses its model (func_00047970 with
// the words at 0x90 and 0x98), keeping the model's state; then builds a yawed frame from the model's matrix, moves
// to its origin and keeps it as the entry's matrix. The state at 0x138 comes from func_000B9B50 with the time at
// 0x13c; when either state is 0 or 1 the entry is marked at 0x78.
void Object_000B1130::func_000B1620(unsigned int index)
{
    func_001BA9C0();
    func_001BAAA0(&entries[index].position.x);
    func_001BAC50(entries[index].angles, 0);
    func_001BB330(entries[index].yaw);
    func_001BB270(&entries[index].scale.x);
    unsigned int first = func_000B9B50(entries[index].model, &entries[index].time);
    ((Object_00047470 *)entries[index].model)->func_00047970(entries[index].data, entries[index].value_098);
    func_001BAA50();
    func_001BA9C0();
    func_001BA8F0(entries[index].model->matrix);
    func_001BAA00();
    func_001BB330(entries[index].yaw);
    func_001BB460();
    Matrix_001BA950 frame;
    func_001BA950(&frame);
    func_001BAA50();
    func_001BADB0((Vector3 *)&frame);
    func_001BA950(&entries[index].matrix);
    entries[index].state = func_000B9B50(entries[index].model, &entries[index].time);
    if (entries[index].state == 0 || entries[index].state == 1 || first == 0 || first == 1) {
        entries[index].dirty = 1;
    }
    func_001BAA50();
}
