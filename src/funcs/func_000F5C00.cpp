/* const: 0x200000 */
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
    int unknown_40;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Mesh_00017F60;

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

struct Item_00016260 {
    char unknown_00[8];
};

struct Item_000162A0 {
    int flags;
    int value_04;
    Mesh_00017F60 *mesh;
    void *frame;
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_000162A0(Item_000162A0 *item);
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The child of Node whose table is at 0x1CF220 (constructor func_000F5E70, destructor func_000F60C0). The class of the
// table at 0x1CEAC0 derives from it. The second base sits at 0x44 (tables 0x1CE1B8, then 0x1CF214).
struct Object_000F55E0 : Node, Object_000C60C0 {
    void func_000F5C00();

    Vector3 position;
    char unknown_054[0xc];
    float value_60;
    float value_64;
    char unknown_068[0xc];
    float distance;
    char unknown_078[0x18];
    unsigned int bits;
    char unknown_094[0x38];
    Vector3 point;
    char unknown_0d8[0xa4];
    Mesh_00017F60 *mesh;
    const Mesh_00017F60 *source;
    Item_00016260 link;
    Box_00017CC0 box;
    char unknown_1a4[4];
    int value_1a8;
    char unknown_1ac[0xc];
    int value_1b8;
    char unknown_1bc[0xc];
    Item_000162A0 item;
};

// Called by slot 1: with bits 8 or 25 at 0x90 clears 0x1b8, 0x1a8 and the item's frame. Within 80 (and bit 24, or
// without bit 21) the mesh at 0x17c is copied from 0x180 (func_00019570) and the item at 0x1c8 drawn; otherwise copied
// within 100 and the frame cleared. With bit 7 or a value at 0x60 or 0x64, the box at 0x18c spans the position lifted
// by 3 and the point at 0xcc lowered by 1 (func_00017CC0) and the link at 0x184 is refreshed; else 0x1b8 and 0x1a8 are
// cleared.
void Object_000F55E0::func_000F5C00()
{
    if (bits & 0x2000100) {
        value_1b8 = 0;
        value_1a8 = 0;
        item.frame = 0;
        return;
    }
    if (distance < 80.0f && ((bits & 0x1000000) || !(bits & 0x200000))) {
        data_0022FCE8.func_00019570(mesh, source);
        data_0022FCE8.func_000162A0(&item);
    } else {
        if (distance < 100.0f) {
            data_0022FCE8.func_00019570(mesh, source);
        }
        item.frame = 0;
    }
    if (!(bits & 0x80) && value_60 == 0.0f && value_64 == 0.0f) {
        value_1b8 = 0;
        value_1a8 = 0;
        return;
    }
    Vector3 points[2];
    points[0] = position;
    points[0].y += 3.0f;
    points[1] = point;
    points[1].y -= 1.0f;
    data_0022FCE8.func_00017CC0(&box, points, 2);
    data_0022FCE8.func_00016260(&link, -1);
}
