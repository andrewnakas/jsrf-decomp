/* sym: ??1Object_000432E0@@UAE@XZ = 0x000432E0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

// An entry of the table at +0x44 (0x54 bytes): its block at +0x38.
struct Entry_00043370 {
    char unknown_00[0x38];
    void *block;
    char unknown_3c[0x18];
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

// The node class whose table is at 0x1CA678.
struct Object_000432E0 : Node {
    virtual ~Object_000432E0();

    Entry_00043370 *entries;
    unsigned int count;
};

// Releases the block of each of its `count` entries (func_00019760 of 0x22FCE8) and frees the entries.
Object_000432E0::~Object_000432E0()
{
    if (entries) {
        for (unsigned int i = 0; i < count; i++) {
            if (entries[i].block) {
                data_0022FCE8.func_00019760(entries[i].block);
            }
        }
        delete entries;
    }
}
