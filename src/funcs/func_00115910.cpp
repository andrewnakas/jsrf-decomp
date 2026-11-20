/* sym: ?func_00011C90_4@Object_00115900@@UAEXXZ = 0x00115910 */
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

struct Animation_00115910 {
    short unknown_0;
    short frames;
};

struct Object_00077B70 {
    int func_00077B70(int index);
};

// The class whose table is at 0x1D2BB0 (destructor 0x115900): this unit's function is its override of Node's
// slot 7.
struct Object_00115900 : Node {
    virtual ~Object_00115900();
    virtual void func_00011C90_4();

    int current;
    int shown;
    char unknown_4c[0x7c];
    unsigned int state;
    char unknown_cc[8];
    Animation_00115910 *animation;
    float frame;
    char unknown_dc[4];
    float phase;
    float speed;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Slot 7: without object 0x1167 runs func_00011BE0 and func_00011C20 on the node; state 1 takes entry 1 of that
// object (func_00077B70) and goes to state 3; state 3 restarts the pulse when the entry changed, steps the
// animation and swings the phase at +0xe0 between 0 and 1 at its speed / 30.
void Object_00115900::func_00011C90_4()
{
    Object_00077B70 *object = (Object_00077B70 *)data_0022FCE0->func_000128C0(0x1167);
    if (!object && this) {
        func_00011BE0(this);
        func_00011C20(child);
    }
    switch (state) {
    case 1:
        state = 3;
        current = object->func_00077B70(1);
        shown = current;
        phase = 0;
    case 3:
        current = object->func_00077B70(1);
        if (current != shown) {
            shown = current;
            phase = 0;
            speed = 1.0f;
        }
        if (animation) {
            frame += 1.0f;
            if (frame >= animation->frames) {
                frame = 0;
            }
        }
        phase += speed * (1.0f / 30.0f);
        if (speed > 0.0f) {
            if (phase >= 1.0f) {
                phase = 1.0f;
                speed *= -1.0f;
            }
        } else if (phase <= 0.0f) {
            phase = 0;
            speed *= -1.0f;
        }
        break;
    }
}
