struct Game {
    void *func_000128C0(int id);
    void func_000127C0(int first, int second);
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

extern unsigned int data_00251EE8;

struct Object_0004D8C0 {
    void func_0004D900(int first, int second);
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

    void func_00053E20();
};

// State handler 112 of the table at 0x1F9888: while the object whose id is at +0xfc8 exists, takes it out when a button
// of mask 5 at 0x251EE8 is down; once it is gone, releases registration (1, 0) of 0x1FA05C (func_0004D900),
// func_000127C0 (0xd, func_000127E0 (0x1ac)) of the game and state 0x71.
void Object_0004ABA0::func_00053E20()
{
    int pressed = 0;
    if (data_00251EE8 & 5)
        pressed = 1;
    Node *object = (Node *)data_0022FCE0->func_000128C0(unknown_fc8);
    if (object) {
        if (pressed) {
            object->func_00011BE0(object);
            object->func_00011C20(object->child);
        }
    } else {
        data_001FA05C.func_0004D900(1, 0);
        data_0022FCE0->func_000127C0(0xd, data_0022FCE0->func_000127E0(0x1ac));
        state = 0x71;
    }
}
