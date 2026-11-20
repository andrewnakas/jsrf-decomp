/* sym: ?func_00011C90@Object_0010F620@@UAEXXZ = 0x0010F620 */
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

    Node *func_00011BD0();
};

struct Owner_0010F620 : Node {
    char unknown_040[0xa0];
    int value_e0;
};

// The child of Node whose table is at 0x1D24F0 (destructor func_0010F610).
struct Object_0010F620 : Node {
    char unknown_040[0x28];
    int value_68;
    float timer;

    virtual void func_00011C90();
};

// Overrides Node's slot 1: advances the timer at 0x6c by 1/60 and wraps it at 0.5; restarts it when the
// parent's field at 0xe0 changes, keeping a copy at 0x68.
void Object_0010F620::func_00011C90()
{
    timer += 0.016666668f;
    if (timer >= 0.5f) {
        timer = 0.0f;
    }
    Owner_0010F620 *owner = (Owner_0010F620 *)func_00011BD0();
    if (owner && value_68 != owner->value_e0) {
        value_68 = owner->value_e0;
        timer = 0.0f;
    }
}
