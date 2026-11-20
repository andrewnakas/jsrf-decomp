/* sym: ?func_00011C90_2@Object_00050EC0@@UAEXXZ = 0x00050ED0 */
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
    char unknown_34[0x10];
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Model_00050CC0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

// The class whose table is at 0x1CAD60 (constructor 0x56080): a model at a position, pushed out by a distance that
// grows by a shrinking speed, and spinning. Overrides slots 4 and 6 of Node.
struct Object_00050EC0 : Node {
    virtual ~Object_00050EC0();
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);

    float speed;
    Model_00050CC0 *model;
    Vector3 position;
    int angles[3];
    int spin[3];
    float distance;
};

// Slot 4: adds the speed to the distance, turns the spin by 0xe38 and slows down.
void Object_00050EC0::func_00011C90_2()
{
    distance += speed;
    spin[0] += 0xe38;
    speed -= 0.0038580247f;
}
