/* sym: ?func_00011C80@Object_000C0A90@@UAEXH@Z = 0x000C04A0 */
struct Object_000C3BE0 {
    void func_000C3BE0();
    void func_000C3CF0();
};

struct Object_000C1270 {
    void func_00011C90_1();
    void func_000C0EF0();
    void func_000C1050();
};

extern Object_000C3BE0 *data_00257CEC;
extern Object_000C1270 *data_00257CE4;

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

// The child of Node whose table is at 0x1CDC18 (constructor func_000C0A90, destructor func_000C0D90): slots 1, 2
// and 3 pass the call on to the objects in data_00257CEC and data_00257CE4, when they exist.
struct Object_000C0A90 : Node {
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
};

// Overrides Node's slot 3; the argument is not used.
void Object_000C0A90::func_00011C80(int)
{
    if (data_00257CEC) {
        data_00257CEC->func_000C3CF0();
    }
    if (data_00257CE4) {
        data_00257CE4->func_000C0EF0();
    }
}
