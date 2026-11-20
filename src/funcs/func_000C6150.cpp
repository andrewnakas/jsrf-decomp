/* sym: ??1Object_000C5B50@@UAE@XZ = 0x000C6150 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000C5B50@@UAEXXZ = 0x000C58A0 */
/* sym: ?func_00011C90_1@Object_000C5B50@@UAEXXZ = 0x000C5910 */
/* sym: ?func_00011C80@Object_000C5B50@@UAEXH@Z = 0x000C5940 */
/* sym: ?func_00011C80_3@Object_000C5B50@@UAEXH@Z = 0x000C5970 */
/* sym: ?func_00011C80_4@Object_000C5B50@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0x12b1.
struct Object_000C0690 {
    void func_000C0690(int amount);
};

// The parts at 0xd4 and 0xd8: slot 4 is the destructor.
struct Part_000C5910 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int argument);
    virtual void slot3(int argument);
    virtual ~Part_000C5910();
};

struct Buffer_000C6150 {
    int unknown_00;
};

struct Object_000C5B50;

// A link of the per-area lists of data_00257CE4.
struct Link_000C6150 {
    Object_000C5B50 *object;
    Link_000C6150 *next;
};

struct Object_00066980;

// The object in data_00257CE4: a list of objects per area at 0x4, its point at 0x7c.
struct Object_000C1270 {
    int unknown_00;
    Link_000C6150 *lists[29];
    Object_00066980 *clock;
    Vector3 point;
};

extern Object_000C1270 *data_00257CE4;

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
    char unknown_080[0x18];
    int value_98;
    int area;
    char unknown_0a0[4];
    unsigned int flags_a4;
    Vector3 *target;
    char unknown_0ac[0x18];
    Buffer_000C6150 *buffer;
    char unknown_0c8[8];
    void *items;
    Part_000C5910 *first;
    Part_000C5910 *second;
    char unknown_0dc[4];
    Object_000C5B50 *leader;
    Object_000C5B50 *follower;
};

// Deletes the parts at 0xd8 and 0xd4 and the buffer at 0xc4; hands the amount at 0x98 back to object 0x12b1
// (func_000C0690, as func_000C5AD0 does); takes itself out of its chain (leader at 0xe0, follower at 0xe4, whose
// target goes back to the point of data_00257CE4) and out of its area's list in data_00257CE4.
Object_000C5B50::~Object_000C5B50()
{
    if (second) {
        delete second;
        second = 0;
    }
    if (first) {
        delete first;
        first = 0;
    }
    if (buffer) {
        delete buffer;
        buffer = 0;
    }
    unsigned int amount = value_98;
    if (amount > 0) {
        Object_000C0690 *total = (Object_000C0690 *)data_0022FCE0->func_000128C0(0x12b1);
        if (total) {
            total->func_000C0690(amount);
        }
        if ((value_98 -= amount) < 0) {
            value_98 = 0;
        }
    }
    if (follower) {
        follower->leader = leader;
        follower->target = &data_00257CE4->point;
    }
    if (leader) {
        leader->follower = follower;
    }
    if (data_00257CE4) {
        Link_000C6150 **head = &data_00257CE4->lists[area];
        Link_000C6150 *link = *head;
        if (link) {
            if (link->object == this) {
                *head = link->next;
                delete link;
            } else {
                Link_000C6150 *previous = link;
                for (link = link->next; link; link = link->next) {
                    if (link->object == this) {
                        previous->next = link->next;
                        delete link;
                        break;
                    }
                    previous = link;
                }
            }
        }
    }
}
