/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
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

    void func_00012020(Node *newParent);
};

struct Game {
    char unknown_0000[0x87e8];
    int nodeCount;

    void func_00012870(int id, void *object);
};

extern Game *data_0022FCE0;

// Registers the node with the game under its id, links it in under its owner (func_00012020) and counts it in.
Node::Node(Node *owner, int id, unsigned int flags)
{
    data_0022FCE0->func_00012870(id, this);
    parent = 0;
    child = 0;
    previous = 0;
    next = 0;
    this->id = id;
    this->flags = flags;
    func_00012020(owner);
    sortKey = 0;
    mask = 1;
    data_0022FCE0->nodeCount++;
}
