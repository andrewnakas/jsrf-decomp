/* sym: ?func_00011C80@Object_00074C60@@UAEXH@Z = 0x00074CB0 */
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

struct Object_0006A720 {
    int func_0006A720();
    void func_0006A770();
    void func_0006A7C0();
    void func_0006B6A0();
    void func_0006B8F0();
    void func_0006BA80();
    float func_0006C360();
};
struct Item_00016200 {
    int unknown_00;
    Item_00016200 *next;
};

int func_0004EA70();

// The class whose table is at 0x1CCC98: overrides slots 1 (74C70), 3 (74CB0), 6 (B3DE0), 12 (B3DE0), 15 (B3DE0).
struct Object_00074C60 : Node {
    virtual ~Object_00074C60();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Object_0006A720 *model;
    Item_00016200 first;
    Item_00016200 second;
};

// Slot 3: the model's handler for each message.
void Object_00074C60::func_00011C80(int argument)
{
    switch (argument) {
    case 0:
        model->func_0006B6A0();
        break;
    case 1:
        model->func_0006B8F0();
        break;
    case 7:
        depth = model->func_0006C360();
        break;
    case 8:
        model->func_0006A7C0();
        break;
    case 0x11:
    case 0x12:
        if (func_0004EA70() & 0x100) {
            model->func_0006BA80();
        }
        break;
    }
}
