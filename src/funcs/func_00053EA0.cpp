int func_000256C0(unsigned int index, int argument);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A registration: a handler index and its argument, released through func_00025740.
struct Item_0004D8C0 {
    int first;
    int second;
    Item_0004D8C0 *next;
    Item_0004D8C0 **link;
};

struct Object_0004D8C0 {
    int unknown_00;
    Item_0004D8C0 *items;
    Item_0004D8C0 **tail;
};

extern Object_0004D8C0 data_001FA05C;

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

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0xf68];
    int unknown_fc8;

    void func_00053EA0();
};

// State handler 114 of the table at 0x1F9888: once func_000256C0 (1, 0) says so, appends a registration of handler 1
// with 0 to the list at 0x1FA05C, takes out the object whose id is at +0xfc8 (if it exists) and moves to state 0x73.
void Object_0004ABA0::func_00053EA0()
{
    if (func_000256C0(1, 0)) {
        Item_0004D8C0 *item = new Item_0004D8C0;
        item->first = 1;
        item->second = 0;
        *data_001FA05C.tail = item;
        item->link = data_001FA05C.tail;
        data_001FA05C.tail = &item->next;
        item->next = 0;
        Node *object = (Node *)data_0022FCE0->func_000128C0(unknown_fc8);
        if (object) {
            object->func_00011BE0(object);
            object->func_00011C20(object->child);
        }
        state = 0x73;
    }
}
