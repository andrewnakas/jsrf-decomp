/* sym: ??0Object_000C6690@@QAE@PAUNode@@HIPAUVector3@@1H@Z = 0x000C6690 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000C6690@@UAEXXZ = 0x000C6A90 */
/* sym: ?func_00011C90_1@Object_000C6690@@UAEXXZ = 0x000C6B50 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Place_00043C00 {
    Vector3 position;
    int kind;
};

struct Info_00043C00 {
    Place_00043C00 *places;
    unsigned int count;
};

int func_00044740(Node *owner, Info_00043C00 *info);

// The class whose table is at 0x1CE030 (0xd0 bytes): a piece with a position, a velocity and a collision shape.
struct Object_000C6690 : Node {
    Object_000C6690(Node *owner, int id, unsigned int flags, Vector3 *start, Vector3 *direction, int count);
    virtual void func_00011C90();
    virtual void func_00011C90_1();

    char unknown_40[4];
    int target_id;
    Vector3 last;
    Vector3 position;
    Vector3 velocity;
    int value_6c;
    unsigned int time;
    int value_74;
    unsigned int bounces;
    int kind;
    char unknown_80[0x40];
    Vector3 center;
    float radius;
};

// Starts at `start` with the velocity `direction`, clears the counters and the shape words at 0x7c-0xbf, sets the
// kind 0xc3f and the radius 4, and registers one place (the start, kind `count`) with func_00044740 (the answer at
// 0x44).
Object_000C6690::Object_000C6690(Node *owner, int id, unsigned int flags, Vector3 *start, Vector3 *direction, int count)
    : Node(owner, id, flags)
{
    position = *start;
    last = *start;
    velocity = *direction;
    value_6c = 0;
    time = 0;
    value_74 = 0;
    bounces = 0;
    memset(&kind, 0, 0x44);
    Place_00043C00 place;
    Info_00043C00 info;
    kind = 0xc3f;
    radius = 4.0f;
    info.places = &place;
    info.count = 1;
    place.position = last;
    place.kind = count;
    target_id = func_00044740(this, &info);
}
