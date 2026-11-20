/* sym: ?func_00011C90@Object_00102920@@UAEXXZ = 0x00102BF0 */
struct Node {
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
    int func_001084E0(int index);
};


// The resource the interface at data_00251D74 creates for this node (its slot 9); slot 2 releases it.
struct Interface_00102920 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

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
    virtual void func_00011C90();

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
    int state;
    int unknown_124;
    int alpha;
    int ownerId;
};

// Slot 1: follows the owner's entry 8; state 0 restarts (alpha 0xff, the value shown) and goes on to state 1, which
// places the corners as the constructor does and moves to state 2; state 3 unlinks the node.
void Object_00102920::func_00011C90()
{
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    value = owner->func_001084E0(8);
    switch (state) {
    case 0:
        unknown_124 = 0;
        alpha = 0xff;
        shown = value;
        state = 1;
    case 1:
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
        state = 2;
        break;
    case 3:
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
}
