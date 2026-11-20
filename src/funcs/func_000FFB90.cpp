/* sym: ??0Object_000FFB90@@QAE@PAUNode@@HIHH@Z = 0x000FFB90 */
/* sym: ??1Object_000FFB90@@UAE@XZ = 0x000FFD10 */
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
struct Interface_000FFB90 {
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
    virtual long __stdcall slot9(int first, int second, Interface_000FFB90 **result);
};

extern Interface_00251D74 *data_00251D74;

// A count shown with its digits: the value and the one shown.
struct Count_000FFB90 {
    int value;
    int shown;
};

// A direct child of Node (table 0x1D1CB0, destructor func_000FFD10): entries 0xd, 0xe and 0xf of its 0x115e-range
// owner (id at 0x120) at 0x88 with their digits at 0x48 (four, four and eight), drawn with a resource at 0x44.
struct Object_000FFB90 : Node {
    Object_000FFB90(Node *parent, int id, unsigned int mask, int value, int ownerId);
    virtual ~Object_000FFB90();

    int unknown_040;
    Interface_000FFB90 *resource;
    int first[4];
    int second[4];
    int third[8];
    Count_000FFB90 counts[3];
    char unknown_0a0[0x60];
    int texture;
    char unknown_104[4];
    int value_108;
    int unknown_10c;
    int unknown_110;
    float scale;
    int unknown_118;
    int unknown_11c;
    int ownerId;
};

// Takes the value and the owner's id, the owner's entries 0xd, 0xe and 0xf (func_001084E0) with their digits, scale
// 1, and a resource from data_00251D74 (slot 9); without one the node unlinks itself, otherwise it takes the texture
// of sprite (0xa, 0, 0, 0) at 0x100.
Object_000FFB90::Object_000FFB90(Node *parent, int id, unsigned int mask, int value, int ownerId)
    : Node(parent, id, mask)
{
    this->ownerId = ownerId;
    value_108 = value;
    resource = 0;
    counts[0].value = 0;
    counts[1].value = 0;
    counts[2].value = 0;
    unknown_118 = 0;
    unknown_11c = 0;
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    counts[0].shown = counts[0].value = owner->func_001084E0(0xd);
    counts[1].shown = counts[1].value = owner->func_001084E0(0xe);
    counts[2].shown = counts[2].value = owner->func_001084E0(0xf);
    func_001087D0(counts[0].value, 4, first, -1);
    func_001087D0(counts[1].value, 4, second, -1);
    func_001087D0(counts[2].value, 8, third, -1);
    unknown_10c = 0;
    unknown_110 = 0;
    scale = 1.0f;
    if (data_00251D74->slot9(0x10, 0, &resource) < 0) {
        func_00011BE0(this);
        func_00011C20(child);
        resource = 0;
    } else {
        texture = data_00252790.func_0006E130((int)func_00025700(0xa, 0, 0, 0));
    }
}
