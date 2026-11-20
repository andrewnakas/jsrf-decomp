/* sym: ??1Object_0006CE00@@UAE@XZ = 0x0006CE00 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000149B0 {
    void func_0006CD80(int id);
};

extern Object_000149B0 data_0020C750;

struct Object_0006DB80 {
    void func_0006DF30(int id);
};

extern Object_0006DB80 data_00251F78;

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

// The node class whose table is at 0x1CC158.
struct Object_0006CE00 : Node {
    virtual ~Object_0006CE00();

    int key;
    char unknown_048[0xc];
    unsigned int count;
    int *ids;
    char *names;
    int unknown_60;
    int entry;
};

// Hands its key (+0x44) to func_0006CD80 of 0x20C750 and its entry (+0x64) to func_0006DF30 of 0x251F78, takes out
// the `count` nodes whose ids are at +0x58 with everything below them, and frees the ids and the block at +0x5c.
Object_0006CE00::~Object_0006CE00()
{
    data_0020C750.func_0006CD80(key);
    data_00251F78.func_0006DF30(entry);
    for (unsigned int i = 0; i < count; i++) {
        Node *node = (Node *)data_0022FCE0->func_000128C0(ids[i]);
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
    }
    delete ids;
    delete names;
}
