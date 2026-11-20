/* sym: ??0Object_000C5B50@@QAE@PAUNode@@HI@Z = 0x000C5830 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_000C5B50@@UAE@XZ = 0x000C6150 */
/* sym: ?func_00011C90@Object_000C5B50@@UAEXXZ = 0x000C58A0 */
/* sym: ?func_00011C90_1@Object_000C5B50@@UAEXXZ = 0x000C5910 */
/* sym: ?func_00011C80@Object_000C5B50@@UAEXH@Z = 0x000C5940 */
/* sym: ?func_00011C80_3@Object_000C5B50@@UAEXH@Z = 0x000C5970 */
/* sym: ?func_00011C80_4@Object_000C5B50@@UAEXH@Z = 0x000B3DE0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// The class whose table is at 0x1CDFF0 (destructor func_000C6150): overrides slots 1, 2, 3, 12 and 15 of Node.
struct Object_000C5B50 : Node {
    Object_000C5B50(Node *owner, int id, unsigned int flags);
    virtual ~Object_000C5B50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0x34];
    Vector3 velocity;
    char unknown_080[0x24];
    unsigned int flags_a4;
    char unknown_0a8[0x14];
    int value_bc;
    char unknown_0c0[4];
    void *buffer_c4;
    int value_c8;
    void *radius;
    void *items;
    Node *first;
    Node *second;
    char unknown_0dc[0xc];
    int value_e8;
};

// Builds the node (func_00012100) with flag 4 and clears the velocity at 0x74 and the words at 0xa4 to 0xe8.
Object_000C5B50::Object_000C5B50(Node *owner, int id, unsigned int flags)
    : Node(owner, id, flags)
{
    Node::flags |= 4;
    value_c8 = 0;
    radius = 0;
    items = 0;
    first = 0;
    second = 0;
    buffer_c4 = 0;
    value_bc = 0;
    flags_a4 = 0;
    value_e8 = 0;
    memset(&velocity, 0, sizeof(velocity));
}
