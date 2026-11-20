/* sym: ?func_00011C90_1@Object_000967E0@@UAEXXZ = 0x00096980 */
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

// One of two direct children of Node with the same slots 2, 3, 5 and 6 (tables 0x1CD360 and 0x1CD3E0); this one
// has the table at 0x1CD360 (constructor func_000967E0).
struct Object_000967E0 : Node {
    virtual ~Object_000967E0();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);

    char unknown_040[0xf08];
    int timer;
    int alpha;
};

// Overrides slot 2: the alpha at 0xf4c is 0x100 from 60 frames left (at 0xf48) and fades with them; the frames
// count down, and past 0 it marks itself and everything below it as dead.
void Object_000967E0::func_00011C90_1()
{
    int left = timer;
    if (left < 60) {
        alpha = (left << 8) / 60;
    } else {
        alpha = 0x100;
    }
    timer = left - 1;
    if (left - 1 < 0) {
        func_00011BE0(this);
        func_00011C20(child);
    }
}
