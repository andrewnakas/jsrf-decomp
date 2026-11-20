/* sym: ?func_00011C90@Object_0006CE00@@UAEXXZ = 0x0006CAF0 */
struct Object_0006DB80 {
    void func_0006DEB0(int handle, int on);
};

extern Object_0006DB80 data_00251F78;

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

// The class whose table is at 0x1CC158 (constructor 0x6C840, destructor 0x6CE00): overrides slot 1.
struct Object_0006CE00 : Node {
    virtual void func_00011C90();

    char unknown_044[0x1c];
    int unknown_60;
    int unknown_64;
};

// Slot 1: passes the handle at +0x64 to func_0006DEB0 of 0x251F78 with 1 while the word at +0x60 is set, else 0.
void Object_0006CE00::func_00011C90()
{
    if (unknown_60) {
        data_00251F78.func_0006DEB0(unknown_64, 1);
    } else {
        data_00251F78.func_0006DEB0(unknown_64, 0);
    }
}
