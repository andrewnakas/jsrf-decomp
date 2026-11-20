/* sym: ??0Object_00102920@@QAE@PAUNode@@HIH@Z = 0x00102920 */
/* sym: ??1Object_00102920@@UAE@XZ = 0x00102B90 */
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
    int func_000127E0(int index);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    int func_00107AB0();
    int func_001084E0(int index);
};

void func_001087D0(int handle, unsigned int count, int *values, int value);
void *func_00025700(unsigned int index, int first, int second, int third);

struct Object_0006E130 {
    int func_0006E130(int texture);
};

extern Object_0006E130 data_00252790;

// The resource the interface at data_00251D74 creates for this node (its slot 9); slot 2 releases it.
struct Interface_00102920 {
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
    virtual long __stdcall slot9(int first, int second, Interface_00102920 **result);
};

extern Interface_00251D74 *data_00251D74;

// A point (x, y, z).
struct Point_00102920 {
    float x;
    float y;
    float z;
};

// A pair of floats.
struct Pair_00102920 {
    float x;
    float y;
};

// The origin of the corners and the offsets by the game's entry 0xc and the owner's kind (four kinds each).
extern float data_00220258;
extern float data_0022025C;
extern Point_00102920 data_00220260[][4];

// The offsets and sizes of the second set of corners, by the owner's entry 8.
extern Pair_00102920 data_00220960[];
extern Pair_00102920 data_002209F0[];

// One of the eight corners at 0x50 (0x18 bytes each).
struct Vertex_00102920 {
    float x;
    float y;
    int index;
    unsigned int color;
    float u;
    float v;
};

// A direct child of Node (table 0x1D1E18, destructor func_00102B90): entry 8 of its 0x115e-range owner (id at
// 0x12c) and the owner's kind at 0x118, eight corners and a resource at 0x44.
struct Object_00102920 : Node {
    Object_00102920(Node *parent, int id, unsigned int mask, int ownerId);
    virtual ~Object_00102920();

    int unknown_040;
    Interface_00102920 *resource;
    int value;
    int shown;
    Vertex_00102920 corners[4];
    Vertex_00102920 frame[4];
    int texture;
    char unknown_114[4];
    int kind;
    char unknown_11c[4];
    int unknown_120;
    int unknown_124;
    int alpha;
    int ownerId;
};

// Takes the owner's id, its entry 8 (value and shown) and kind (func_00107AB0), alpha 0xff, and a resource from
// data_00251D74 (slot 9); without one the node unlinks itself, otherwise it takes the texture of sprite (0xa, 0, 0, 0)
// and sets up the corners (index -1, white): the first set 25 by 27 at data_00220258 plus the offset of the game's
// entry 0xc and the kind, the second set at that offset plus the position and size of the value's entry.
Object_00102920::Object_00102920(Node *parent, int id, unsigned int mask, int ownerId)
    : Node(parent, id, mask)
{
    this->ownerId = ownerId;
    resource = 0;
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    shown = value = owner->func_001084E0(8);
    kind = owner->func_00107AB0();
    unknown_120 = 0;
    unknown_124 = 0;
    alpha = 0xff;
    if (data_00251D74->slot9(3, 0, &resource) < 0) {
        func_00011BE0(this);
        func_00011C20(child);
        resource = 0;
    } else {
        texture = data_00252790.func_0006E130((int)func_00025700(0xa, 0, 0, 0));
        for (int i = 0; i < 4; i++) {
            corners[i].index = -1;
            corners[i].color = 0xffffff;
            frame[i].index = -1;
            frame[i].color = 0xffffff;
        }
        corners[0].x = data_00220258 + data_00220260[data_0022FCE0->func_000127E0(0xc)][kind].x;
        corners[0].y = data_0022025C + data_00220260[data_0022FCE0->func_000127E0(0xc)][kind].y;
        corners[1].x = corners[0].x + 25.0f;
        corners[1].y = corners[0].y;
        corners[2].x = corners[0].x;
        corners[2].y = corners[0].y + 27.0f;
        corners[3].x = corners[1].x;
        corners[3].y = corners[2].y;
        frame[0].x = data_00220260[data_0022FCE0->func_000127E0(0xc)][kind].x + data_00220960[value].x;
        frame[0].y = data_00220260[data_0022FCE0->func_000127E0(0xc)][kind].y + data_00220960[value].y;
        frame[1].x = data_002209F0[value].x + frame[0].x;
        frame[1].y = frame[0].y;
        frame[2].x = frame[0].x;
        frame[2].y = data_002209F0[value].y + frame[0].y;
        frame[3].x = frame[1].x;
        frame[3].y = frame[2].y;
    }
}
