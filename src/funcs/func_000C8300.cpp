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
    int unknown_40;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240), with the second base Object_000C60C0
// at 0x44.
struct Object_000C7910 : Node, Object_000C60C0 {
    virtual void func_000C8300();

    char unknown_48[0x48];
    unsigned int flags;
    char unknown_94[0x58];
    int timer;
    char unknown_f0[0x84];
    unsigned int blinks;
    float shown;
    float fade;
};

// Slot 45: fades the value at 0x17c to 0 by 1/180 a frame; every 4th frame (timer at 0xec) shows it at 0x178 on odd
// blinks (0 on even ones), and after 45 blinks unlinks (slot 1 of the second base), takes itself out of the tree
// (func_00011BE0, then func_00011C20 on its child) and sets flag 0x20.
void Object_000C7910::func_000C8300()
{
    if (fade > 0.0f) {
        fade -= 0.0055555557f;
        if (fade < 0.0f)
            fade = 0.0f;
    }
    if (++timer >= 4) {
        timer = 0;
        if (blinks & 1)
            shown = fade;
        else
            shown = 0.0f;
        if (++blinks >= 45) {
            func_000C60C0();
            func_00011BE0(this);
            func_00011C20(child);
            flags |= 0x20;
        }
    }
}
