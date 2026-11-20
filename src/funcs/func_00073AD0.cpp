/* sym: ??1Object_00073AD0@@UAE@XZ = 0x00073AD0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void func_00118870(int value);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object 0x1163.
struct Object_000FEDB0 {
    void func_000FEF40(int id, int value);
    void func_000FEFE0(int id, int value);
};

struct Object_00107FE0 {
    char unknown_0000[0x1700];
    unsigned int flags;

    void func_001077C0(int index);
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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
    char unknown_34[0x10];
};

// The node class whose table is at 0x1CCB68 (constructor 0x73500, made by 0x109300).
struct Object_00073AD0 : Node {
    virtual ~Object_00073AD0();

    unsigned int state;
    unsigned int mode;
    char unknown_4c[0x58];
    int unknown_a4;
    int children[2];
    char unknown_b0[8];
    int owner;

    // func_00072BA0, inlined here.
    void func_00072BA0()
    {
        if (!(state & 0x20000000)) {
            Object_000FEDB0 *object = (Object_000FEDB0 *)data_0022FCE0->func_000128C0(0x1163);
            if (object) {
                object->func_000FEF40(id, unknown_a4);
                object->func_000FEFE0(id, unknown_a4);
                state |= 0x20000000;
            }
        }
    }
};

// Unless bit 30 of +0x44 is set, has the object whose id is at +0xb8 run func_001077C0 (0x12) and sets bit 31 of its
// +0x1700; takes out node 0x1164 and the two nodes whose ids are at +0xa8; with bit 15 of +0x48 runs func_00072BA0;
// passes 0 to func_00118870.
Object_00073AD0::~Object_00073AD0()
{
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(owner);
    if (object && !(state & 0x40000000)) {
        object->func_001077C0(0x12);
        object->flags |= 0x80000000;
    }
    Node *node = (Node *)data_0022FCE0->func_000128C0(0x1164);
    if (node) {
        node->func_00011BE0(node);
        node->func_00011C20(node->child);
    }
    for (unsigned int i = 0; i < 2; i++) {
        if (children[i]) {
            Node *child = (Node *)data_0022FCE0->func_000128C0(children[i]);
            if (child) {
                child->func_00011BE0(child);
                child->func_00011C20(child->child);
            }
        }
    }
    if (mode & 0x8000) {
        func_00072BA0();
    }
    func_00118870(0);
}
