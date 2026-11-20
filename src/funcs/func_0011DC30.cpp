/* sym: ?func_00011C90@Object_0011DC20@@UAEXXZ = 0x0011DC30 */
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

struct Animation_0011DC30 {
    short unknown_0;
    short frames;
};

struct Object_00067380 {
    int func_00067380(int index);
};

// The class whose table is at 0x1D8CD0 (destructor 0x11DC20): this unit's function is its override of Node's
// slot 1.
struct Object_0011DC20 : Node {
    virtual ~Object_0011DC20();
    virtual void func_00011C90();

    int unknown_44;
    int current;
    int shown;
    char unknown_50[0x1c];
    Animation_0011DC30 *cursor;
    float cursorFrame;
    char unknown_74[0x10];
    Animation_0011DC30 *marker;
    float markerFrame;
    char unknown_8c[0xc];
    unsigned int state;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
int func_00119540(int group, int index, void *position);

// Slot 1: in state 0 or 1 takes the current entry of object 0x12af (func_00067380(1)) and goes to state 3; in
// state 3 plays entry 3 of group 8 when the entry changed, and steps both animations.
void Object_0011DC20::func_00011C90()
{
    Object_00067380 *menu = (Object_00067380 *)data_0022FCE0->func_000128C0(0x12af);
    switch (state) {
    case 0:
    case 1:
        state = 3;
        current = menu->func_00067380(1);
        shown = current;
        cursorFrame = 0;
        markerFrame = 0;
    case 3:
        current = menu->func_00067380(1);
        if (current != shown) {
            func_00119540(8, 3, 0);
            shown = current;
        }
        if (marker) {
            markerFrame += 1.0f;
            if (markerFrame >= marker->frames) {
                markerFrame = 0;
            }
        }
        if (cursor) {
            cursorFrame += 1.0f;
            if (cursorFrame >= cursor->frames) {
                cursorFrame = 0;
            }
        }
        break;
    }
}
