/* sym: ??0Object_00050B70@@QAE@PAUNode@@HIPAX1@Z = 0x00050AB0 */
/* sym: ??1Object_00050B70@@UAE@XZ = 0x00050B70 */
/* sym: ?func_00011C90_2@Object_00050B70@@UAEXXZ = 0x00055DD0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Object_000800D0@@QAE@HPAMPAHH@Z = 0x00084010 */
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

struct Game {
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

// The class whose table at 0x1CD088 holds only its scalar deleting destructor 0x84160 (constructor 0x84010); its
// methods 0x800D0, 0x80110, 0x80150, 0x801F0 and 0x841C0 work on the game object named by the id at +8.
struct Object_000800D0 {
    Object_000800D0(int value, float *position, int *rotation, int unused);
    virtual ~Object_000800D0();

    void *block;
    int id;
};

// The class whose table is at 0x1CACA0 (constructor 0x50AB0, destructor 0x50B70; 0x58 bytes): overrides slot 4.
struct Object_00050B70 : Node {
    Object_00050B70(Node *owner, int id, unsigned int flags, void *first, void *second);
    virtual ~Object_00050B70();
    virtual void func_00011C90_2();

    int unknown_44;
    Object_000800D0 *part;
    int unknown_4c;
    float *position;
    int *rotation;
};

// Made by 0x53D40 with a stage record's position and angles: keeps them at +0x50 / +0x54 and makes the part at
// +0x48 from them (Object_000800D0 with the game's value 0xd).
Object_00050B70::Object_00050B70(Node *owner, int id, unsigned int flags, void *first, void *second)
    : Node(owner, id, flags)
{
    unknown_44 = 0;
    position = (float *)first;
    rotation = (int *)second;
    unknown_4c = -1;
    part = new Object_000800D0(data_0022FCE0->func_000127E0(0xd), position, rotation, 0);
}
