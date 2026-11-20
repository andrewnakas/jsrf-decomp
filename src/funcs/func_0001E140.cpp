/* sym: ??1Object_0001E140@@UAE@XZ = 0x0001E140 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Game {
    void func_00012710(int value);
};

extern Game *data_0022FCE0;

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

// The node class whose table is at 0x1C45C8: overrides slots 10 (42880), 11 (1E3C0) and 12 (1E1A0).
struct Object_0001E140 : Object_00012170 {
    virtual ~Object_0001E140();
};

// Passes 0 to the game's func_00012710 on the way out.
Object_0001E140::~Object_0001E140()
{
    data_0022FCE0->func_00012710(0);
}
