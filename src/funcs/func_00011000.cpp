/* sym: ??1Node@@UAE@XZ = 0x00011000 */
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
};

struct Game {
    char unknown_0000[0x87dc];
    Node *root;
    char unknown_87e0[8];
    int nodeCount;
};

extern Game *data_0022FCE0;

// Unlinks the node from its siblings (and from its parent or the game's root when it was the first) and counts it out.
Node::~Node()
{
    if (previous) {
        if (next) {
            next->previous = previous;
        }
        previous->next = next;
    } else {
        if (next) {
            next->previous = 0;
        }
        if (parent) {
            parent->child = next;
        } else {
            data_0022FCE0->root = next;
        }
    }
    data_0022FCE0->nodeCount--;
}
