/* sym: ??1Object_00024240@@UAE@XZ = 0x00024330 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
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

// The node class whose table is at 0x1C4CD0 (stored by its constructor func_00024240); it overrides none of Node's slots.
struct Object_00024240 : Node {
    virtual ~Object_00024240();
};

// Nothing of its own to undo: resets the table pointer and goes on to Node's destructor.
Object_00024240::~Object_00024240()
{
}
