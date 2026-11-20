/* sym: ??0Object_00103D60@@QAE@PAUNode@@HIHHH@Z = 0x00103D60 */
/* sym: ??1Object_00103D60@@UAE@XZ = 0x00103F50 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Node {
    Node(Node *parent, int id, unsigned int mask);
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

void func_001087D0(int handle, unsigned int count, int *values, int value);
void *func_00025700(unsigned int index, int first, int second, int third);

struct Object_0006E130 {
    int func_0006E130(int texture);
};

extern Object_0006E130 data_00252790;

// The resource the interface at data_00251D74 creates for this node (its slot 9); slot 2 releases it.
struct Interface_00103D60 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9(int first, int second, Interface_00103D60 **result);
};

extern Interface_00251D74 *data_00251D74;

// Where the second set of corners goes: its top left at data_00220470, its size at data_002209E8.
extern float data_00220470;
extern float data_00220474;
extern float data_002209E8;
extern float data_002209EC;

// The rectangle of the second set's corners.
extern float data_00220888;
extern float data_0022088C;
extern float data_00220890;
extern float data_00220894;

// One of the eight corners at 0x60 (0x18 bytes each).
struct Vertex_00103D60 {
    float x;
    float y;
    int index;
    unsigned int color;
    float u;
    float v;
};

// A direct child of Node (table 0x1D1E98, destructor func_00103F50): two two-digit numbers at 0x48 (digits at 0x50
// and 0x58), eight corners and a resource at 0x44.
struct Object_00103D60 : Node {
    Object_00103D60(Node *parent, int id, unsigned int mask, int target, int first, int second);
    virtual ~Object_00103D60();

    int unknown_040;
    Interface_00103D60 *resource;
    int first;
    int second;
    int firstDigits[2];
    int secondDigits[2];
    Vertex_00103D60 corners[4];
    Vertex_00103D60 frame[4];
    int texture;
    char unknown_124[8];
    int state;
    unsigned int count;
    float fade;
    int target;
};

// Keeps the target and both numbers, state 0 at fade 1, and takes a resource from data_00251D74 (slot 9); without
// one the node unlinks itself, otherwise it writes both numbers in two digits (the first with -1), takes the texture
// of sprite (0xa, 0, 0, 0) and sets up the corners (index -1, white): the second set as the rectangle at
// data_00220470 with the size at data_002209E8, over the texture rectangle data_00220888 to data_00220894.
Object_00103D60::Object_00103D60(Node *parent, int id, unsigned int mask, int target, int first, int second)
    : Node(parent, id, mask)
{
    this->target = target;
    this->first = first;
    this->second = second;
    resource = 0;
    state = 0;
    count = 0;
    fade = 1.0f;
    if (data_00251D74->slot9(5, 0, &resource) < 0) {
        func_00011BE0(this);
        func_00011C20(child);
        resource = 0;
    } else {
        func_001087D0(this->first, 2, firstDigits, -1);
        func_001087D0(this->second, 2, secondDigits, 0);
        texture = data_00252790.func_0006E130((int)func_00025700(0xa, 0, 0, 0));
        for (int i = 0; i < 4; i++) {
            corners[i].index = -1;
            corners[i].color = 0xffffff;
            frame[i].index = -1;
            frame[i].color = 0xffffff;
        }
        frame[0].x = data_00220470;
        frame[0].y = data_00220474;
        frame[1].x = frame[0].x + data_002209E8;
        frame[1].y = frame[0].y;
        frame[2].x = frame[0].x;
        frame[2].y = frame[0].y + data_002209EC;
        frame[3].x = frame[1].x;
        frame[3].y = frame[2].y;
        frame[0].u = data_00220888;
        frame[0].v = data_0022088C;
        frame[1].u = data_00220890;
        frame[1].v = data_0022088C;
        frame[2].u = data_00220888;
        frame[2].v = data_00220894;
        frame[3].u = data_00220890;
        frame[3].v = data_00220894;
    }
}
