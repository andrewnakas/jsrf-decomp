/* sym: ??0Object_00012AE0@@QAE@PAUNode@@HI@Z = 0x00012AE0 */
/* sym: ??1Object_00012AE0@@UAE@XZ = 0x00012BE0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Object_0007BC10@@QAE@PAUNode@@HI@Z = 0x0007BC10 */
/* sym: ??0Object_00118CB0@@QAE@PAUNode@@HI@Z = 0x00118C00 */
/* sym: ??0Object_00116A10@@QAE@PAUNode@@HI@Z = 0x00115FC0 */
/* sym: ??0Object_000243F0@@QAE@PAUNode@@HI@Z = 0x00024670 */
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

void func_00026010(Node *owner);

// The node class whose table is at 0x1CCEB8 (constructor 0x7BC10; 0x4c bytes).
struct Object_0007BC10 {
    Object_0007BC10(Node *owner, int id, unsigned int flags);

    char unknown_00[0x4c];
};

// The node class whose table is at 0x1D7B20 (constructor 0x118C00; 0x431c bytes).
struct Object_00118CB0 {
    Object_00118CB0(Node *owner, int id, unsigned int flags);

    char unknown_00[0x431c];
};

// The node class whose table is at 0x1D76C8 (constructor 0x115FC0; 0x114 bytes).
struct Object_00116A10 {
    Object_00116A10(Node *owner, int id, unsigned int flags);

    char unknown_00[0x114];
};

// The node class whose table is at 0x1C4D10 (constructor 0x24670; 0xc4 bytes).
struct Object_000243F0 {
    Object_000243F0(Node *owner, int id, unsigned int flags);

    char unknown_00[0xc4];
};

// The root node class (table 0x1C4480, destructor 0x12BE0; 0x44 bytes), made by func_00012C10.
struct Object_00012AE0 : Node {
    Object_00012AE0(Node *owner, int id, unsigned int flags);
    virtual ~Object_00012AE0();
};

// Creates object 7 under the root (func_00026010) and the root's children: an Object_0007BC10 (id 0), objects 4
// (Object_00118CB0) and 5 (Object_00116A10), and object 6 (Object_000243F0, with no owner and flags 1).
Object_00012AE0::Object_00012AE0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    func_00026010(this);
    new Object_0007BC10(this, 0, 0);
    new Object_00118CB0(this, 4, 0);
    new Object_00116A10(this, 5, 0);
    new Object_000243F0(0, 6, 1);
}
