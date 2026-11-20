/* sym: ??1Object_00079B50@@UAE@XZ = 0x00079B50 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Game {
    void *func_000128C0(int id);
    void func_00012730(int value);
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

// The object 0x1163.
struct Object_000FEDB0 {
    void func_000FF060(int value);
};

struct Node {
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

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    char unknown_44[0x50];
    int unknown_94;
};

// The node class whose table is at 0x1CCDE8 (constructor 0x7A8B0).
struct Object_00079B50 : Object_00012170 {
    virtual ~Object_00079B50();
};

// Passes 0 to the game's func_00012730 and to func_000FF060 of object 0x1163, and sets game value 0x1a1 to 1.
Object_00079B50::~Object_00079B50()
{
    data_0022FCE0->func_00012730(0);
    Object_000FEDB0 *object = (Object_000FEDB0 *)data_0022FCE0->func_000128C0(0x1163);
    if (object) {
        object->func_000FF060(0);
    }
    data_0022FCE0->func_000127C0(0x1a1, 1);
}
