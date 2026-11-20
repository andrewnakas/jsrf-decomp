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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};


// The Node child whose table is at 0x1D1D48 (constructor func_00100F40, which runs the handlers of
// data_0021FF98 by the phase at 0x44).
struct Object_00101180 : Node {
    int unknown_040;
    int phase;
    int state;
    char unknown_04c[0x30];
    int angle;
    char unknown_080[4];
    int spin;
    char unknown_088[8];
    float fade;
    char unknown_094[0x18];
    float scaleX;
    float scaleY;
    float scaleZ;

    void func_00101370();
};

// Entry 2 of data_0021FF98: state 0 sets the spin at 0x84 to 0x1555; state 3 raises the fade at 0x90 by 1/60 up to 1
// (then state 6), turns the angle at 0x7c by the spin and scales by 1 + fade; state 6 unlinks the object (func_00011BE0)
// and links its child (func_00011C20).
void Object_00101180::func_00101370()
{
    switch (state) {
    case 0:
        spin = 0x1555;
        break;
    case 3: {
        fade += 1.0f / 60.0f;
        if (fade >= 1.0f) {
            fade = 1.0f;
            state = 6;
        }
        angle += spin;
        float scale = fade + 1.0f;
        scaleX = scale;
        scaleY = scale;
        scaleZ = scale;
        break;
    }
    case 6:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
}
