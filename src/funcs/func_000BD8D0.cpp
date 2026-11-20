/* sym: ??0Object_000BDAE0@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000BD8D0 */
/* sym: ??1Object_000BDAE0@@UAE@XZ = 0x000BDAE0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000BDAE0@@UAEXXZ = 0x000BDBA0 */
/* sym: ?func_00011C90_1@Object_000BDAE0@@UAEXXZ = 0x000BDE30 */
/* sym: ?func_00011C80@Object_000BDAE0@@UAEXH@Z = 0x000BDFD0 */
/* sym: ?func_00011C90_2@Object_000BDAE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000BDAE0@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000BDAE0@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000BDAE0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000BDAE0@@UAEXH@Z = 0x000B3DE0 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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

// One entry (0x20 bytes) of the table func_00025700(6, bank, 5, 8).
struct Entry_000BD8D0 {
    unsigned int flags;
    int model;
    int kind;
    int handle;
    int unknown_10[2];
    float radius;
    int unknown_1c;
};

// The collision part (0x24 bytes).
struct Part_000BD8D0 {
    Vector3 center;
    float radius;
    Vector3 motion;
    int kind;
    int value_20;
};

// The shape a model points at; its radius is at 0x60.
struct Shape_000BD8D0 {
    char unknown_00[0x60];
    float radius;
};

// A model from func_00025700 (6, bank, 2, key).
struct Model_000BD8D0 {
    int unknown_00[2];
    Shape_000BD8D0 *shape;
};

struct Object_00016200 {
    int func_0001D950(void *resource, int index);
};

extern Object_00016200 data_0022FCE8;

void *func_00025700(unsigned int index, int first, int second, int third);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDAE0).
struct Object_000BDAE0 : Node {
    Object_000BDAE0(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement);
    virtual ~Object_000BDAE0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    int value_44;
    Params_000BAC60 placement;
    Entry_000BD8D0 entry;
    int key;
    float value_94;
    int seen;
    int posed;
    Model_000BD8D0 *model;
    int value_a4;
    int value_a8;
    int first;
    int second;
    Vector3 placedPosition;
    int placedAngles[3];
    float placedScale[3];
    char unknown_0d8[0x18];
    Vector3 motion;
    int value_fc;
    char unknown_100[0x48];
    int value_148;
    int phase;
    float radius;
    char unknown_154[0x24];
    Part_000BD8D0 *part;
    int partCount;
    char unknown_180[0x10];
    void *resource;
    int shadow;
    int shadowItem;
};

// Builds the node; without a placement it only runs func_00011BE0 and func_00011C20 (the child at 0x28). Otherwise
// keeps the placement at 0x48 and the entry of its model code (bank = code >> 10 plus 1 below 5, else 0) at 0x70,
// places itself at the origin with no turn and scale 1, and loads its model (radius from its shape, phase 10 without
// one), a collision part with the entry's radius, and the shadow model at 0x190 for the entry's handle
// (func_0001D950, kept at 0x194 and 0x198).
Object_000BDAE0::Object_000BDAE0(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement)
    : Node(owner, id, flags)
{
    first = -1;
    second = -1;
    key = -1;
    seen = 0;
    posed = 1;
    model = 0;
    value_a4 = 0;
    part = 0;
    value_94 = 0.0f;
    value_a8 = 0;
    if (!placement) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    this->placement = *placement;
    unsigned int group = placement->model >> 10;
    int bank;
    if (group < 5) {
        bank = group + 1;
    } else {
        bank = 0;
    }
    unsigned int index = placement->model - (group << 10);
    Entry_000BD8D0 *entries = (Entry_000BD8D0 *)func_00025700(6, bank, 5, 8);
    entry = entries[index];
    for (int i = 0; i < 3; i++) {
        placedAngles[i] = 0;
        placedScale[i] = 1.0f;
    }
    placedPosition.x = 0.0f;
    placedPosition.y = 0.0f;
    placedPosition.z = 0.0f;
    motion.x = 0.0f;
    motion.y = 0.0f;
    motion.z = 0.0f;
    phase = 0;
    value_148 = 0;
    value_44 = 0;
    value_fc = 0xff;
    if (entry.model != -1) {
        model = (Model_000BD8D0 *)func_00025700(6, bank, 2, entry.model);
        if (model) {
            radius = model->shape->radius;
        } else {
            phase = 10;
        }
    }
    part = new Part_000BD8D0;
    part->kind = 3;
    part->value_20 = 0;
    part->radius = entry.radius;
    partCount = 1;
    if (entry.handle != -1) {
        resource = func_00025700(6, bank, 4, entry.handle);
        shadow = data_0022FCE8.func_0001D950(resource, -1);
        shadowItem = shadow;
    }
}
