/* sym: ??1Object_0003BB10@@UAE@XZ = 0x0003BB10 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

// An entry of the table at +0x50 (0x5c bytes): its block at +0x40.
struct Entry_0003BC80 {
    char unknown_00[0x40];
    void *block;
    char unknown_44[0x18];
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

// The node class whose table is at 0x1CA3E8 (constructor 0x3B940).
struct Object_0003BB10 : Node {
    virtual ~Object_0003BB10();

    char unknown_044[4];
    unsigned int count;
    char unknown_04c[4];
    Entry_0003BC80 *entries;
};

// Releases the block of each of its `count` entries (func_00019760 of 0x22FCE8) and frees the entries.
Object_0003BB10::~Object_0003BB10()
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
