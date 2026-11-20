/* sym: ??1Object_00043950@@UAE@XZ = 0x00043950 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Game {
    void func_00012710(int value);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    void func_00039DE0(int kind, int index, int value);
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

// The node class whose table is at 0x1CA708.
struct Object_00043950 : Object_00012170 {
    virtual ~Object_00043950();

    char unknown_98[0xc];
    int index;
};

// Passes kind 3 with its index (+0xa4) and with the five indices 0x20 + index * 5 + i to func_00039DE0 of
// data_001EFFB0 (value 1), then 0 to the game's func_00012710.
Object_00043950::~Object_00043950()
{
    data_001EFFB0.func_00039DE0(3, index, 1);
    for (unsigned int i = 0; i < 5; i++) {
        data_001EFFB0.func_00039DE0(3, index * 5 + i + 0x20, 1);
    }
    data_0022FCE0->func_00012710(0);
}
