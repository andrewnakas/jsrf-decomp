/* sym: ??1Object_00074D60@@UAE@XZ = 0x00074D60 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void __cdecl operator delete(void *memory);

struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

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

// The class whose table is at 0x1CCCD8 (constructor 0x75A30, destructor 0x74D60).
struct Object_00074D60 : Object_00012170 {
    virtual ~Object_00074D60();

    char unknown_98[0x1c];
    void *buffers[17];
};

// Frees the 17 buffers at +0xb4 that are there and sets the game's entry 0x1a2 to 1 (func_000127C0).
Object_00074D60::~Object_00074D60()
{
    for (int i = 0; i < 17; i++) {
        if (buffers[i]) {
            operator delete(buffers[i]);
        }
    }
    data_0022FCE0->func_000127C0(0x1a2, 1);
}
