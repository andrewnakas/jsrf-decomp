/* sym: ??0Object_000A8360@@QAE@PAUNode@@HI@Z = 0x000A82D0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_000A8360@@UAE@XZ = 0x000A8360 */
/* sym: ?func_00011C90@Object_000A8360@@UAEXXZ = 0x000A8370 */
/* sym: ?func_00011C90_2@Object_000A8360@@UAEXXZ = 0x000AECC0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

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

struct Part_000A82D0 {
    char unknown_00[0x34];
};

struct Slot_000A82D0 {
    Part_000A82D0 *part;
    char unknown_04[0x24];
};

// A direct child of Node (table 0x1CD5C8, destructor func_000A8360; slot 1 func_000A8370 runs the stage's
// players): 32 slots (0x44), each with its part (0x544) and a second part (0xbc4), and 32 ids (0x1244).
struct Object_000A8360 : Node {
    Object_000A8360(Node *owner, int id, unsigned int flags);
    virtual ~Object_000A8360();
    virtual void func_00011C90();
    virtual void func_00011C90_2();

    char unknown_40[4];
    Slot_000A82D0 slots[32];
    Part_000A82D0 parts[32];
    Part_000A82D0 others[32];
    int ids[32];
};

// Builds the Node part and empties the 32 slots, pointing each at its part, with id -1.
Object_000A8360::Object_000A8360(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    for (int i = 0; i < 32; i++) {
        memset(&slots[i], 0, sizeof slots[i]);
        memset(&parts[i], 0, sizeof parts[i]);
        memset(&others[i], 0, sizeof others[i]);
        slots[i].part = &parts[i];
        ids[i] = -1;
    }
}
