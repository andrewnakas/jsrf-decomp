/* sym: ??1Object_00067980@@UAE@XZ = 0x00067980 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void __cdecl operator delete(void *memory);
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

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

// The node 0x12af (table 0x1CB0F8, constructor 0x67B60).
struct Object_00067980 : Object_00012170 {
    virtual ~Object_00067980();

    char unknown_098[0x2a4];
    void *block;
    void *buffers[3];
    char unknown_34c[0x32c];
    void *list;
};

// Frees the block at +0x33c and the three buffers at +0x340 that are set, and releases the memory at +0x678
// (func_00145A5D with 0x8000).
Object_00067980::~Object_00067980()
{
    if (block) {
        operator delete(block);
    }
    for (unsigned int i = 0; i < 3; i++) {
        if (buffers[i]) {
            operator delete(buffers[i]);
        }
    }
    if (list) {
        func_00145A5D(list, 0, 0x8000);
    }
}
