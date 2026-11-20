/* sym: ??0Object_000AE220@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000ADE90 */
/* sym: ??1Object_000AE220@@UAE@XZ = 0x000AE220 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Object_00015D50@@QAE@PAX@Z = 0x00015420 */
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
struct Shape_000ADE90 {
    char unknown_00[0x60];
    float radius;
};

// A model from func_00025700 (6, bank, 2, key); bit 3 of the flags at 0x24 is cleared once the part is made.
struct Model_000ADE90 {
    int unknown_00[2];
    Shape_000ADE90 *shape;
    char unknown_0c[0x18];
    unsigned int flags;
};

// A 0x68-byte entry (bank 6, table 5 of group 0x11): a model key, a radius, an offset and turn (degrees), and the
// settings handed to the part.
struct Entry_000ADE90 {
    int unknown_00;
    int key;
    char unknown_08[0xc];
    float radius;
    Vector3 offset;
    Vector3 turn;
    float part_04;
    float part_08;
    float part_0c;
    float part_10;
    int part_14;
    int unknown_44;
    int part_18;
    int part_1c;
    int part_20;
    int unknown_54;
    int part_28;
    int part_2c;
    int part_30;
    int unknown_64;
};

// The 0x24-byte block kept at 0x1bc.
struct Block_000ADE90 {
    char unknown_00[0xc];
    float radius;
    char unknown_10[0xc];
    int kind;
    int unknown_20;
};

// The 0x118-byte part made for the model (constructor 0x15420).
struct Object_00015D50 {
    Object_00015D50(void *owner);
    virtual ~Object_00015D50();

    float unknown_04;
    float unknown_08;
    float unknown_0c;
    float unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    int unknown_24;
    int unknown_28;
    int unknown_2c;
    int unknown_30;
    int unknown_34;
    char unknown_38[0xe0];

    void func_00015480();
    void func_00015D90();
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
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BB410(Vector3 *out);
void func_001BB9C0(int *angles, int unused);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD730).
struct Object_000AE220 : Node {
    Object_000AE220(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement);
    virtual ~Object_000AE220();

    int unknown_40;
    int unknown_44;
    Params_000BAC60 placement;
    Entry_000ADE90 entry;
    int key;
    int value_dc;
    int seen;
    int value_e4;
    int bank;
    int unknown_ec;
    Model_000ADE90 *model;
    Object_00015D50 *part;
    Vector3 position;
    int angles[3];
    char unknown_110[0x30];
    int alpha;
    char unknown_144[0x48];
    int unknown_18c;
    int unknown_190;
    float radius;
    char unknown_198[0x24];
    Block_000ADE90 *buffer;
    int unknown_1c0;
};

// Copies the placement and its bank-6 entry, takes the world position of the placed offset (turned by the entry's
// angles) from the matrix stack and finds the model; with a model it takes the radius, makes the part (0x15420) with
// the entry's settings and the block at 0x1bc, otherwise the node leaves the draw links.
Object_000AE220::Object_000AE220(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement)
    : Node(owner, id, flags)
{
    seen = 0;
    value_e4 = 1;
    model = 0;
    part = 0;
    buffer = 0;
    key = -1;
    value_dc = 0;
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
    Entry_000ADE90 *entries = (Entry_000ADE90 *)func_00025700(6, bank, 5, 0x11);
    entry = entries[index];
    func_001BAA00();
    func_001BAAA0(&this->placement.position.x);
    func_001BAC50(this->placement.angles, 0);
    func_001BAAA0(&entry.offset.x);
    func_001BB2E0((int)(entry.turn.x * 182.04445f));
    func_001BB330((int)(entry.turn.y * 182.04445f));
    func_001BB380((int)(entry.turn.z * 182.04445f));
    float point[4];
    func_001BB410((Vector3 *)point);
    func_001BB9C0(angles, 0);
    func_001BAA50();
    position.x = point[0];
    position.y = point[1];
    position.z = point[2];
    unknown_190 = 0;
    unknown_18c = 0;
    unknown_44 = 0;
    alpha = 0xff;
    unknown_ec = -1;
    model = (Model_000ADE90 *)func_00025700(6, bank, 2, entry.key);
    if (model) {
        if (entry.radius > 0.0f) {
            radius = entry.radius;
        } else {
            radius = model->shape->radius;
        }
        part = new Object_00015D50(model);
        if (part) {
            part->func_00015D90();
            part->unknown_04 = entry.part_04;
            part->unknown_08 = entry.part_08;
            part->unknown_0c = entry.part_0c;
            part->unknown_14 = entry.part_14;
            part->unknown_18 = entry.part_18;
            part->unknown_1c = entry.part_1c;
            part->unknown_20 = entry.part_20;
            part->unknown_24 = 0;
            part->unknown_28 = entry.part_28;
            part->unknown_2c = entry.part_2c;
            part->unknown_30 = entry.part_30;
            part->unknown_34 = 0;
            part->unknown_10 = entry.part_10;
            part->func_00015480();
        }
        model->flags &= ~8;
        buffer = new Block_000ADE90;
        buffer->kind = 3;
        buffer->unknown_20 = 0;
        buffer->radius = radius;
        unknown_1c0 = 1;
    } else {
        func_00011BE0(this);
        func_00011C20(child);
    }
}
