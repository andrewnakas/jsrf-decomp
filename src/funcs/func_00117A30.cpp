/* sym: ??1Object_00117A30@@UAE@XZ = 0x00117A30 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00117A30@@UAEXXZ = 0x00117AB0 */
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
    char unknown_34[0x60];
};

struct Sound_00117AB0 {
    int group;
    int index;
};

extern Sound_00117AB0 data_002227A8[];
int func_001186A0(int id, unsigned int index);

// The class whose table is at 0x1D77B8: overrides slot 1 of Node.
struct Object_00117A30 : Node {
    virtual ~Object_00117A30();
    virtual void func_00011C90();
};

// Runs func_001186A0 for each sound of data_002227A8 (group, entry) up to the first negative group.
Object_00117A30::~Object_00117A30()
{
    for (int i = 0; data_002227A8[i].group >= 0; i++) {
        func_001186A0(data_002227A8[i].group, data_002227A8[i].index);
    }
}
