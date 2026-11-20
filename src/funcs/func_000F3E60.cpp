/* sym: ??0Object_000F44E0@@QAE@PAUNode@@HIPBUVector3@@PAU2@@Z = 0x000F3E60 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_000F44E0@@UAE@XZ = 0x000F3F70 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000F44E0@@UAEXXZ = 0x000F4480 */
/* sym: ?func_00011C90_1@Object_000F44E0@@UAEXXZ = 0x000F44E0 */
/* sym: ?func_00011C80@Object_000F44E0@@UAEXH@Z = 0x000F3FE0 */
/* sym: ?func_00011C80_3@Object_000F44E0@@UAEXH@Z = 0x000F4050 */
/* sym: ?func_00011C80_4@Object_000F44E0@@UAEXH@Z = 0x000B3DE0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

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

struct Item_00016260 {
    int unknown_00;
    int value;
    char unknown_08[0x18];
    int unknown_20[8];
    Item_00016260 *next;
};

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;
extern const Mesh_00017F60 data_0021B2C4;

struct Frame_000F3E60 {
    char unknown_00[0xc];
    int value;
};

struct Info_000F3E60 {
    char unknown_00[0x4c];
    int value;
};

// What func_00025700 gives for (5, 0xd).
struct Sprite_000F3E60 {
    Frame_000F3E60 *frame;
    char unknown_04[0x14];
    Info_000F3E60 *info;
};

void *func_00025700(unsigned int index, int first, int second, int third);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);

// The child of Node whose table is at 0x1CF098 (destructor func_000F3F70): its slot 1 (func_000F4480) runs entry
// `state` of the member-function table at 0x21b2dc on itself.
struct Object_000F44E0 : Node {
    Object_000F44E0(Node *owner, int id, unsigned int flags, const Vector3 *position, Vector3 *direction);
    virtual ~Object_000F44E0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    int state;
    Vector3 start;
    Vector3 position;
    int angle;
    Vector3 velocity;
    int unknown_070;
    char unknown_074[0x20];
    int value_94;
    int value_98;
    int unknown_9c;
    Item_00016260 item;
    int unknown_e4;
    int unknown_e8;
    Mesh_00017F60 *mesh;
    int unknown_f0;
};

// Starts in state 0 at the position, heading along the direction made level (its y is cleared) and unit length
// (func_0014C410); takes two values of sprite (5, 0xd) (func_00025700), an item of kind 0x4000 and a copy of the
// mesh at 0x21B2C4 (func_00019680 of data_0022FCE8).
Object_000F44E0::Object_000F44E0(Node *owner, int id, unsigned int flags, const Vector3 *position, Vector3 *direction)
    : Node(owner, id, flags)
{
    Sprite_000F3E60 *sprite = (Sprite_000F3E60 *)func_00025700(5, 0xd, 0, 0);
    state = 0;
    start = *position;
    this->position = *position;
    direction->y = 0.0f;
    func_0014C410(&velocity, direction);
    unknown_070 = 0;
    value_94 = sprite->frame->value;
    value_98 = sprite->info->value;
    unknown_9c = 0;
    memset(&item, 0, sizeof(item));
    item.unknown_00 = 0x4000;
    mesh = data_0022FCE8.func_00019680(&data_0021B2C4);
    unknown_f0 = 0;
    unknown_e4 = 8;
    unknown_e8 = 1;
}
