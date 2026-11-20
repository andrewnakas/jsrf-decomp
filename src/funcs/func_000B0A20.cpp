/* sym: ??0Object_000B1130@@QAE@PAUNode@@HIPAUParams_000BAC60@@I@Z = 0x000B0A20 */
/* sym: ??1Object_000B1130@@UAE@XZ = 0x000B1130 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* const: 0x200010 */
/* const: 0x200000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// Where func_000BAC60 places the object: position, angles, scale and a model code (bank << 10 | index).
struct Params_000BAC60 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    unsigned int model;
};

// The shape a model points at; its radius is at 0x60.
struct Shape_000B0A20 {
    char unknown_00[0x60];
    float radius;
};

// A model from func_00025700 (6, bank, 2, key).
struct Model_000B0A20 {
    int unknown_00[2];
    Shape_000B0A20 *shape;
};

// A 0x38-byte record (bank 6, table 5 of group 4): flags (bit 0 and 1 pick the kind, bit 0x200000 an extra model),
// the model keys, a radius, the item key (or -1), an offset and turn (degrees).
struct Data_000B0A20 {
    unsigned int flags;
    unsigned int modelKey;
    int key3;
    float radius;
    int itemKey;
    int extraKey;
    Vector3 offset;
    Vector3 turn;
    int unknown_30;
    int key3b;
};

// The 0x24-byte block kept at 0x178.
struct Block_000B0A20 {
    char unknown_00[0xc];
    float radius;
    char unknown_10[0xc];
    int kind;
    int unknown_20;
};

// The 0x74-byte block kept at 0x1b8 with an extra model.
struct First_000B0A20 {
    char unknown_00[0x6c];
    int kind;
    int unknown_70;
};

// One of the node's entries (0x1e0 bytes).
struct Entry_000B0A20 {
    int used;
    int kind;
    int unknown_008;
    Params_000BAC60 placement;
    Data_000B0A20 data;
    int key;
    int value_070;
    int visible;
    int dirty;
    int unknown_07c;
    int bank;
    int unknown_084;
    float factor;
    Model_000B0A20 *model;
    void *value_090;
    void *model3;
    int value_098;
    void *model3b;
    int unknown_0a0;
    void *value_0a4;
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_0cc[0x18];
    int unknown_0e4;
    int unknown_0e8;
    int unknown_0ec;
    int posed;
    int alpha;
    char unknown_0f8[0x48];
    int unknown_140;
    int phase;
    float radius;
    unsigned int keyCount;
    int *keys;
    char unknown_154[0x24];
    Block_000B0A20 *block;
    int unknown_17c;
    char unknown_180[0x10];
    void *extra;
    char unknown_194[0x24];
    First_000B0A20 *first;
    int unknown_1bc;
    char unknown_1c0[0x10];
    void *item;
    int handle;
    int handle2;
    int unknown_1dc;
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
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
    char unknown_34[0xc];

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

void *__cdecl operator new(unsigned int size);

struct Object_00016200 {
    int func_0001D810(void *list, int index);
    int func_0001D950(void *source, int id);
};

extern Object_00016200 data_0022FCE8;

extern "C" void *memset(void *destination, int value, unsigned int size);

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);
int func_000BA890(unsigned int key);
void func_001BA9C0();
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BB410(Vector3 *out);
void func_001BB9C0(int *angles, int unused);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD838).
struct Object_000B1130 : Node {
    Object_000B1130(Node *owner, int id, unsigned int flags, Params_000BAC60 *placements, unsigned int count);
    virtual ~Object_000B1130();

    int unknown_40;
    Entry_000B0A20 *entries;
    unsigned int count;
};

// Makes an entry per placement: with flag 8, a placement whose model func_000BA890 accepts gets a node of its own
// (flags 0x200010) instead; otherwise the entry copies the placement and its bank-6 record, takes its world position
// and angles from the matrix stack, finds its models, makes its block (0x1b8 with an extra model, else 0x178),
// registers its item and, for model 0xC45, the eight keys 0xC07 on.
Object_000B1130::Object_000B1130(Node *owner, int id, unsigned int flags, Params_000BAC60 *placements,
                                 unsigned int count)
    : Node(owner, id, flags)
{
    if (!placements) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    entries = 0;
    this->count = count;
    entries = (Entry_000B0A20 *)operator new(count * sizeof(Entry_000B0A20));
    if (!entries) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    memset(entries, 0, count * sizeof(Entry_000B0A20));
    for (unsigned int i = 0; i < count; i++) {
        entries[i].placement = placements[i];
        unsigned int group = placements[i].model >> 10;
        if (group < 5) {
            entries[i].bank = group + 1;
        } else {
            entries[i].bank = 0;
        }
        unsigned int index = placements[i].model - (group << 10);
        Data_000B0A20 *records = (Data_000B0A20 *)func_00025700(6, entries[i].bank, 5, 4);
        entries[i].data = records[index];
        if ((flags & 8) && func_000BA890(entries[i].data.modelKey)) {
            entries[i].used = 0;
            new Object_000B1130(this, -1, 0x200010, &placements[i], 1);
            continue;
        }
        entries[i].used = 1;
        entries[i].kind = 0;
        if (entries[i].data.flags & 1) {
            entries[i].kind = 1;
        } else if (entries[i].data.flags & 2) {
            entries[i].kind = 2;
        }
        entries[i].visible = 0;
        entries[i].unknown_07c = 1;
        entries[i].dirty = 1;
        entries[i].model = 0;
        entries[i].value_090 = 0;
        entries[i].model3 = 0;
        entries[i].model3b = 0;
        entries[i].value_0a4 = 0;
        entries[i].block = 0;
        entries[i].first = 0;
        entries[i].key = -1;
        entries[i].value_070 = 0;
        entries[i].value_098 = 0;
        entries[i].unknown_0a0 = 0;
        func_001BAA00();
        func_001BAAA0(&entries[i].placement.position.x);
        func_001BAC50(entries[i].placement.angles, 0);
        func_001BAAA0(&entries[i].data.offset.x);
        func_001BB2E0((int)(entries[i].data.turn.x * 182.04445f));
        func_001BB330((int)(entries[i].data.turn.y * 182.04445f));
        func_001BB380((int)(entries[i].data.turn.z * 182.04445f));
        float point[4];
        func_001BB410((Vector3 *)point);
        func_001BB9C0(entries[i].angles, 0);
        func_001BAA50();
        entries[i].position.x = point[0];
        entries[i].position.y = point[1];
        entries[i].position.z = point[2];
        entries[i].posed = 0;
        entries[i].unknown_0e4 = 0;
        entries[i].unknown_0e8 = 0;
        entries[i].unknown_0ec = 0;
        entries[i].unknown_084 = -1;
        entries[i].phase = 0;
        entries[i].unknown_140 = 0;
        entries[i].unknown_008 = 0;
        entries[i].alpha = 0xff;
        if (entries[i].data.modelKey >= 0x812 && entries[i].data.modelKey <= 0x813) {
            entries[i].factor = 0.5f;
        } else {
            entries[i].factor = 1.0f;
        }
        entries[i].model = (Model_000B0A20 *)func_00025700(6, entries[i].bank, 2, entries[i].data.modelKey);
        if (entries[i].model) {
            if (entries[i].data.radius == 0.0f) {
                entries[i].radius = entries[i].model->shape->radius;
            } else {
                entries[i].radius = entries[i].data.radius;
            }
        } else {
            entries[i].phase = 10;
        }
        entries[i].model3 = func_00025700(6, entries[i].bank, 3, entries[i].data.key3);
        switch (entries[i].kind) {
        case 1:
            entries[i].model3b = func_00025700(6, entries[i].bank, 3, entries[i].data.key3b);
            entries[i].value_0a4 = (void *)func_0005E790(entries[i].model3, 1);
            entries[i].value_090 = entries[i].value_0a4;
            break;
        case 2:
            entries[i].model3b = func_00025700(6, entries[i].bank, 3, entries[i].data.key3b);
            entries[i].value_090 = entries[i].model3;
            break;
        default:
            entries[i].value_090 = entries[i].model3;
            break;
        }
        if (entries[i].data.flags & 0x200000) {
            entries[i].extra = func_00025700(6, entries[i].bank, 7, entries[i].data.extraKey);
            entries[i].first = new First_000B0A20;
            entries[i].first->kind = 3;
            entries[i].first->unknown_70 = 0;
            entries[i].unknown_1bc = 1;
        } else {
            entries[i].block = new Block_000B0A20;
            entries[i].block->kind = 3;
            entries[i].block->unknown_20 = 0;
            entries[i].block->radius = entries[i].radius;
            entries[i].unknown_17c = 1;
        }
        if (entries[i].data.itemKey != -1) {
            entries[i].item = func_00025700(6, entries[i].bank, 4, entries[i].data.itemKey);
            if (entries[i].item) {
                entries[i].handle = data_0022FCE8.func_0001D950(entries[i].item, -1);
                entries[i].handle2 = entries[i].handle;
            }
        }
        entries[i].keyCount = 0;
        entries[i].keys = 0;
        func_001BA9C0();
        func_001BAAA0(&entries[i].position.x);
        func_001BAC50(entries[i].angles, 0);
        if (entries[i].data.modelKey == 0xc45) {
            entries[i].keyCount = 8;
            entries[i].keys = (int *)operator new(entries[i].keyCount * 4);
            for (unsigned int k = 0; k < entries[i].keyCount; k++) {
                void *list = func_00025700(6, entries[i].bank, 6, k + 0xc07);
                entries[i].keys[k] = data_0022FCE8.func_0001D810(list, -1);
            }
        }
        func_001BAA50();
    }
}
