/* sym: ??1Object_000780F0@@UAE@XZ = 0x000780F0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void func_00118780(int value);
void func_001166B0(int value);

struct Game {
    void func_000126D0(int argument);
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
    void func_00012AC0(int first, int second);
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

// The node class whose table is at 0x1CCD18.
struct Object_000780F0 : Object_00012170 {
    virtual ~Object_000780F0();

    char unknown_098[8];
    char *names;
    char *buffers[7];
    char unknown_0c0[0x38c];
    char *block;
    char unknown_450[4];
    int mode;
};

// In mode 1 (+0x454) clears bit 0 of game value 0x1b3; passes 0 to the game's func_000126D0, sets game value 0x1a1
// to 1, runs func_00012AC0 (0x72b1, 0), func_00118780 (0) and func_001166B0 (0), then frees and clears the blocks at
// +0x44c, +0xa0 and the seven at +0xa4 that are set.
Object_000780F0::~Object_000780F0()
{
    if (mode == 1) {
        data_0022FCE0->func_000127C0(0x1b3, data_0022FCE0->func_000127E0(0x1b3) & ~1);
    }
    data_0022FCE0->func_000126D0(0);
    data_0022FCE0->func_000127C0(0x1a1, 1);
    data_0022FCE0->func_00012AC0(0x72b1, 0);
    func_00118780(0);
    func_001166B0(0);
    if (block) {
        delete block;
        block = 0;
    }
    if (names) {
        delete names;
        names = 0;
    }
    for (unsigned int i = 0; i < 7; i++) {
        if (buffers[i]) {
            delete buffers[i];
            buffers[i] = 0;
        }
    }
}
