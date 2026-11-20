/* sym: ??1Object_00042A30@@UAE@XZ = 0x00042A30 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Game {
    void func_00012710(int value);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    void func_00039E80(unsigned int index);
};

extern Object_00039BE0 data_001EFFB0;

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

// The node class whose table is at 0x1CA630 (constructor 0x42970, made by 0x42AA0).
struct Object_00042A30 : Object_00012170 {
    virtual ~Object_00042A30();

    char unknown_98[0xc];
    unsigned int index;
};

// Hands its index (+0xa4) to func_00039E80 of data_001EFFB0 and passes 0 to the game's func_00012710.
Object_00042A30::~Object_00042A30()
{
    data_001EFFB0.func_00039E80(index);
    data_0022FCE0->func_00012710(0);
}
