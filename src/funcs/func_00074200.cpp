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

struct Object_000FEDB0 {
    void func_000FEF40(int value, int id);
    void func_000FEFE0(int value, int id);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00074260 : Node {
    char unknown_44[0x58];
    unsigned int flags_9c;
    char unknown_a0[8];
    int unknown_a8;
    char unknown_ac[4];
    int target;
    unsigned int flags;
    char unknown_b8[0x28];
    int value;

    void func_00074200();
};

// Once (bit 29 of +0xb4): hands its id and +0xa8 to object 0x1163's func_000FEF40 and func_000FEFE0.
void Object_00074260::func_00074200()
{
    if (!(flags & 0x20000000)) {
        Object_000FEDB0 *object = (Object_000FEDB0 *)data_0022FCE0->func_000128C0(0x1163);
        if (object) {
            object->func_000FEF40(id, unknown_a8);
            object->func_000FEFE0(id, unknown_a8);
            flags |= 0x20000000;
        }
    }
}
