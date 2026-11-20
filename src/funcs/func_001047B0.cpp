/* sym: ??0Object_001047B0@@QAE@PAUNode@@HIHH@Z = 0x001047B0 */
/* sym: ??1Object_001047B0@@UAE@XZ = 0x00104930 */
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
struct Interface_001047B0 {
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
    virtual long __stdcall slot9(int first, int second, Interface_001047B0 **result);
};

extern Interface_00251D74 *data_00251D74;

// The rectangle the corners take.
extern float data_00220808;
extern float data_0022080C;
extern float data_00220810;
extern float data_00220814;

// One of the eight corner entries at 0x5c (0x18 bytes each).
struct Corner_001047B0 {
    int index;
    unsigned int color;
    float x;
    float y;
    int texture;
    int unknown_14;
};

// A direct child of Node (table 0x1D1F18, destructor func_00104930): a three-digit count at 0x11c (its digits at 0x48)
// following entry 0xb of its 0x115e-range owner (id at 0x134), drawn with a resource at 0x44.
struct Object_001047B0 : Node {
    Object_001047B0(Node *parent, int id, unsigned int mask, int value, int ownerId);
    virtual ~Object_001047B0();

    int unknown_040;
    Interface_001047B0 *resource;
    int digits[3];
    char unknown_054[8];
    Corner_001047B0 first[4];
    Corner_001047B0 second[4];
    int count;
    int last;
    int value_124;
    int state;
    unsigned int timer;
    int alpha;
    int ownerId;
};

// Takes the value and the owner's id, the owner's entry 0xb plus 1 (func_001084E0) as the count and its three
// digits, state 0, and a resource from data_00251D74 (slot 9); without one the node unlinks itself, otherwise it takes
// the texture of sprite (0xa, 0, 0, 0) (in the last corner entry) and the eight corner entries (index -1, white) at
// the corners of data_00220808 to data_00220814.
Object_001047B0::Object_001047B0(Node *parent, int id, unsigned int mask, int value, int ownerId)
    : Node(parent, id, mask)
{
    this->ownerId = ownerId;
    value_124 = value;
    resource = 0;
    state = 0;
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    last = count = owner->func_001084E0(0xb) + 1;
    func_001087D0(count, 3, digits, 0);
    if (data_00251D74->slot9(4, 0, &resource) < 0) {
        func_00011BE0(this);
        func_00011C20(child);
        resource = 0;
    } else {
        second[3].texture = data_00252790.func_0006E130((int)func_00025700(0xa, 0, 0, 0));
        for (int i = 0; i < 4; i++) {
            second[i].index = -1;
            second[i].color = 0xffffff;
            first[i].index = -1;
            first[i].color = 0xffffff;
        }
        first[0].x = data_00220808;
        first[0].y = data_0022080C;
        first[1].x = data_00220810;
        first[1].y = data_0022080C;
        first[2].x = data_00220808;
        first[2].y = data_00220814;
        first[3].x = data_00220810;
        first[3].y = data_00220814;
    }
}
