struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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
    char unknown_34[0x10];
};

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7: a camera.
struct Object_00012170 : Node {
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

int func_0004A7F0(int from, int to);

// The node class whose table is at 0x1C45C8 (destructor 0x1E140): a camera that moves from one eye to another.
struct Object_0001E140 : Object_00012170 {
    virtual ~Object_0001E140();
    virtual void func_00011C90_7();

    Vector3 lookAt;
    Vector3 startEye;
    Vector3 endEye;
    int startRoll;
    int endRoll;
    unsigned int startFov;
    float value;
    float speed;
    int state;
    unsigned int timer;

    void func_00042890();
};

// Places the camera along the way (eased by 1 - (1 - value)^2): the eye between +0xa4 and +0xb0, the roll between
// +0xbc and +0xc0 (by func_0004A7F0's difference), the target from +0x98 and the fov from +0xc4.
void Object_0001E140::func_00042890()
{
    float t = 1.0f - value;
    float f = 1.0f - t * t;
    Vector3 position;
    position.x = (endEye.x - startEye.x) * f + startEye.x;
    position.y = (endEye.y - startEye.y) * f + startEye.y;
    position.z = (endEye.z - startEye.z) * f + startEye.z;
    int angle = (int)(func_0004A7F0(startRoll, endRoll) * f) + startRoll;
    eye.x = position.x;
    eye.y = position.y;
    eye.z = position.z;
    target.x = lookAt.x;
    target.y = lookAt.y;
    target.z = lookAt.z;
    fov = startFov;
    roll = angle;
}
