/* sym: ?func_00011C90@Object_000F97D0@@UAEXXZ = 0x000F9830 */
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
};

// A direct child of Node (table 0x1D07F8, destructor func_000F9820): something that scrolls from x = 640 to the left
// by `speed` each frame and starts again once it is past its own width.
struct Object_000F97D0 : Node {
    virtual ~Object_000F97D0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);

    int unknown_040;
    int kind;
    float first;
    float second;
    int unknown_050;
    float x;
    float y;
    int unknown_05c;
    float speed;
    float width;
    int unknown_068;
    int phase;
    int unknown_070;
};

float func_0003D750(float scale, int kind);

// Slot 1: the first time, starts at x = 640 with y from 0x4c and the width from func_0003D750(1, kind); then moves
// left by the speed and starts again at 640 once x is below minus the width.
void Object_000F97D0::func_00011C90()
{
    switch (phase) {
    case 0:
        x = 640.0f;
        y = second;
        width = func_0003D750(1.0f, kind);
        phase = 1;
    case 1:
        x -= speed;
        if (x < -width) {
            x = 640.0f;
        }
    }
}
