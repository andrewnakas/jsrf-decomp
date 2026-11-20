/* sym: ??1Object_000667D0@@UAE@XZ = 0x000663E0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void func_00025740(unsigned int index, int argument);

struct Object_000667D0;

extern Object_000667D0 *data_00251F24;

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

// The node class whose table is at 0x1CB0A8 (data_00251F24 points at the one there is).
struct Object_000667D0 : Object_00012170 {
    virtual ~Object_000667D0();
};

// Passes 0x17 and 0 to func_00025740 and clears data_00251F24.
Object_000667D0::~Object_000667D0()
{
    func_00025740(0x17, 0);
    data_00251F24 = 0;
}
