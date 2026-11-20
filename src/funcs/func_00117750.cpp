/* sym: ?func_00011C90_2@Object_00117510@@UAEXXZ = 0x00117750 */
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
};

struct Object_00117510 : Node {
    virtual ~Object_00117510();
    virtual void func_00011C90_2();

    char unknown_034[0x3d8];
    int value_40c;
};

void func_001168F0();

// Slot 4 of the table at 0x1D7778: calls func_001168F0 and sets the word at +0x40c to -1.
void Object_00117510::func_00011C90_2()
{
    func_001168F0();
    value_40c = -1;
}
