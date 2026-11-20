/* sym: ??1Object_00113C40@@UAE@XZ = 0x00113C40 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00113C40@@UAEXXZ = 0x00113CD0 */
/* sym: ?func_00011C90_2@Object_00113C40@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00113C40@@UAEXXZ = 0x001145F0 */
/* sym: ?func_00011C80_2@Object_00113C40@@UAEXH@Z = 0x00114A80 */
/* sym: ?func_00011C90_6@Object_00113C40@@UAEXXZ = 0x000AECC0 */
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
    char unknown_34[0x60];
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A node with no virtual functions of its own (table 0x1C43D8). Its destructor (0x121D0, implicit here) is inlined
// at the end of the destructor below and called by its unwind code.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    int unknown_94;
};

// The class whose table is at 0x1D2B28: overrides slots 1, 7, 9 of Node; slots 4, 10 hold folded thunks.
struct Object_00113C40 : Object_00012170 {
    virtual ~Object_00113C40();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();

    char unknown_098[0x9c];
    int id_134;
};

// Unlinks the node whose id is id_134, when it still exists.
Object_00113C40::~Object_00113C40()
{
    if (data_0022FCE0->func_000128C0(id_134)) {
        Node *node = (Node *)data_0022FCE0->func_000128C0(id_134);
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
    }
}
