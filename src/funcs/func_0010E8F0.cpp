/* sym: ??0Object_0010E8F0@@QAE@PAUNode@@HIIHHHH@Z = 0x0010E8F0 */
/* sym: ??1Object_0010E8F0@@UAE@XZ = 0x0010EAB0 */
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
struct Interface_0010E8F0 {
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
    virtual long __stdcall slot9(int first, int second, Interface_0010E8F0 **result);
};

extern Interface_00251D74 *data_00251D74;

// The rectangle the corners take.
extern float data_00220848;
extern float data_0022084C;
extern float data_00220850;
extern float data_00220854;

// One of the four corner entries at 0x94 (0x18 bytes each).
struct Corner_0010E8F0 {
    int index;
    unsigned int color;
    float x;
    float y;
    int unknown_10;
    int unknown_14;
};

// A direct child of Node (table 0x1D23F0, destructor func_0010EAB0): three two-digit numbers at 0x50, a value as a
// float at 0x80, four corners at 0x94 and a resource at 0x4c.
struct Object_0010E8F0 : Node {
    Object_0010E8F0(Node *parent, int id, unsigned int mask, unsigned int value, int kind, int value_164,
                    int value_16c, int value_44);
    virtual ~Object_0010E8F0();

    int unknown_040;
    int value_44;
    int unknown_48;
    Interface_0010E8F0 *resource;
    int first[4];
    int second[4];
    int third[4];
    float value;
    float unknown_84;
    int unknown_88;
    char unknown_08c[8];
    Corner_0010E8F0 corners[4];
    char unknown_0f4[0x58];
    int unknown_14c;
    int texture;
    char unknown_154[4];
    unsigned int color;
    int unknown_15c;
    int kind;
    int value_164;
    int unknown_168;
    int value_16c;
    int unknown_170;
};

// Keeps the arguments (the value as a float at 0x80) and takes a resource from data_00251D74 (slot 9); without one
// the node unlinks itself, otherwise it takes colour 0xFF6496FF for kind 3 (white otherwise), the texture of sprite
// (0xa, 0, 0, 0), the corners of data_00220848 to data_00220854 and three zeros in two digits each.
Object_0010E8F0::Object_0010E8F0(Node *parent, int id, unsigned int mask, unsigned int value, int kind, int value_164,
                                 int value_16c, int value_44)
    : Node(parent, id, mask)
{
    this->value_16c = value_16c;
    this->value_44 = value_44;
    unknown_170 = 0;
    resource = 0;
    unknown_84 = -1.0f;
    this->value = value;
    unknown_88 = 0;
    unknown_15c = 0;
    unknown_14c = 0;
    this->kind = kind;
    this->value_164 = value_164;
    unknown_168 = 0;
    unknown_48 = 0;
    if (data_00251D74->slot9(0x10, 0, &resource) < 0) {
        func_00011BE0(this);
        func_00011C20(child);
        resource = 0;
    } else {
        color = this->kind != 3 ? 0xffffffff : 0xff6496ff;
        texture = data_00252790.func_0006E130((int)func_00025700(0xa, 0, 0, 0));
        corners[0].x = data_00220848;
        corners[0].y = data_0022084C;
        corners[1].x = data_00220850;
        corners[1].y = data_0022084C;
        corners[2].x = data_00220848;
        corners[2].y = data_00220854;
        corners[3].x = data_00220850;
        corners[3].y = data_00220854;
        func_001087D0(0, 2, first, 0);
        func_001087D0(0, 2, second, 0);
        func_001087D0(0, 2, third, 0);
    }
}
