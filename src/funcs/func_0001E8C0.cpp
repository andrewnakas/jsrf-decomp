void func_001169B0(int a, int b, float c, unsigned int d);
void func_00060BA0(int id);
void func_000FE550(int index);

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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
    char unknown_34[0x10];
};

struct Game {
    void func_000126F0(int value);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    void func_0003A890(unsigned int value);
};

extern Object_00039BE0 data_001EFFB0;

// What +0x8 of an entry points at: the number of ids at +0xf8.
struct Info_0001E8C0 {
    char unknown_000[0xf8];
    unsigned int count;
};

struct Entry_0001E8C0 {
    char unknown_00[0x8];
    Info_0001E8C0 *info;
    char unknown_0c[0x40];
    int *ids;
    void *block;
};

// The block at +0xdc.
struct State_0001E8C0 {
    unsigned int unknown_000;
    char unknown_004[0x4];
    int index;
    char unknown_00c[0xc];
    unsigned int count;
    char unknown_01c[0xcc];
    int unknown_0e8[0x24];
    int unknown_178;
};

// Node child with the table at 0x1C4BA8.
struct Object_00022990 : Node {
    virtual ~Object_00022990();

    char unknown_44[0x78];
    void *unknown_bc;
    void *unknown_c0;
    char unknown_c4[0x18];
    State_0001E8C0 *state;
    Entry_0001E8C0 **entries;

    void func_0001E8C0();
};

// Called by func_00023790 at the end: passes the block's first word to data_001EFFB0's func_0003A890, runs
// func_001169B0 (0, 0, 1.0, 60), releases the positive ids of every entry (func_00060BA0), frees each entry's two
// blocks, runs func_000126F0 (0) and func_000FE550 (5), frees +0xc0 and +0xbc, and kills object 0x1164 (unless the
// block's current slot is set and +0x178 is clear), itself and object 0x1ddb with everything below them.
void Object_00022990::func_0001E8C0()
{
    data_001EFFB0.func_0003A890(state->unknown_000);
    func_001169B0(0, 0, 1.0f, 0x3c);
    unsigned int i;
    for (i = 0; i < state->count; i++) {
        for (unsigned int j = 0; j < entries[i]->info->count; j++) {
            int id = entries[i]->ids[j];
            if (id > 0) {
                func_00060BA0(id);
            }
        }
    }
    for (i = 0; i < state->count; i++) {
        if (entries[i]->block) {
            delete entries[i]->block;
        }
        if (entries[i]->ids) {
            delete entries[i]->ids;
        }
    }
    data_0022FCE0->func_000126F0(0);
    func_000FE550(5);
    if (unknown_c0) {
        delete unknown_c0;
    }
    if (unknown_bc) {
        delete unknown_bc;
    }
    if (state->unknown_0e8[state->index]) {
        if (state->unknown_178) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(0x1164);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
        }
    } else {
        Node *node = (Node *)data_0022FCE0->func_000128C0(0x1164);
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
    }
    func_00011BE0(this);
    func_00011C20(child);
    Node *node = (Node *)data_0022FCE0->func_000128C0(0x1ddb);
    if (node) {
        node->func_00011BE0(node);
        node->func_00011C20(node->child);
    }
}
