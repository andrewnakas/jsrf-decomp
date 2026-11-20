struct Game {
    void *func_000128C0(int id);
};

struct Node {
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// An entry of the list at 0xdc.
struct Entry_000FDF30 {
    int unknown_0[2];
    void *buffer;
    char unknown_c[0xc];
};

// Object 0x1165 (constructor func_000FE740, destructor func_000FDF30).
struct Object_000FDF30 {
    char unknown_000[0xa4];
    int ids[7];
    int unknown_0c0[7];
    Entry_000FDF30 entries[7];

    void func_000FE190();
};

extern Game *data_0022FCE0;

// Takes out every child whose id is in the list at 0xa4 (func_00011BE0 for it and func_00011C20 for its children)
// and clears its id; frees the buffer of each entry whose id at 0xc0 is set and clears that id.
void Object_000FDF30::func_000FE190()
{
    for (int i = 0; i < 7; i++) {
        if (ids[i] != -1) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(ids[i]);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
            ids[i] = -1;
        }
        if (unknown_0c0[i] != -1) {
            if (entries[i].buffer) {
                operator delete(entries[i].buffer);
                entries[i].buffer = 0;
            }
            unknown_0c0[i] = -1;
        }
    }
}
