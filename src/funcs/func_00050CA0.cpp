/* sym: ?func_00011C90_2@Object_00050C90@@UAEXXZ = 0x00050CA0 */
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

// The class whose table is at 0x1CACE0 (constructor 0x50BD0): a model at a position, moved by a velocity and
// spinning. Overrides slots 4 and 6 of Node.
struct Object_00050C90 : Node {
    virtual ~Object_00050C90();
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);

    Vector3 velocity;
    int spin[3];
    int angles[3];
    Model_00050CC0 *model;
    Vector3 position;
};

void __fastcall func_0014C340(Vector3 *vector, const Vector3 *offset);

// Slot 4: moves the position by the velocity and turns the spin by 0xe38.
void Object_00050C90::func_00011C90_2()
{
    func_0014C340(&position, &velocity);
    spin[0] += 0xe38;
}
