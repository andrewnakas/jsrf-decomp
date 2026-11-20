/* sym: ??1Object_000448B0@@UAE@XZ = 0x000448B0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Entry_00044520;

// The list at 0x1F9138.
struct Object_00043700 {
    void func_00044520(int id);
};

extern Object_00043700 data_001F9138;

struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

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

// The node class whose table is at 0x1CA748: overrides slots 1 (43660), 2 (436C0) and 3 (44400).
struct Object_000448B0 : Node {
    virtual ~Object_000448B0();

    char unknown_44[0x40];
    int entry;
    char unknown_88[0x20];
    void *block;
};

// Takes its entry (+0x84) off the list at 0x1F9138 and releases the block at +0xa8 (func_00019760 of 0x22FCE8).
Object_000448B0::~Object_000448B0()
{
    data_001F9138.func_00044520(entry);
    data_0022FCE8.func_00019760(block);
}
