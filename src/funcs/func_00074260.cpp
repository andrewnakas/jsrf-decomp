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

struct Object_00107FE0 {
    char unknown_0000[0x1700];
    unsigned int flags;
    int unknown_1704;

    void func_001077C0(int value);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00074260 : Node {
    char unknown_44[0x58];
    unsigned int flags_9c;
    char unknown_a0[0x10];
    int target;
    unsigned int flags;
    char unknown_b8[0x28];
    int value;

    void func_00074200();
    void func_00074260();
};

// Unless already ended (top bit of +0xb4): runs func_00074200 when +0x9c has bit 26, hands +0xe0 to its target object
// and, unless +0xb4 has bit 30, runs the target's func_001077C0(0x13) and marks it; then ends the node.
void Object_00074260::func_00074260()
{
    if (!(flags & 0x80000000)) {
        if (flags_9c & 0x4000000) {
            func_00074200();
        }
        Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(target);
        if (object) {
            object->unknown_1704 = value;
            if (!(flags & 0x40000000)) {
                object->func_001077C0(0x13);
                object->flags |= 0x40000000;
            }
        }
        flags |= 0x80000000;
        func_00011BE0(this);
        func_00011C20(child);
    }
}
