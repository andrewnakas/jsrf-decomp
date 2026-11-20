/* sym: ?func_00011C90@Object_0011D420@@UAEXXZ = 0x0011D430 */
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
};

struct Animation_0011D430 {
    short unknown_0;
    short frames;
};

struct Object_00074E50 {
    int func_00074E50(int index);
};

// The class whose table is at 0x1D8C90 (destructor 0x11D420): this unit's function is its override of Node's
// slot 1.
struct Object_0011D420 : Node {
    virtual ~Object_0011D420();
    virtual void func_00011C90();

    int unknown_44;
    int current;
    int shown;
    char unknown_50[0x40];
    Animation_0011D430 *animation;
    float frame;
    int unknown_98;
    float phase;
    float speed;
    float timer;
    unsigned int state;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
int func_00119540(int group, int index, void *position);

// Slot 1: in state 0 or 1 takes entry 3 of object 0x128a (func_00074E50) and goes to state 3; in state 3 plays
// entry 8 of group 8 and restarts the pulse when the entry changed, steps the animation, swings the phase at
// +0x9c between 0 and 1 at its speed / 30, and counts the timer at +0xa4 down by 1/60, from 0.5.
void Object_0011D420::func_00011C90()
{
    Object_00074E50 *menu = (Object_00074E50 *)data_0022FCE0->func_000128C0(0x128a);
    switch (state) {
    case 0:
    case 1:
        state = 3;
        current = menu->func_00074E50(3);
        shown = current;
        frame = 0;
        phase = 0;
        timer = 0.5f;
    case 3:
        current = menu->func_00074E50(3);
        if (current != shown) {
            func_00119540(8, 8, 0);
            shown = current;
            timer = 0.5f;
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
        timer -= 1.0f / 60.0f;
        if (timer < 0.0f) {
            timer = 0.5f;
        }
        break;
    }
}
