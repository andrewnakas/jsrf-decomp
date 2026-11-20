struct Vector3 {
    float x;
    float y;
    float z;
};

struct Hit_00018260;

// The shape func_00018260 tests a segment against.
struct Model_00018260 {
    int unknown_00;
};

// A contact func_0001B5C0 or func_00018260 finds: points at 0x2c and 0x50.
struct Contact_000C4A90 {
    char unknown_00[0x2c];
    Vector3 point;
    char unknown_38[0x18];
    Vector3 otherPoint;
};

// What func_00018260 hands func_000194B0: two lists of contacts with their counts.
struct Hits_000C4C60 {
    Contact_000C4A90 *contacts;
    unsigned int count;
    Contact_000C4A90 *others;
    unsigned int otherCount;
};

struct Object_00016200 {
    int func_00018260(Model_00018260 *model, Vector3 *from, Vector3 *to, Hit_00018260 *hit, int mask, int limit);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060810(int key);
};

void func_000DA670(Vector3 *position, Vector3 *direction);

// A point of the trail (0x1c bytes): a direction at 0xc and a sound at 0x18.
struct Point_000DB0F0 {
    Vector3 position;
    Vector3 direction;
    int sound;
};

// The collision block at 0x6f8: its shape at 0x20 and two counts at 0x24 and 0x34.
struct Block_000DB0F0 {
    char unknown_00[0x20];
    Model_00018260 shape;
    unsigned int first;
    char unknown_28[0xc];
    unsigned int second;
    char unknown_38[0xc];
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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


struct Object_000DB0F0 : Node {
    virtual void func_00011C90();

    void func_000DB0F0();

    int state;
    unsigned int flags;
    int timer;
    Point_000DB0F0 points[60];
    unsigned int head;
    unsigned int tail;
    char unknown_6e8[4];
    Vector3 contact;
    Block_000DB0F0 block;
};

// While the block at 0x6f8 holds anything, tests the segment from the head point to the tail point against it
// (func_00018260); on a hit, the first time (flag 2 at 0x48) takes the nearest contact (func_000194B0) into 0xec
// and hands it to func_000DA670 with the tail's direction; then, while the tail is behind the head, stops its sound
// and moves the tail on (wrapping at 60).
void Object_000DB0F0::func_000DB0F0()
{
    if (block.first > 0 || block.second > 0) {
        Contact_000C4A90 *nearest;
        Hits_000C4C60 hits;
        Vector3 segment[2];
        segment[0] = points[head].position;
        segment[1] = points[tail].position;
        if (data_0022FCE8.func_00018260(&block.shape, &segment[0], &segment[1],
                                        (Hit_00018260 *)&hits, 0xffff, -1)) {
            if (!(flags & 2)) {
                if (!data_0022FCE8.func_000194B0(&hits, &nearest)) {
                    contact = nearest->point;
                } else {
                    contact = nearest->otherPoint;
                }
                func_000DA670(&contact, &points[tail].direction);
                flags |= 2;
            }
            if (tail != head) {
                Object_000607B0 *player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
                if (player) {
                    player->func_00060810(points[tail].sound);
                }
                if (++tail >= 60) {
                    tail = 0;
                }
            }
        }
    }
}
