/* sym: ?func_00011C90_4@Object_00113700@@UAEXXZ = 0x00113710 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// The class whose table is at 0x1D2AE8 (destructor 0x113700): this unit's function is its override of Node's
// slot 7.
struct Object_00113700 : Node {
    virtual ~Object_00113700();
    virtual void func_00011C90_4();

    char unknown_44[0x10c];
    float phase;
    float speed;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Slot 7: unless object 0x1167 exists, runs func_00011BE0 and func_00011C20 on the node; then moves the phase at
// +0x150 by its speed / 30, turning down at 1.5 and up at 0.
void Object_00113700::func_00011C90_4()
{
    if (!data_0022FCE0->func_000128C0(0x1167) && this) {
        func_00011BE0(this);
        func_00011C20(child);
    }
    phase += speed * (1.0f / 30.0f);
    if (speed > 0.0f) {
        if (phase >= 1.5f) {
            phase = 1.5f;
            speed = -1.0f;
        }
    } else if (phase <= 0.0f) {
        phase = 0.0f;
        speed = 1.0f;
    }
}
