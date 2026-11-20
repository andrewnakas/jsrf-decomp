/* sym: ?func_00011C90_1@Object_000F44E0@@UAEXXZ = 0x000F44E0 */
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

// The child of Node whose table is at 0x1CF098.
struct Object_000F44E0 : Node {
    char unknown_40[4];
    unsigned int state;
    char unknown_48[0xa8];
    int target;


    virtual void func_00011C90_1();
};

// Overrides Node's slot 2: below state 3, a target at 0xf0 moves it to state 3.
void Object_000F44E0::func_00011C90_1()
{
    if (state < 3 && target) {
        state = 3;
    }
}
