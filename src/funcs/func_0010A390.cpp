/* sym: ??0Object_0010A390@@QAE@PAUNode@@HIH@Z = 0x0010A390 */
/* sym: ??1Object_0010A390@@UAE@XZ = 0x0010A580 */
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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    int func_001084E0(int index);
};

void func_001087D0(int handle, unsigned int count, int *values, int value);
void *func_00025700(unsigned int index, int first, int second, int third);

struct Object_0006E130 {
    int func_0006E130(int texture);
};

extern Object_0006E130 data_00252790;

// The resource the interface at data_00251D74 creates for this node (its slot 9); slot 2 releases it.
struct Interface_0010A390 {
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
    virtual long __stdcall slot9(int first, int second, Interface_0010A390 **result);
};

extern Interface_00251D74 *data_00251D74;

// Where the corners go: the top left at data_00220908, the size at data_00220998.
extern float data_00220908;
extern float data_0022090C;
extern float data_00220998;
extern float data_0022099C;

// The texture rectangle of the corners.
extern float data_002207E8;
extern float data_002207EC;
extern float data_002207F0;
extern float data_002207F4;

// One of the eight corners at 0xa8 (0x18 bytes each).
struct Vertex_0010A390 {
    float x;
    float y;
    int index;
    unsigned int color;
    float u;
    float v;
};

// A direct child of Node (table 0x1D20A0, destructor func_0010A580): entry 6 of its 0x115e-range owner (id at 0x178)
// in seven digits at 0x4c, eight corners and a resource at 0x44.
struct Object_0010A390 : Node {
    Object_0010A390(Node *parent, int id, unsigned int mask, int ownerId);
    virtual ~Object_0010A390();

    int unknown_040;
    Interface_0010A390 *resource;
    int unknown_048;
    int digits[7];
    int changing[7];
    char unknown_084[0x1c];
    int shown;
    int value;
    Vertex_0010A390 corners[4];
    Vertex_0010A390 shadow[4];
    int texture;
    int state;
    unsigned int frame;
    float roll;
    int ownerId;
};

// Takes the owner's id and its entry 6 (shown and value) in seven digits, marks the seven digits unchanged (-1),
// state 0, and takes a resource from data_00251D74 (slot 9); without one the node unlinks itself, otherwise it takes
// the texture of sprite (0xa, 0, 0, 0) and sets up the corners (index -1, white): the first set as the rectangle at
// data_00220908 with the size at data_00220998, over the texture rectangle data_002207E8 to data_002207F4.
Object_0010A390::Object_0010A390(Node *parent, int id, unsigned int mask, int ownerId)
    : Node(parent, id, mask)
{
    this->ownerId = ownerId;
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    shown = value = owner->func_001084E0(6);
    func_001087D0(shown, 7, digits, 0);
    for (int i = 0; i < 7; i++) {
        changing[i] = -1;
    }
    resource = 0;
    state = 0;
    if (data_00251D74->slot9(0xf, 0, &resource) < 0) {
        func_00011BE0(this);
        func_00011C20(child);
        resource = 0;
    } else {
        texture = data_00252790.func_0006E130((int)func_00025700(0xa, 0, 0, 0));
        for (int j = 0; j < 4; j++) {
            corners[j].index = -1;
            corners[j].color = 0xffffff;
            shadow[j].index = -1;
            shadow[j].color = 0xffffff;
        }
        corners[0].x = data_00220908;
        corners[0].y = data_0022090C;
        corners[1].x = corners[0].x + data_00220998;
        corners[1].y = corners[0].y;
        corners[2].x = corners[0].x;
        corners[2].y = corners[0].y + data_0022099C;
        corners[3].x = corners[1].x;
        corners[3].y = corners[2].y;
        corners[0].u = data_002207E8;
        corners[0].v = data_002207EC;
        corners[1].u = data_002207F0;
        corners[1].v = data_002207EC;
        corners[2].u = data_002207E8;
        corners[2].v = data_002207F4;
        corners[3].u = data_002207F0;
        corners[3].v = data_002207F4;
    }
}
