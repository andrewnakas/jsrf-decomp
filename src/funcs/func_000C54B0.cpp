/* sym: ?func_00011C90_11@Object_000C5490@@UAEXXZ = 0x000C54B0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1270 {
    int func_000C1160(int kind, int count, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

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

// The child of Node whose table is at 0x1CDE60 (constructor func_000C4CF0, destructor func_000C4E50): it
// overrides slots 1, 2, 3, 12 and 15 and adds three empty slots, 16 to 18.
struct Object_000C4CF0 : Node {
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
    virtual void func_00011C90_10();
    virtual void func_00011C90_11();
    virtual void func_00011C90_12();
};

Node *func_000C70A0(Node *owner, int value, int kind);

// The child of func_000C4CF0's class with the table at 0x1CDF50 (constructor func_000C53D0).
struct Object_000C5490 : Object_000C4CF0 {
    char unknown_40[4];
    Vector3 unknown_44;
    char unknown_50[0x34];
    int unknown_84;

    virtual void func_00011C90_10();
    virtual void func_00011C90_11();
};

// Overrides slot 17: when the field at 0x84 is set, makes an object of kind 1 at the point at 0x44
// (func_000C70A0), calls func_000C1160 of data_00257CE4 with 0x2b and 3 there, and marks itself and everything
// below it as dead.
void Object_000C5490::func_00011C90_11()
{
    if (unknown_84) {
        func_000C70A0(0, (int)&unknown_44, 1);
        data_00257CE4->func_000C1160(0x2b, 3, &unknown_44);
        func_00011BE0(this);
        func_00011C20(child);
    }
}
