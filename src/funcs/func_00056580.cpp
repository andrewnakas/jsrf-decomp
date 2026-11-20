struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Node {
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

// Object 0x12ac (destructor 0x4FBC0).
struct Object_0004FC40 {
    void func_00055A80(int value);
};

struct Stage_00056540 {
    char unknown_00[0x14];
    int unknown_14;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0xf58];
    Stage_00056540 *stage;
    char unknown_fbc[0x2c];
    int skipped;
    int fading;

    void func_0004D880();
    void func_00056580();
};

// A state handler: takes objects 0x12ad and 0x12ae out, hands the stage's word at +0x14 to func_00055A80 of object
// 0x12ac when it is there, runs func_0004D880, clears +0xfe8 and +0xfec and goes to state 0x3f.
void Object_0004ABA0::func_00056580()
{
    Node *node = (Node *)data_0022FCE0->func_000128C0(0x12ad);
    if (node) {
        node->func_00011BE0(node);
        node->func_00011C20(node->child);
    }
    node = (Node *)data_0022FCE0->func_000128C0(0x12ae);
    if (node) {
        node->func_00011BE0(node);
        node->func_00011C20(node->child);
    }
    Object_0004FC40 *object = (Object_0004FC40 *)data_0022FCE0->func_000128C0(0x12ac);
    if (object) {
        object->func_00055A80(stage->unknown_14);
    }
    func_0004D880();
    skipped = 0;
    fading = 0;
    state = 0x3f;
}
