/* sym: ?func_00011C90@Object_00118CB0@@UAEXXZ = 0x00118610 */
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

struct Object_00118CB0 : Node {
    virtual ~Object_00118CB0();
    virtual void func_00011C90();
    virtual void func_00011C90_2();

    void func_00117FC0();
    void func_00118090();
    void func_00118170();
    void func_001185B0();
};

// Override of Node's slot 1 in the class whose table is at 0x1D7B20.
void Object_00118CB0::func_00011C90()
{
    func_00117FC0();
    func_00118170();
    func_001185B0();
}
