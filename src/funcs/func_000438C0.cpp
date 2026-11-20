/* sym: ?func_00011C90@Object_00043860@@UAEXXZ = 0x000438C0 */
struct Object_00039BE0 {
    int func_00039DB0(int kind, int id);
};

extern Object_00039BE0 data_001EFFB0;

struct Item_000162A0;

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
};

extern Object_00016200 data_0022FCE8;

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

// The class whose table is at 0x1CA6C8 (constructor 0x43710, destructor 0x43860): overrides slot 1.
struct Object_00043860 : Node {
    virtual void func_00011C90();

    char unknown_044[0xc];
    int unknown_50;
    char unknown_054[0xc];
    int unknown_60;
    int unknown_64;
    char unknown_068[0xc];
    char item[0x24];
};

// Slot 1: while +0x60 is set, clears it once func_00039DB0 of 0x1EFFB0 says so for kind 3 and the id at +0x50; while
// it and +0x64 stay set, hands the item at +0x74 to func_000162A0 of 0x22FCE8.
void Object_00043860::func_00011C90()
{
    if (unknown_60) {
        if (data_001EFFB0.func_00039DB0(3, unknown_50))
            unknown_60 = 0;
        if (unknown_60 && unknown_64)
            data_0022FCE8.func_000162A0((Item_000162A0 *)item);
    }
}
