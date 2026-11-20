/* sym: ?func_00011C90@Object_00101180@@UAEXXZ = 0x00101180 */
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// The child of Node whose table is at 0x1D1D48 (constructor func_00100F40, destructor func_00101100): slots 1, 2
// and 3 run the handlers of the current state from three tables.
struct Object_00101180 : Node {
    char unknown_40[4];
    int state;

    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int event);
};

extern void (Object_00101180::*data_0021FFA0[])();

// Overrides Node's slot 1: runs the handler of the current state.
void Object_00101180::func_00011C90()
{
    (this->*data_0021FFA0[state])();
}
