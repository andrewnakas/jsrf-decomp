/* sym: ?func_00011C90@Object_00074C60@@UAEXXZ = 0x00074C70 */
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

struct Object_000149B0 {
    int func_000149E0();
};

struct Object_00039BE0 {
    int func_00039CA0();
};

struct Object_00016200 {
    void func_00016200(Item_00016200 *item);
    void func_00016220(Item_00016200 *item);
};

extern Object_00016200 data_0022FCE8;

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

// Slot 1: queues the model's two counts on the lists at 0x22FCE8, then updates the model.
void Object_00074C60::func_00011C90()
{
    first.unknown_00 = ((Object_000149B0 *)model)->func_000149E0();
    data_0022FCE8.func_00016200(&first);
    second.unknown_00 = ((Object_00039BE0 *)model)->func_00039CA0();
    data_0022FCE8.func_00016220(&second);
    model->func_0006A770();
}
