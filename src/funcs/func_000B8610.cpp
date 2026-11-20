/* sym: ??1Object_000B9960@@UAE@XZ = 0x000B8610 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000B9960@@UAEXXZ = 0x000B9960 */
/* sym: ?func_00011C90_1@Object_000B9960@@UAEXXZ = 0x000B9980 */
/* sym: ?func_00011C80@Object_000B9960@@UAEXH@Z = 0x000B86E0 */
/* sym: ?func_00011C90_2@Object_000B9960@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000B9960@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000B9960@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000B9960@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000B9960@@UAEXH@Z = 0x000B3DE0 */
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
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_0005DAA0(void *pointer);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD998).
struct Object_000B9960 : Node {
    virtual ~Object_000B9960();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0x48];
    void *block;
    char unknown_08c[0xc];
    int ids[16];
    char unknown_0d8[0xd0];
    void *first;
    char unknown_1ac[0x3c];
    void *second;
};

// Unlinks the nodes the 16 ids at 0x98 name (func_00011BE0, then func_00011C20 on the node's child), frees the
// buffers at 0x1a8 and 0x1e8 when there are any, and passes the block at 0x88 to func_0005DAA0 when there is one.
Object_000B9960::~Object_000B9960()
{
    for (int i = 0; i < 16; i++) {
        if (ids[i]) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(ids[i]);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
        }
    }
    if (first) {
        operator delete(first);
    }
    if (second) {
        operator delete(second);
    }
    if (block) {
        func_0005DAA0(block);
    }
}
