/* sym: ?func_00011C90_11@Object_000C5500@@UAEXXZ = 0x000C5610 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

struct Object_000607B0 {
    int func_000651E0(int kind, void *position, Vector3 *direction);
};

extern Game *data_0022FCE0;

// The object at data_00257CE4.
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

// The child of func_000C4CF0's class with the table at 0x1CDFA0 (constructor func_000C5500).
struct Object_000C5500 : Object_000C4CF0 {
    char unknown_40[4];
    Vector3 unknown_44;
    char unknown_50[0x18];
    Vector3 unknown_68;
    char unknown_74[0x10];
    int unknown_84;

    virtual void func_00011C90_11();
};

// Overrides slot 17: when the field at 0x84 is set, tells object 0xe8 (func_000651E0, kind 0x1f) about the
// point at 0x44 and the vector at 0x68, passes kind 0x25 and 0x10 with the point to func_000C1160 of data_00257CE4,
// and marks itself and everything below it as dead.
void Object_000C5500::func_00011C90_11()
{
    if (unknown_84) {
        Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (target) {
            target->func_000651E0(0x1f, &unknown_44, &unknown_68);
        }
        data_00257CE4->func_000C1160(0x25, 0x10, &unknown_44);
        func_00011BE0(this);
        func_00011C20(child);
    }
}
