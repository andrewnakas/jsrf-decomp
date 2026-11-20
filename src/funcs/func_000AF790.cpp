/* sym: ??1Object_000AF790@@UAE@XZ = 0x000AF790 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000AF790@@UAEXXZ = 0x000AF860 */
/* sym: ?func_00011C90_1@Object_000AF790@@UAEXXZ = 0x000AFA90 */
/* sym: ?func_00011C80@Object_000AF790@@UAEXH@Z = 0x000AFD40 */
/* sym: ?func_00011C90_2@Object_000AF790@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000AF790@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000AF790@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000AF790@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000AF790@@UAEXH@Z = 0x000B3DE0 */
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

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD7B0).
struct Object_000AF790 : Node {
    virtual ~Object_000AF790();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0xe0];
    int *ids;
    char unknown_124[0x94];
    void *first;
    char unknown_1bc[0x38];
    void *second;
};

// Frees the buffers at 0x1b8 and 0x1f4 when there are any; then unlinks the nodes the three ids at 0x120 name
// (func_00011BE0, then func_00011C20 on the node's child) and frees the ids.
Object_000AF790::~Object_000AF790()
{
    if (first) {
        operator delete(first);
    }
    if (second) {
        operator delete(second);
    }
    if (ids) {
        for (int i = 0; i < 3; i++) {
            if (ids[i]) {
                Node *node = (Node *)data_0022FCE0->func_000128C0(ids[i]);
                if (node) {
                    node->func_00011BE0(node);
                    node->func_00011C20(node->child);
                }
            }
        }
        delete[] ids;
    }
}
