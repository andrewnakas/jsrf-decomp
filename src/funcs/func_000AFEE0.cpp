/* sym: ??0Object_000B0190@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000AFEE0 */
/* sym: ??1Object_000B0190@@UAE@XZ = 0x000B0190 */
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
struct Shape_000AFEE0 {
    char unknown_00[0x60];
    float radius;
};

// A model from func_00025700 (6, bank, 2, key).
struct Model_000AFEE0 {
    int unknown_00[2];
    Shape_000AFEE0 *shape;
    int unknown_0c;
    int kind;
    char unknown_14[0x10];
    unsigned int flags;
};

// One of the entry's ten parts: a model key (table 2) and a second key (table 3), -1 when there is none.
struct Part_000AFEE0 {
    int model;
    int second;
    int unknown_08[2];
};

// A 0xb8-byte model entry (bank 6, table 5 of group 9).
struct Entry_000AFEE0 {
    unsigned int flags;
    int unknown_04[2];
    int handle;
    int unknown_10[2];
    Part_000AFEE0 parts[10];
};

// The 0x24-byte block kept at 0x268.
struct Block_000AFEE0 {
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

struct Object_00016200 {
    int func_0001D950(void *frame, int value);
};

extern Object_00016200 data_0022FCE8;

void *func_00025700(unsigned int index, int first, int second, int third);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD7F8).
struct Object_000B0190 : Node {
    Object_000B0190(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement);
    virtual ~Object_000B0190();

    int unknown_40;
    int unknown_44;
    Params_000BAC60 placement;
    Entry_000AFEE0 entry;
    int unknown_128;
    int unknown_12c;
    int unknown_130;
    int unknown_134;
    Model_000AFEE0 *model;
    Model_000AFEE0 *models[10];
    void *second;
    void *seconds[10];
    int unknown_190;
    int unknown_194;
    int unknown_198;
    int bank;
    int unknown_1a0;
    int unknown_1a4[3];
    int unknown_1b0[3];
    float scale[3];
    char unknown_1c8[0x18];
    int unknown_1e0[3];
    int alpha;
    char unknown_1f0[0x48];
    int unknown_238;
    int unknown_23c;
    float radius;
    char unknown_244[0x24];
    Block_000AFEE0 *buffer;
    int unknown_26c;
    char unknown_270[0x10];
    void *frame;
    int items[2];
};

// Copies the placement and its bank-6 model entry and finds the models and second models of its ten parts; with no
// placement or no first model the node leaves the draw links, otherwise it makes the block at 0x268 with the first
// model's radius and registers the entry's frame (table 4) with data_0022FCE8 when it has one.
Object_000B0190::Object_000B0190(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement)
    : Node(owner, id, flags)
{
    unknown_130 = 0;
    unknown_134 = 1;
    model = 0;
    second = 0;
    buffer = 0;
    unknown_128 = -1;
    unknown_12c = 0;
    for (int i = 0; i < 10; i++) {
        models[i] = 0;
        seconds[i] = 0;
    }
    unknown_198 = -1;
    unknown_194 = 0;
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
    Entry_000AFEE0 *entries = (Entry_000AFEE0 *)func_00025700(6, bank, 5, 9);
    entry = entries[index];
    for (int j = 0; j < 3; j++) {
        unknown_1b0[j] = 0;
        scale[j] = 1.0f;
    }
    unknown_1a4[0] = 0;
    unknown_1a4[1] = 0;
    unknown_1a4[2] = 0;
    unknown_1e0[0] = 0;
    unknown_1e0[1] = 0;
    unknown_1e0[2] = 0;
    unknown_23c = 0;
    unknown_238 = 0;
    unknown_44 = 0;
    alpha = 0xff;
    unknown_190 = 0;
    for (int k = 0; k < 10; k++) {
        if (entry.parts[k].model != -1) {
            models[k] = (Model_000AFEE0 *)func_00025700(6, bank, 2, entry.parts[k].model);
        }
        if (entry.parts[k].second != -1) {
            seconds[k] = func_00025700(6, bank, 3, entry.parts[k].second);
        }
    }
    model = models[0];
    second = seconds[0];
    if (model) {
        radius = model->shape->radius;
        if ((entry.flags & 0x40000000) && model->kind == 2) {
            model->flags &= ~8;
        }
        buffer = new Block_000AFEE0;
        buffer->kind = 3;
        buffer->unknown_20 = 0;
        buffer->radius = radius;
        unknown_26c = 1;
        if (entry.handle != -1) {
            frame = func_00025700(6, bank, 4, entry.handle);
            items[1] = items[0] = data_0022FCE8.func_0001D950(frame, -1);
        }
        return;
    }
    func_00011BE0(this);
    func_00011C20(child);
}
