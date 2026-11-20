/* sym: ?func_00011C90_1@Object_000BE900@@UAEXXZ = 0x000BE900 */
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

    Node *func_00011BD0();
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Owner_000BE900 {
    char unknown_000[0x300];
    Vector3 position;
};

// The child of Node whose table is at 0x1CDB60 (destructor func_000BE8F0).
struct Object_000BE900 : Node {
    char unknown_040[4];
    Vector3 position;
    char unknown_050[0x24];
    int value_74;

    virtual void func_00011C90_1();
};

// Overrides Node's slot 2: takes the parent's position at 0x300 and sets the field at 0x74 to 0x71c.
void Object_000BE900::func_00011C90_1()
{
    Owner_000BE900 *owner = (Owner_000BE900 *)func_00011BD0();
    position.x = owner->position.x;
    position.y = owner->position.y;
    position.z = owner->position.z;
    value_74 = 0x71c;
}
