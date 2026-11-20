/* const: 0x10000 */
/* sym: ??1Object_000D01A0@@UAE@XZ = 0x000CFA90 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000D01A0@@UAEXXZ = 0x000D05C0 */
/* sym: ?func_00011C80@Object_000D01A0@@UAEXH@Z = 0x000D02F0 */
/* sym: ?func_00011C80_3@Object_000D01A0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000D01A0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ??0Object_000D01A0@@QAE@PAUNode@@HIPAUVector3@@@Z = 0x000D01A0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??0Object_000CFB70@@QAE@PAUObject_000D01A0@@PAUVector3@@H@Z = 0x000CFB70 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// What func_00025700 gives: the model at 0x10 holds the texture id at 0x2c.
struct Model_000D01A0 {
    char unknown_00[0x2c];
    int texture;
};

struct Resource_000D01A0 {
    char unknown_00[0x10];
    Model_000D01A0 *model;
};

void *func_00025700(unsigned int first, int second, int third, int fourth);

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB380(int angle);

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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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
    char unknown_34[0x10];
};


struct Object_000D01A0;

// One of the eight pieces at 0x48 (0x1dac bytes; table 0x1CE3F8).
struct Object_000CFB70 {
    Object_000CFB70(Object_000D01A0 *owner, Vector3 *direction, int angle);

    char unknown_0000[0x1dac];
};

// The class whose table is at 0x1CE3B8 (0x90 bytes; destructor 0xCFA90, constructor 0xD01A0): eight
// Object_000CFB70 at 0x48 around the position at 0x74; overrides slots 1 and 3 of Node, slots 12 and 15 hold
// folded thunks.
struct Object_000D01A0 : Node {
    Object_000D01A0(Node *owner, int id, unsigned int flags, Vector3 *position);
    virtual ~Object_000D01A0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    int state;
    Object_000CFB70 *items[8];
    unsigned int timer;
    float fade;
    unsigned int value_70;
    Vector3 position;
    char unknown_80[0xc];
    int texture;
};

// Keeps the texture id of resource (5, 0x13) at 0x8c and the position, timer 1, fade 1 and state 0, then builds the
// eight pieces at 0x48, the n-th with the direction (0, 0.707, -0.707) turned about z by n/8 of a turn plus 1/16
// (func_001BB380, func_001BAC00 in a pushed matrix) and the angle n * 0x2000.
Object_000D01A0::Object_000D01A0(Node *owner, int id, unsigned int flags, Vector3 *position) : Node(owner, id, flags)
{
    Resource_000D01A0 *resource = (Resource_000D01A0 *)func_00025700(5, 0x13, 0, 0);
    texture = resource->model->texture;
    state = 0;
    this->position = *position;
    timer = 1;
    fade = 1.0f;
    value_70 = 0;
    unsigned int angle = 0;
    Object_000CFB70 **item = items;
    for (; angle < 0x10000; angle += 0x2000) {
        Vector3 direction;
        direction.x = 0.0f;
        direction.y = 0.707f;
        direction.z = -0.707f;
        func_001BA9C0();
        func_001BB380(angle + 0x1000);
        func_001BAC00(&direction, &direction);
        func_001BAA50();
        *item = new Object_000CFB70(this, &direction, angle);
        item++;
    }
}
