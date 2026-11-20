/* sym: ?func_00011C90@Object_0011F530@@UAEXXZ = 0x0011F540 */
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

struct Animation_0011F540 {
    short unknown_0;
    short count;
};

struct Object_00074E50 {
    int func_00074E50(int index);
    int func_00074EA0(int index, int value);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

int func_00119540(int first, int second, void *data);
void func_00117350(int first, int second);
void func_001165D0(int value);

// The class whose table is at 0x1D8F88; this is its slot 1.
struct Object_0011F530 : Node {
    char unknown_034[0x14];
    int value_48;
    int value_4c;
    int value_50;
    int value_54;
    char unknown_058[0x18];
    Animation_0011F540 *animation;
    Animation_0011F540 *opening;
    Animation_0011F540 *idle;
    float frame;
    char unknown_080[0x4];
    Animation_0011F540 *cursor;
    float cursorFrame;
    char unknown_08c[0xc];
    int state;

    virtual void func_00011C90();
};

// Slot 1: follows setting 5 of object 0x128A (func_00119540(8, 3) when it changes) while looping the idle
// animation; state 2 plays idle to its end and starts the opening animation (func_001165D0(30)), state 3 plays it
// and applies the setting (func_00117350); the cursor animation loops throughout.
void Object_0011F530::func_00011C90()
{
    Object_00074E50 *settings = (Object_00074E50 *)data_0022FCE0->func_000128C0(0x128a);
    switch (state) {
    case 0:
        state = 1;
        value_48 = settings->func_00074E50(5);
        value_4c = value_48;
        frame = 0.0f;
        cursorFrame = 0.0f;
    case 1:
        value_48 = settings->func_00074E50(5);
        if (value_48 != value_4c) {
            func_00119540(8, 3, 0);
            value_4c = value_48;
        }
        frame += 1.0f;
        if (frame >= idle->count - 1.0f) {
            frame = 0.0f;
        }
        break;
    case 2:
        frame += 1.0f;
        if (frame >= idle->count - 1.0f) {
            frame = 0.0f;
            animation = opening;
            func_001165D0(0x1e);
            state = 3;
        }
        break;
    case 3:
        frame += 1.0f;
        if (frame >= opening->count - 1.0f) {
            frame = 0.0f;
            animation = idle;
            value_54 = value_48;
            value_50 = 1;
            func_00117350(settings->func_00074EA0(5, value_48), 0);
            state = 1;
        }
        break;
    }
    if (cursor) {
        cursorFrame += 1.0f;
        if (cursorFrame >= cursor->count) {
            cursorFrame = 0.0f;
        }
    }
}
