/* sym: ?func_00011C90@Object_0011CC70@@UAEXXZ = 0x0011CC80 */
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

struct Animation_0011CC80 {
    short unknown_0;
    short frames;
};

struct Object_00074E50 {
    int func_00074E50(int index);
    int func_00074EA0(int index, int entry);
};

// The class whose table is at 0x1D8898 (destructor 0x11CC70): this unit's function is its override of Node's
// slot 1.
struct Object_0011CC70 : Node {
    virtual ~Object_0011CC70();
    virtual void func_00011C90();

    int unknown_44;
    int current;
    int shown;
    int values[3];
    int shownValues[3];
    char unknown_68[0x48];
    Animation_0011CC80 *animation;
    float frame;
    char unknown_b8[4];
    float speed;
    float timer;
    unsigned int state;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
int func_00119540(int group, int index, void *position);

// Slot 1: in state 0 or 1 takes entry 13 of object 0x128a (func_00074E50) and its three values (func_00074EA0)
// and goes to state 3; state 3 plays entry 3 of group 8 when the entry changed and entry 8 for each value that
// changed, steps the animation and counts the timer at +0xc0 down by 1/60, from 0.5.
void Object_0011CC70::func_00011C90()
{
    Object_00074E50 *menu = (Object_00074E50 *)data_0022FCE0->func_000128C0(0x128a);
    int i;
    switch (state) {
    case 0:
    case 1:
        state = 3;
        current = menu->func_00074E50(13);
        shown = current;
        for (i = 0; i < 3; i++) {
            values[i] = menu->func_00074EA0(13, i);
            shownValues[i] = values[i];
        }
        frame = 0;
        timer = 0.5f;
    case 3:
        current = menu->func_00074E50(13);
        if (current != shown) {
            func_00119540(8, 3, 0);
            shown = current;
            timer = 0.5f;
            speed = 1.0f;
        }
        for (i = 0; i < 3; i++) {
            values[i] = menu->func_00074EA0(13, i);
            if (values[i] != shownValues[i]) {
                func_00119540(8, 8, 0);
                shownValues[i] = values[i];
            }
        }
        if (animation) {
            frame += 1.0f;
            if (frame >= animation->frames) {
                frame = 0;
            }
        }
        timer -= 1.0f / 60.0f;
        if (timer < 0.0f) {
            timer = 0.5f;
        }
        break;
    }
}
