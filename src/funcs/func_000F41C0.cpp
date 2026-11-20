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

void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);

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
    char unknown_060[4];
    Vector3 velocity;
    char unknown_070[0x30];
    Item_00016260 item;
    Box_00017CC0 box;
    char unknown_0c0[0xc];
    int value_cc;

    void func_000F41C0();
};

// Moves the position at 0x54 along the velocity at 0x64 by 2.7777777 less the value at 0xb4 of data_00257CE4 (at
// least 0.46296296, func_0014C730), boxes the start at 0x48 raised by 10 and the position lowered by 10 into 0xa8
// (func_00017CC0) and hands data_0022FCE8 the item at 0xa0 with -1.
void Object_000F44E0::func_000F41C0()
{
    float scale = 2.7777777f - data_00257CE4->value_b4;
    if (scale < 0.46296296f) {
        scale = 0.46296296f;
    }
    func_0014C730(&position, &velocity, scale);
    Vector3 points[2];
    points[0] = start;
    points[0].y += 10.0f;
    points[1] = position;
    points[1].y -= 10.0f;
    data_0022FCE8.func_00017CC0(&box, points, 2);
    data_0022FCE8.func_00016260(&item, -1);
}
