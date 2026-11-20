/* sym: ??0Object_000EB440@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000EB290 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000EB440@@UAEXXZ = 0x000EB630 */
/* sym: ?func_00011C90_1@Object_000EB440@@UAEXXZ = 0x000EB740 */
/* sym: ?func_00011C80@Object_000EB440@@UAEXH@Z = 0x000EB390 */
/* sym: ?func_00011C80_3@Object_000EB440@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000EB440@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

extern "C" void *memset(void *destination, int value, unsigned int size);

void *func_00025700(unsigned int index, int first, int second, int third);

// The resource func_00025700(5, 0xc) gives: a value at 0xc of its first entry.
struct Entry_000EB290 {
    char unknown_00[0xc];
    int value;
};

struct Resource_000EB290 {
    Entry_000EB290 *entry;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

struct Item_00016260 {
    int kind;
    int value;
    Box_00017CC0 box;
    int unknown_20[8];
    Item_00016260 *next;
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
    char unknown_34[0x10];
};

// The child of Node whose table is at 0x1CEED8 (its deleting destructor folds with Object_00012170's, 0x121B0).
struct Object_000EB440 : Node {
    Object_000EB440(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *velocity);
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Vector3 start;
    Vector3 position;
    Vector3 velocity;
    float rise;
    int spin[3];
    int state;
    unsigned int timer;
    unsigned int count;
    int value_84;
    Item_00016260 shape;
    Vector3 point;
    float radius;
};

// Builds the Node part and starts at `position` (also 0x44) with `velocity` (0x5c), rising by its y times 2.78
// (0x68), the value at 0xc of resource (5, 0xc) at 0x84, state, counts and spin cleared, an empty shape (kind 0xc3f)
// at 0x88 and radius 4.
Object_000EB440::Object_000EB440(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *velocity)
    : Node(owner, id, flags)
{
    value_84 = ((Resource_000EB290 *)func_00025700(5, 0xc, 0, 0))->entry->value;
    this->position = *position;
    start = *position;
    this->velocity = *velocity;
    rise = velocity->y * 2.7777777f;
    state = 0;
    timer = 0;
    count = 0;
    memset(spin, 0, sizeof(spin));
    memset(&shape, 0, sizeof(shape));
    radius = 4.0f;
    shape.kind = 0xc3f;
}
