/* sym: ??0Object_000F37B0@@QAE@PAUNode@@HIPBUVector3@@@Z = 0x000F37B0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_000F37B0@@UAE@XZ = 0x000F38B0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000F37B0@@UAEXXZ = 0x000F3920 */
/* sym: ?func_00011C80@Object_000F37B0@@UAEXH@Z = 0x000F3A20 */
/* sym: ?func_00011C80_3@Object_000F37B0@@UAEXH@Z = 0x000F3BB0 */
/* sym: ?func_00011C80_4@Object_000F37B0@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
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
};

struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_0021B23C;

struct Frame_000F37B0 {
    char unknown_00[8];
    int value;
};

struct Info_000F37B0 {
    char unknown_00[0x48];
    int value;
};

// What func_00025700 gives for (5, 0xd).
struct Sprite_000F37B0 {
    Frame_000F37B0 *frame;
    char unknown_04[0x14];
    Info_000F37B0 *info;
};

void *func_00025700(unsigned int index, int first, int second, int third);

// One of the 75 entries at 0x764 (0x24 bytes each).
struct Entry_000F37B0 {
    int width;
    int height;
    Mesh_00017F60 *item;
    int unknown_0c;
    char unknown_10[0x14];
};

// The child of Node whose table is at 0x1CF058 (destructor func_000F38B0).
struct Object_000F37B0 : Node {
    Object_000F37B0(Node *owner, int id, unsigned int flags, const Vector3 *position);
    virtual ~Object_000F37B0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    Vector3 position;
    char unknown_050[0x6fc];
    int hasPosition;
    int unknown_750;
    float scale;
    int value_758;
    int value_75c;
    int unknown_760;
    Entry_000F37B0 entries[75];
};

// Takes two values of sprite (5, 0xd) (func_00025700), the position when there is one, scale 1, and 75 entries of
// 0x200 by 0x400, each with a copy of the mesh at 0x21B23C (func_00019680 of data_0022FCE8).
Object_000F37B0::Object_000F37B0(Node *owner, int id, unsigned int flags, const Vector3 *position)
    : Node(owner, id, flags)
{
    Sprite_000F37B0 *sprite = (Sprite_000F37B0 *)func_00025700(5, 0xd, 0, 0);
    value_758 = sprite->frame->value;
    value_75c = sprite->info->value;
    unknown_760 = 0;
    if (position) {
        this->position = *position;
        hasPosition = 1;
    } else {
        hasPosition = 0;
    }
    unknown_750 = 0;
    scale = 1.0f;
    for (int i = 0; i < 75; i++) {
        entries[i].item = data_0022FCE8.func_00019680(&data_0021B23C);
        entries[i].width = 0x200;
        entries[i].height = 0x400;
        entries[i].unknown_0c = 0;
    }
}
