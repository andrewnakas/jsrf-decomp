/* sym: ?func_00011C90@Object_001044F0@@UAEXXZ = 0x00104500 */
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


// A direct child of Node (table 0x1D1ED8, destructor func_001044F0).
struct Object_001044F0 : Node {
    virtual ~Object_001044F0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    int unknown_040;
    int value_44;
    int unknown_048;
    int value_4c;
    int unknown_050;
    int value;
    int state;
    unsigned int count;
    float scale;
    float fade;
};

// Slot 1, while the object has a parent: state 0 resets (count, scale 1, fade 0) and goes to 2; 2 raises the fade
// at 0x64 by 0.1 up to 1 (then 3); 3 waits 120 calls (then 5); 5 lowers the scale at 0x60 by 1/30 down to 0 (then
// 6); 6 unlinks the object (func_00011BE0) and links its child (func_00011C20).
void Object_001044F0::func_00011C90()
{
    if (parent) {
        switch (state) {
        case 0:
            count = 0;
            scale = 1.0f;
            fade = 0.0f;
            state = 2;
        case 2:
            fade += 0.1f;
            if (fade >= 1.0f) {
                fade = 1.0f;
                state = 3;
            }
            break;
        case 3:
            if (++count > 120) {
                state = 5;
            }
            break;
        case 5:
            scale -= 1.0f / 30.0f;
            if (scale < 0.0f) {
                scale = 0.0f;
                state = 6;
            }
            break;
        case 6:
            func_00011BE0(this);
            func_00011C20(child);
            break;
        }
    }
}
