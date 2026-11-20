struct Game {
    void func_000127C0(int first, int second);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

int func_00024650();

struct Object_0004F0B0 {
    char unknown_00[0x48];
    unsigned int unknown_48;
};

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

struct Object_0004ABA0 : Node {
    void func_00053C40();
};

// State handler 96 of the table at 0x1F9888: once func_00024650 says so and object 10 exists with its word at +0x48 at
// least 1, func_000127C0 of the game (10, 0) and takes the object out.
void Object_0004ABA0::func_00053C40()
{
    if (func_00024650()) {
        Object_0004F0B0 *object = (Object_0004F0B0 *)data_0022FCE0->func_000128C0(10);
        if (object && object->unknown_48 >= 1) {
            data_0022FCE0->func_000127C0(10, 0);
            if (this) {
                func_00011BE0(this);
                func_00011C20(child);
            }
        }
    }
}
