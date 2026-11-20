/* sym: ?func_00011C90@Object_000C4850@@UAEXXZ = 0x000C4960 */
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

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
};

extern Object_00016200 data_0022FCE8;

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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

// Slot 1: once faded out removes itself and everything below it (func_00011BE0, func_00011C20); after landing fades by
// a 120th down to 0. Moves by its velocity times the speed in x and z and by the rise in y, the rise falling by a
// 36th, and puts its collision box around the new position (func_00017D90, radius 4; func_00016260).
void Object_000C4850::func_00011C90()
{
    if (alpha <= 0.0f) {
        func_00011BE0(this);
        func_00011C20(child);
    } else if (landed) {
        alpha -= 0.008333334f;
        if (alpha < 0.0f) {
            alpha = 0.0f;
        }
    }
    position.x += velocity.x * speed;
    position.z += velocity.z * speed;
    position.y += rise;
    rise -= 0.027777778f;
    data_0022FCE8.func_00017D90(&item.box, &position, 1, 4.0f);
    data_0022FCE8.func_00016260(&item, -1);
}
