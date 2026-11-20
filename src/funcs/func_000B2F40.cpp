/* sym: ??0Object_000B3200@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000B2F40 */
/* sym: ??1Object_000B3200@@UAE@XZ = 0x000B3200 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
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
struct Shape_000B2F40 {
    char unknown_00[0x60];
    float radius;
};

// A model from func_00025700 (6, bank, 2, key).
struct Model_000B2F40 {
    int unknown_00[2];
    Shape_000B2F40 *shape;
    int unknown_0c;
    int kind;
    char unknown_14[0x10];
    unsigned int flags;
};

// A model from func_00025700 (6, bank, 3, key); a count at 2.
struct Second_000B2F40 {
    short unknown_00;
    short count;
};

// A 0x38-byte model entry (bank 6, table 5 of group 0xd).
struct Entry_000B2F40 {
    int model;
    int second;
    int third;
    int unknown_0c[4];
    unsigned int flags;
    int unknown_20[3];
    float radius;
    int unknown_30[2];
};

// The 0x24-byte block kept at 0x204.
struct Block_000B2F40 {
    char unknown_00[0xc];
    float radius;
    char unknown_10[0xc];
    int kind;
    int unknown_20;
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

struct Object_00066980 {
    unsigned int value;

    float func_00066950();
};

extern Object_00066980 data_00257C80;

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD878).
struct Object_000B3200 : Node {
    Object_000B3200(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement);
    virtual ~Object_000B3200();

    int unknown_40;
    unsigned int state;
    int unknown_48;
    int unknown_4c;
    int unknown_50;
    int unknown_54;
    Params_000BAC60 placement;
    Entry_000B2F40 entry;
    int unknown_b8;
    int unknown_bc;
    int bank;
    int unknown_c4;
    Model_000B2F40 *model;
    Second_000B2F40 *current;
    Second_000B2F40 *second;
    Second_000B2F40 *third;
    int block;
    float offset;
    int unknown_e0;
    int unknown_e4;
    int unknown_e8[3];
    int unknown_f4[3];
    int unknown_100[3];
    float scale[3];
    char unknown_118[0x18];
    int unknown_130[3];
    float radius;
    int alpha;
    char unknown_144[0xc0];
    Block_000B2F40 *buffer;
    int unknown_208;
};

// Copies the placement and its bank-6 model entry and finds its model; with no placement or no model the node leaves
// the draw links. With a second model the node takes a random offset within its count when bit 31 of the
// entry's flags (0x1c) is set, a third model and a block from func_0005E790; without one it sets state bit 0x40000000.
Object_000B3200::Object_000B3200(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement)
    : Node(owner, id, flags)
{
    if (!placement) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    this->placement = *placement;
    unsigned int group = placement->model >> 10;
    if (group < 5) {
        bank = group + 1;
    } else {
        bank = 0;
    }
    unsigned int index = placement->model - (group << 10);
    Entry_000B2F40 *entries = (Entry_000B2F40 *)func_00025700(6, bank, 5, 0xd);
    entry = entries[index];
    unknown_50 = 0;
    unknown_54 = 1;
    model = 0;
    current = 0;
    second = 0;
    third = 0;
    block = 0;
    buffer = 0;
    unknown_b8 = -1;
    unknown_bc = 0;
    offset = 0;
    unknown_e0 = 0;
    unknown_e4 = 0;
    for (int j = 0; j < 3; j++) {
        unknown_100[j] = 0;
        scale[j] = 1.0f;
    }
    unknown_f4[0] = 0;
    unknown_f4[1] = 0;
    unknown_f4[2] = 0;
    unknown_130[0] = 0;
    unknown_130[1] = 0;
    unknown_130[2] = 0;
    unknown_4c = 0;
    unknown_48 = 0;
    state = 0;
    alpha = 0xff;
    radius = 0;
    unknown_c4 = -1;
    model = (Model_000B2F40 *)func_00025700(6, bank, 2, entry.model);
    if (model) {
        radius = model->shape->radius;
        if (entry.second != -1) {
            second = (Second_000B2F40 *)func_00025700(6, bank, 3, entry.second);
            if (entry.flags & 0x80000000) {
                float random = data_00257C80.func_00066950();
                offset = second->count * random;
            }
            if (entry.third != -1) {
                third = (Second_000B2F40 *)func_00025700(6, bank, 3, entry.third);
            }
            block = func_0005E790(second, 1);
            current = second;
        } else {
            state |= 0x40000000;
        }
        buffer = new Block_000B2F40;
        buffer->kind = 3;
        buffer->unknown_20 = 0;
        buffer->radius = entry.radius;
        unknown_208 = 1;
        state |= 0x10000000;
        return;
    }
    func_00011BE0(this);
    func_00011C20(child);
}
