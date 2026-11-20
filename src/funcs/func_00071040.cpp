/* sym: ??1Object_00071040@@UAE@XZ = 0x00071040 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
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

// The class whose table is at 0x1CCA80 (constructor 0x70E30): overrides slots 1 (71CB0) and 3 (71100).
struct Object_00071040 : Object_00012170 {
    virtual ~Object_00071040();

    void func_0006FA70();
};

// Runs func_0006FA70 on the way out.
Object_00071040::~Object_00071040()
{
    func_0006FA70();
}
