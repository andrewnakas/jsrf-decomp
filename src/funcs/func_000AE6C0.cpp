/* sym: ??0Object_000AE970@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000AE6C0 */
/* sym: ??1Object_000AE970@@UAE@XZ = 0x000AE970 */
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
struct Shape_000AE6C0 {
    char unknown_00[0x60];
    float radius;
};

// A model from func_00025700 (6, bank, 2, key).
struct Model_000AE6C0 {
    int unknown_00[2];
    Shape_000AE6C0 *shape;
};

// A 0x40-byte model entry (bank 6, table 5 of group 0xb): two model keys, two more keys, an offset and a radius.
struct Entry_000AE6C0 {
    int keys[4];
    Vector3 offset;
    char unknown_1c[0x1c];
    float radius;
    int unknown_3c;
};

// The 0x24-byte block kept at 0x198.
struct Block_000AE6C0 {
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

void *func_00025700(unsigned int index, int first, int second, int third);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BB410(Vector3 *out);
void func_001BB9C0(int *angles, int unused);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD770).
struct Object_000AE970 : Node {
    Object_000AE970(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement);
    virtual ~Object_000AE970();

    int unknown_40;
    int unknown_44;
    Params_000BAC60 placement;
    Entry_000AE6C0 entry;
    int unknown_b0;
    int unknown_b4;
    int unknown_b8;
    int unknown_bc;
    int bank;
    Model_000AE6C0 *models[4];
    int unknown_d4;
    int unknown_d8;
    Vector3 position;
    int angles[3];
    int unknown_f4[3];
    int unknown_100[5];
    float scale[2];
    int alpha;
    char unknown_120[0x48];
    int unknown_168;
    int unknown_16c;
    float radius;
    char unknown_174[0x24];
    Block_000AE6C0 *buffer;
    int unknown_19c;
};

// Copies the placement and its bank-6 model entry, takes the world position and angles of the placed offset from
// the matrix stack and finds the four models; without a placement or either of the first two models the node leaves
// the draw links, otherwise it makes the block at 0x198 with the entry's radius (or the first model's).
Object_000AE970::Object_000AE970(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement)
    : Node(owner, id, flags)
{
    unknown_b8 = 0;
    unknown_bc = 1;
    models[0] = 0;
    models[1] = 0;
    models[2] = 0;
    models[3] = 0;
    unknown_b0 = -1;
    unknown_b4 = 0;
    unknown_d4 = 0;
    unknown_d8 = 0;
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
    Entry_000AE6C0 *entries = (Entry_000AE6C0 *)func_00025700(6, bank, 5, 0xb);
    entry = entries[index];
    func_001BAA00();
    func_001BAAA0(&this->placement.position.x);
    func_001BAC50(this->placement.angles, 0);
    func_001BAAA0(&entry.offset.x);
    float point[4];
    func_001BB410((Vector3 *)point);
    func_001BB9C0(angles, 0);
    func_001BAA50();
    position.x = point[0];
    position.y = point[1];
    position.z = point[2];
    unknown_100[0] = 0;
    unknown_100[1] = 0;
    unknown_100[2] = 0;
    unknown_100[3] = 0;
    unknown_100[4] = 0;
    scale[0] = 1.0f;
    scale[1] = 1.0f;
    unknown_16c = 0;
    unknown_168 = 0;
    unknown_44 = 0;
    alpha = 0xff;
    models[0] = (Model_000AE6C0 *)func_00025700(6, bank, 2, entry.keys[0]);
    models[1] = (Model_000AE6C0 *)func_00025700(6, bank, 2, entry.keys[1]);
    if (!models[0] || !models[1]) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    if (entry.radius == 0.0f) {
        radius = models[0]->shape->radius;
    } else {
        radius = entry.radius;
    }
    models[2] = (Model_000AE6C0 *)func_00025700(6, bank, 3, entry.keys[2]);
    models[3] = (Model_000AE6C0 *)func_00025700(6, bank, 3, entry.keys[3]);
    buffer = new Block_000AE6C0;
    buffer->kind = 3;
    buffer->unknown_20 = 0;
    buffer->radius = radius;
    unknown_19c = 1;
}
