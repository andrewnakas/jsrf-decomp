struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

struct Item_00016260 {
    int unknown_00;
    int value;
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
};

extern Object_00016200 data_0022FCE8;

// The object at data_00257CE4 (only the field used here).
struct Object_000C1270 {
    char unknown_00[0xb4];
    float value_b4;
};

extern Object_000C1270 *data_00257CE4;

// A place on a path (func_000C1820): the path, the point reached, the segment, the distance along it, the
// direction of travel.
struct Path_000C1820 {
    void *path;
    Vector3 point;
    int segment;
    float distance;
    int reverse;
    int unknown_1c;
};

// The object in data_00257CE8 (its callers load `ecx` from there; this function does not read it).
struct Object_00157F10 {
    int func_000C1820(Path_000C1820 *path, float step, Vector3 *direction);
};

extern Object_00157F10 *data_00257CE8;

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
int func_0014C7D0(float x, float z);

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
};

// The child of Node whose table is at 0x1CF098 (destructor func_000F3F70): its slot 1 (func_000F4480) runs entry
// `state` of the member-function table at 0x21b2dc on itself.
struct Object_000F44E0 : Node {
    char unknown_040[4];
    int state;
    Vector3 start;
    Vector3 position;
    int angle;
    Vector3 velocity;
    char unknown_070[4];
    Path_000C1820 path;
    char unknown_094[0xc];
    Item_00016260 item;
    Box_00017CC0 box;
    char unknown_0c0[0xc];
    int value_cc;

    void func_000F4280();
};

// Moves along the path at 0x74 (func_000C1820 of data_00257CE8) by 2.7777777 less the value at 0xb4 of
// data_00257CE4 (at least 0.46296296), from the position at 0x54 (kept at 0x48) to the point reached; state 1 at
// the path's end. The angle at 0x60 turns towards the point 15 further on the way back (func_0014C7D0).
void Object_000F44E0::func_000F4280()
{
    float scale = 2.7777777f - data_00257CE4->value_b4;
    if (scale < 0.46296296f) {
        scale = 0.46296296f;
    }
    start = position;
    if (data_00257CE8->func_000C1820(&path, scale, &velocity)) {
        state = 1;
    }
    position = path.point;
    Path_000C1820 ahead = path;
    ahead.reverse = !ahead.reverse;
    Vector3 direction;
    data_00257CE8->func_000C1820(&ahead, 15.0f, &direction);
    func_0014C4C0(&direction, &position, &ahead.point);
    if (direction.x != 0.0f || direction.z != 0.0f) {
        angle = func_0014C7D0(direction.x, direction.z);
    }
}
