/* sym: ??0Object_0010D820@@QAE@PAUNode@@HIH@Z = 0x0010D820 */
/* sym: ??1Object_0010D820@@UAE@XZ = 0x0010D9D0 */
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
struct Interface_0010D820 {
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
    virtual long __stdcall slot9(int first, int second, Interface_0010D820 **result);
};

extern Interface_00251D74 *data_00251D74;

// A model from func_00025700: its flags at 0x24.
struct Model_0010D820 {
    char unknown_00[0x24];
    unsigned int flags;
};

// One of the four vertices at 0x58 (0x18 bytes each).
struct Vertex_0010D820 {
    float x;
    float y;
    int index;
    unsigned int color;
    float u;
    float v;
};

// A direct child of Node (table 0x1D2370, destructor func_0010D9D0): entry 5 of its 0x115e-range owner (id at 0x100)
// at 0xb8 with two digits at 0xd0, entry 4 and the owner's func_00107AB0, two models and a resource at 0x50.
struct Object_0010D820 : Node {
    Object_0010D820(Node *parent, int id, unsigned int mask, int ownerId);
    virtual ~Object_0010D820();

    int unknown_040;
    Model_0010D820 *model;
    void *sprite;
    int unknown_4c;
    Interface_0010D820 *resource;
    int unknown_54;
    Vertex_0010D820 vertices[4];
    int count;
    int shown;
    int last;
    int unknown_c4;
    int unknown_c8;
    int unknown_cc;
    int digits[2];
    int value_d8;
    int value_dc;
    float scale;
    int texture;
    char unknown_0e8[4];
    int unknown_ec;
    int unknown_f0;
    float position[3];
    int ownerId;
};

// Takes the owner's id, the owner's entry 5 as the count with its two digits, entry 4 and func_00107AB0, a resource
// from data_00251D74 (slot 9), the four vertices (index -1, white), the texture of sprite (0xa, 0, 0, 0), model
// (0xa, 0, 1, 0x3c) with flag 1 set and flag 8 clear, and sprite (0xa, 0, 2, 6); scale 1.
Object_0010D820::Object_0010D820(Node *parent, int id, unsigned int mask, int ownerId)
    : Node(parent, id, mask)
{
    this->ownerId = ownerId;
    unknown_ec = 0;
    resource = 0;
    model = 0;
    texture = -1;
    position[0] = -32.0f;
    position[1] = 24.0f;
    position[2] = 1220.0f;
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    last = shown = count = owner->func_001084E0(5);
    unknown_c8 = 0;
    unknown_c4 = 0;
    func_001087D0(count, 2, digits, 0);
    value_d8 = owner->func_001084E0(4);
    value_dc = owner->func_00107AB0();
    unknown_cc = 0;
    data_00251D74->slot9(0x14, 0, &resource);
    for (int i = 0; i < 4; i++) {
        vertices[i].index = -1;
        vertices[i].color = 0xffffff;
    }
    texture = data_00252790.func_0006E130((int)func_00025700(0xa, 0, 0, 0));
    model = (Model_0010D820 *)func_00025700(0xa, 0, 1, 0x3c);
    if (model) {
        model->flags &= ~1;
        model->flags |= 1;
        model->flags &= ~8;
    }
    sprite = func_00025700(0xa, 0, 2, 6);
    unknown_4c = 0;
    unknown_f0 = 0;
    scale = 1.0f;
}
