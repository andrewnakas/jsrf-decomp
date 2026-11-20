/* sym: ?func_00011C90_4@Object_00115E20@@UAEXXZ = 0x00115E30 */
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

struct Object_00115EE0 {
    char unknown_000[0x12c];
    unsigned int flags;
};

// The class whose table is at 0x1D3770 (destructor 0x115E20): this unit's function is its override of Node's
// slot 7.
struct Object_00115E20 : Node {
    virtual ~Object_00115E20();
    virtual void func_00011C90_4();

    int text;
    char unknown_48[4];
    int value_4c;
    char unknown_50[4];
    float x;
    int value_58;
    char unknown_5c[4];
    float step;
    float width;
    char unknown_68[4];
    int state;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
float func_0003D750(float scale, int text);

// Slot 7: unless object 0x1167 exists without bit 30 of its flags (then it only runs func_00011BE0 and
// func_00011C20 on the node), scrolls the text: state 0 starts it at x 640 with the width func_0003D750 gives,
// then each step moves it left and wraps it once it has left the screen.
void Object_00115E20::func_00011C90_4()
{
    Object_00115EE0 *object = (Object_00115EE0 *)data_0022FCE0->func_000128C0(0x1167);
    if (!object) {
        if (this) {
            func_00011BE0(this);
            func_00011C20(child);
        }
        return;
    }
    if (object->flags & 0x40000000) {
        if (this) {
            func_00011BE0(this);
            func_00011C20(child);
        }
        return;
    }
    switch (state) {
    case 0:
        x = 640.0f;
        value_58 = value_4c;
        width = func_0003D750(1.0f, text);
        state = 1;
    case 1:
        x -= step;
        if (x < -width) {
            x = 640.0f;
        }
        break;
    }
}
