/* sym: ??0Object_00022990@@QAE@PAUNode@@HIH@Z = 0x0001E540 */
/* sym: ??1Object_00022990@@UAE@XZ = 0x00022990 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
extern "C" void *memset(void *destination, int value, unsigned int size);

void func_000FE550(int index);
int func_0002ABC0(int id);

struct Entry_2ABC0 {
    int id;
    int unknown_04;
    int unknown_08;
    int value;
    int unknown_10;
};

extern Entry_2ABC0 data_001EC690[];

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

// Node child with the table at 0x1C4BA8 (destructor 0x22990; made by 0x24240 as object 0x1ddd).
struct Object_00022990 : Node {
    Object_00022990(Node *owner, int id, unsigned int flags, int stage);
    virtual ~Object_00022990();

    char unknown_044[0x48];
    int stage;
    char unknown_090[4];
    int unknown_094;
    char unknown_098[0x6c];
    int unknown_104;
};

// Clears +0x44 to +0x108, keeps the stage at +0x8c, sets +0x104 to -1, runs func_000FE550 for 0 to 5 and takes +0x94
// from the entry of the table at 0x1EC690 for the stage (func_0002ABC0).
Object_00022990::Object_00022990(Node *owner, int id, unsigned int flags, int stage) : Node(owner, id, flags)
{
    memset(unknown_044, 0, 0xc4);
    this->stage = stage;
    unknown_104 = -1;
    func_000FE550(0);
    func_000FE550(1);
    func_000FE550(2);
    func_000FE550(3);
    func_000FE550(4);
    func_000FE550(5);
    unknown_094 = data_001EC690[func_0002ABC0(stage)].value;
}
