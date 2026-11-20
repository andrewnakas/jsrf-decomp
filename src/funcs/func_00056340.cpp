/* sym: ?func_00011C90_2@Object_000511B0@@UAEXXZ = 0x00056340 */
/* sym: ??1Object_00051480@@UAE@XZ = 0x00051480 */
/* sym: ?func_00011C90_3@Object_00051480@@UAEXXZ = 0x00051490 */
/* sym: ?func_00011C80_1@Object_00051480@@UAEXH@Z = 0x000515B0 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The class whose table at 0x1CD088 holds only its scalar deleting destructor 0x84160 (constructor 0x84010); its
// methods 0x800D0, 0x80110, 0x80150, 0x801F0 and 0x841C0 work on the game object named by the id at +8.
struct Object_000800D0 {
    void func_000800D0(int mode);
    void func_00080150(int first, int second, int third);
    int func_000801F0();
};

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    char unknown_44[0x50];
    int unknown_94;
};

// The class whose table is at 0x1CAE68 (destructor 0x51480; 0x9c bytes): overrides slots 5 and 6.
struct Object_00051480 : Object_00012170 {
    Object_00051480(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
    {
        unknown_98 = 0;
    }
    virtual ~Object_00051480();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);

    int unknown_98;
};

// The class whose table is at 0x1CADE8 (constructor 0x561C0, destructor 0x511B0; 0x58 bytes): overrides slot 4.
struct Object_000511B0 : Node {
    virtual ~Object_000511B0();
    virtual void func_00011C90_2();

    int state;
    Object_000800D0 *part;
    int handle;
    void *position;
    int *rotation;
};

// Slot 4, by the state at +0x44. 0: the part to mode 0xc1 and func_00080150(1, 5, 9), an Object_00051480 child (id
// -1, flags 1), state 1. 1: while the object at +0x4c exists, mode 0xc1; once it is gone mode 0xc2,
// func_00080150(1, 5, 0xc), state 2. 2: mode 0xc2, taking the node out first when the part's func_000801F0 says so.
void Object_000511B0::func_00011C90_2()
{
    switch (state) {
    case 0:
        part->func_000800D0(0xc1);
        part->func_00080150(1, 5, 9);
        new Object_00051480(this, -1, 1);
        break;
    case 1:
        if (!data_0022FCE0->func_000128C0(handle)) {
            part->func_000800D0(0xc2);
            part->func_00080150(1, 5, 0xc);
            break;
        }
        part->func_000800D0(0xc1);
        return;
    case 2:
        if (part->func_000801F0()) {
            func_00011BE0(this);
            func_00011C20(child);
        }
        part->func_000800D0(0xc2);
        return;
    default:
        return;
    }
    state++;
}
