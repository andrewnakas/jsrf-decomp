/* sym: ?func_00011C90_1@Object_000A4D80@@UAEXXZ = 0x000A28B0 */
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

    Node *func_00011BD0();
};

// A camera node (table 0x1C43D8 repeats Node's slots 1 to 15; mask 7): eye, target, field of view and roll.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    Vector3 eye;
    char unknown_50[0xc];
    Vector3 target;
    char unknown_68[0xc];
    unsigned int fov;
    int unknown_78;
    int roll;
    int unknown_80;
    int left;
    int top;
    int width;
    int height;
    int unknown_94;
};

int func_0004A7A0(float x, float z);
float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

// The class whose table is at 0x1CD518 (constructor 0xA4D80, destructor 0xA2820): overrides slots 1 (A5070),
// 2 (A28B0), 3 (A2960), 15 (B3DE0).
struct Object_000A4D80 : Object_00012170 {
    virtual ~Object_000A4D80();
    virtual void func_00011C90_1();

    char unknown_098[0x170];
    int mode;
    Vector3 position;
    Vector3 focus;
    int roll_224;
    int angle;
    unsigned int fov_22c;
    float distance;
};

// The handlers of the modes at +0x208 (0x11C90 where a mode has none).
extern void (Object_000A4D80::*data_002155AC[])();

// Slot 2: runs the handler of the current mode, then copies the position and the focus into the camera's eye and
// target (with the field of view and roll) and keeps the heading and the distance from the position to the focus.
void Object_000A4D80::func_00011C90_1()
{
    void (Object_000A4D80::*handler)() = data_002155AC[mode];
    if (handler) {
        (this->*handler)();
    }
    eye.x = position.x;
    eye.y = position.y;
    eye.z = position.z;
    target.x = focus.x;
    target.y = focus.y;
    target.z = focus.z;
    fov = fov_22c;
    roll = roll_224;
    angle = func_0004A7A0(focus.x - position.x, focus.z - position.z);
    distance = func_0014C530(&focus, &position);
}
