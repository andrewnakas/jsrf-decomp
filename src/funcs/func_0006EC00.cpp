/* sym: ??1Object_0006EC00@@UAE@XZ = 0x0006EC00 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void __cdecl operator delete(void *memory);
void func_00024620(unsigned int color, float step);

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

// The node class whose table is at 0x1CC660.
struct Object_0006EC00 : Object_00012170 {
    virtual ~Object_0006EC00();

    char unknown_98[8];
    void *buffer;
    int keep;
};

// Unless +0xa4 is set, fades to black (func_00024620 with 0 and 1/60); frees the buffer at +0xa0 when there is one.
Object_0006EC00::~Object_0006EC00()
{
    if (!keep) {
        func_00024620(0, 1.0f / 60.0f);
    }
    if (buffer) {
        operator delete(buffer);
    }
}
