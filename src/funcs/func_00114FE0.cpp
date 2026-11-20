/* sym: ?func_00011C90_4@Object_00114FD0@@UAEXXZ = 0x00114FE0 */
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
};

struct Animation_00114FE0 {
    short unknown_0;
    short frames;
};

struct Object_00114FD0 : Node {
    virtual ~Object_00114FD0();
    virtual void func_00011C90_4();

    char unknown_034[0x94];
    Animation_00114FE0 *animation;
    float frame;
};

// Slot 7 of the table at 0x1D2B68: advances the frame by one and wraps it to 0 at the last frame.
void Object_00114FD0::func_00011C90_4()
{
    frame += 1.0f;
    if (frame >= animation->frames - 1.0f) {
        frame = 0;
    }
}
