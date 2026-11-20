/* sym: ??0Object_00024240@@QAE@PAUNode@@HIH@Z = 0x00024240 */
/* sym: ??1Object_00024240@@UAE@XZ = 0x00024330 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Object_000239D0@@QAE@PAUNode@@HIH@Z = 0x00024150 */
/* sym: ??0Object_00022990@@QAE@PAUNode@@HIH@Z = 0x0001E540 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Game {
    void func_000126F0(int value);
};

extern Game *data_0022FCE0;
extern int data_00230D94;

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

// The object 0x1ddc (table 0x1C4C88; 0xfc bytes).
struct Object_000239D0 {
    Object_000239D0(Node *owner, int id, unsigned int flags, int unused);

    char unknown_00[0xfc];
};

// Node child with the table at 0x1C4BA8 (object 0x1ddd; 0x108 bytes).
struct Object_00022990 {
    Object_00022990(Node *owner, int id, unsigned int flags, int stage);

    char unknown_000[0x108];
};

// The node class whose table is at 0x1C4CD0 (destructor 0x24330; 0x64 bytes).
struct Object_00024240 : Node {
    Object_00024240(Node *owner, int id, unsigned int flags, int stage);
    virtual ~Object_00024240();

    int unknown_44[8];
};

// Clears +0x44 to +0x64, runs func_000126F0 (1) of the game, creates object 0x1ddc (an Object_000239D0, flags 1)
// under it, keeps the stage at +0x48 and, for a stage that is not negative, clears data_00230D94 and creates object
// 0x1ddd (an Object_00022990, flags 0x5100) for it.
Object_00024240::Object_00024240(Node *owner, int id, unsigned int flags, int stage) : Node(owner, id, flags)
{
    memset(unknown_44, 0, sizeof(unknown_44));
    data_0022FCE0->func_000126F0(1);
    new Object_000239D0(this, 0x1ddc, 1, stage);
    unknown_44[1] = stage;
    if (stage >= 0) {
        data_00230D94 = 0;
        new Object_00022990(this, 0x1ddd, 0x5100, unknown_44[1]);
    }
}
