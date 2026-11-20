/* sym: ??0Object_000C4850@@QAE@PAUNode@@HIPAUVector3@@1H@Z = 0x000C4850 */
/* sym: ??1Object_000C4850@@UAE@XZ = 0x000121D0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ?func_00011C90@Object_000C4850@@UAEXXZ = 0x000C4960 */
/* sym: ?func_00011C90_1@Object_000C4850@@UAEXXZ = 0x000C4C60 */
/* sym: ?func_00011C80@Object_000C4850@@UAEXH@Z = 0x000C4A10 */
/* sym: ?func_00011C80_3@Object_000C4850@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000C4850@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// The part of the collision item func_0001B5C0 tests: two counts, at +0x4 and +0x14.
struct Shape_000EC910 {
    int unknown_00;
    unsigned int first;
    char unknown_08[0xc];
    unsigned int second;
    char unknown_18[0xc];
};

// The collision item of data_0022FCE8 (func_00016260): a mask, a box (func_00017D90) and a shape.
struct Item_00016260 {
    int mask;
    int value;
    Box_00017CC0 box;
    Shape_000EC910 shape;
};

// The models' base (tables 0x1CA490, 0x1CAA8C, 0x1CC12C): slot 5 poses the model.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470();
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);

    char unknown_04[0x1c];
    Matrix_001BA950 *matrices;
    char unknown_24[0x34];
    float frame;
};

// What func_0001B5C0 finds and func_000194B0 picks from: a contact with a point and a normal at +0x3c and +0x48,
// or +0x60 and +0x6c.
struct Contact_000C4A90 {
    char unknown_00[0x3c];
    Vector3 point;
    Vector3 normal;
    char unknown_54[0xc];
    Vector3 otherPoint;
    Vector3 otherNormal;
};

extern "C" void *memset(void *destination, int value, unsigned int size);

// An axis and an angle (func_001BAC70 reads the angle at 0xc).
struct Rotation_000D2B90 {
    Vector3 axis;
    int angle;
};

// What func_00025700 (5, ...) returns: its models.
struct Sprite_000C4850 {
    Object_00047470 **models;
};

void *func_00025700(unsigned int index, int first, int second, int third);
void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAC70(Rotation_000D2B90 *rotation);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);

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

// The child of Node with the table at 0x1CDE20 (constructor func_000C4850, 0xc0 bytes; its implicit destructor and
// deleting destructor are folded into the camera node's, 0x121D0 and 0x121B0): a model (0x78) thrown from a position
// (0x44) along a velocity (0x50) at a speed (0x68) and rise (0x6c), turned by three angles (0x5c), that bounces off
// what its collision item (0x7c) hits and fades (0x70) once it has landed (0x74).
struct Object_000C4850 : Node {
    Object_000C4850(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction, int angle);
    virtual ~Object_000C4850();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_40[4];
    Vector3 position;
    Vector3 velocity;
    int angleX;
    int angleY;
    int angleZ;
    float speed;
    float rise;
    float alpha;
    int landed;
    Object_00047470 *model;
    Item_00016260 item;

    void func_000C4A90(Contact_000C4A90 *contact, int first);
};

// Builds the Node part, takes model 4 of sprite set 5 (func_00025700), starts at the position with the angle at 0x60,
// and sends the direction out turned a quarter turn about y (the other way when the x of the position is odd) as its
// velocity (func_001BAC70, func_001BAC00); the collision item starts empty with mask 0xffff.
Object_000C4850::Object_000C4850(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction,
                                 int angle) : Node(owner, id, flags)
{
    model = ((Sprite_000C4850 *)func_00025700(5, 5, 0, 0))->models[4];
    this->position = *position;
    angleZ = 0;
    angleX = 0;
    angleY = angle;
    speed = 0.46296296f;
    rise = 0.8333333f;
    alpha = 1.0f;
    landed = 0;
    Rotation_000D2B90 rotation;
    rotation.axis.x = 0.0f;
    rotation.axis.y = 1.0f;
    rotation.axis.z = 0.0f;
    rotation.angle = 0x4000;
    if ((int)this->position.x & 1) {
        rotation.angle = -0x4000;
    }
    func_001BAA00();
    func_001BAC70(&rotation);
    func_001BAC00(&velocity, direction);
    func_001BAA50();
    memset(&item, 0, sizeof item);
    item.mask = 0xffff;
}
