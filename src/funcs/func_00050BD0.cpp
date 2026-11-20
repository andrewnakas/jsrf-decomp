/* sym: ??0Object_00050C90@@QAE@PAUNode@@HIPBUVector3@@1PBH@Z = 0x00050BD0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??1Object_00050C90@@UAE@XZ = 0x00050C90 */
/* sym: ?func_00011C90_2@Object_00050C90@@UAEXXZ = 0x00050CA0 */
/* sym: ?func_00011C80_1@Object_00050C90@@UAEXH@Z = 0x00050CC0 */
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

void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1CACE0 (constructor 0x50BD0): a model at a position, moved by a velocity and
// spinning. Overrides slots 4 and 6 of Node.
struct Object_00050C90 : Node {
    Object_00050C90(Node *owner, int id, unsigned int flags, const Vector3 *position, const Vector3 *velocity,
                    const int *angles);
    virtual ~Object_00050C90();
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);

    Vector3 velocity;
    int spin[3];
    int angles[3];
    Model_00050CC0 *model;
    Vector3 position;
};

Object_00050C90::Object_00050C90(Node *owner, int id, unsigned int flags, const Vector3 *position,
                                 const Vector3 *velocity, const int *angles)
    : Node(owner, id, flags)
{
    this->flags |= 4;
    this->position = *position;
    this->velocity = *velocity;
    spin[0] = 0;
    spin[1] = 0;
    spin[2] = 0;
    this->angles[0] = angles[0];
    this->angles[1] = angles[1];
    this->angles[2] = angles[2];
    model = (Model_00050CC0 *)func_00025700(0xb, 0, 1, 0);
}
