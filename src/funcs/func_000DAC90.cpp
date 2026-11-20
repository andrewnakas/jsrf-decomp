/* sym: ??0Object_000DB0F0@@QAE@PAUNode@@HI@Z = 0x000DAC90 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_000DB0F0@@UAE@XZ = 0x000DAD60 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000DB0F0@@UAEXXZ = 0x000DB330 */
/* sym: ?func_00011C90_1@Object_000DB0F0@@UAEXXZ = 0x000DB3D0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_002174F0;

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

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

// One of the sixty trail points at 0x50 (28 bytes).
struct Point_000DAE30 {
    Vector3 position;
    Vector3 direction;
    int handle;
};

// The 0x44-byte block at 0x6f8; the constructor sets only its kind.
struct Block_000DAC90 {
    int kind;
    char unknown_04[0x40];
};

// One of the sixteen mesh copies at 0x73c (36 bytes).
struct Entry_000DAD60 {
    int kind;
    int size;
    Mesh_00017F60 *pointer;
    int unknown_0c;
    char unknown_10[0x14];
};

// The child of Node whose table is at 0x1CE6F8 (0x97c bytes; destructor func_000DAD60): overrides slots 1 and 2.
struct Object_000DB0F0 : Node {
    Object_000DB0F0(Node *owner, int id, unsigned int flags);
    virtual ~Object_000DB0F0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

    int state;
    unsigned int flags_48;
    int timer;
    Point_000DAE30 points[60];
    unsigned int current;
    unsigned int oldest;
    int active;
    char unknown_6ec[0xc];
    Block_000DAC90 block;
    Entry_000DAD60 entries[16];
};

// Starts in state 0 with an empty trail (the flag at 0x6e8 set), the block at 0x6f8 cleared to kind 0x3f, and
// sixteen copies of the mesh at data_002174F0 (kind 7, size 0x400).
Object_000DB0F0::Object_000DB0F0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    state = 0;
    flags_48 = 0;
    timer = 0;
    current = 0;
    oldest = 0;
    active = 1;
    memset(&block, 0, sizeof(block));
    block.kind = 0x3f;
    for (int i = 0; i < 16; i++) {
        entries[i].pointer = data_0022FCE8.func_00019680(&data_002174F0);
        entries[i].kind = 7;
        entries[i].size = 0x400;
        entries[i].unknown_0c = 0;
    }
}
