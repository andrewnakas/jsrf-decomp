/* sym: ?func_00011C90@Object_001112A0@@UAEXXZ = 0x001117B0 */
struct Game {
    void *func_000128C0(int id);
};

struct Animation_001117B0 {
    short unknown_00;
    short frames;
};

struct Object_00111DE0 {
    void func_00111DE0(int value);
};

struct Flag_001117B0 {
    char unknown_000[0x148];
    int value_148;
};

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

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

// The class whose table is at 0x1D2788: overrides slots 1, 3 of Node.
struct Object_001112A0 : Node {
    virtual void func_00011C90();

    char unknown_44[0x14];
    Animation_001117B0 *animation;
    float frame;
    char unknown_60[8];
    Animation_001117B0 *overlay;
    float overlayFrame;
    char unknown_70[0xc];
    int state;
    int previous;
    char unknown_84[4];
    int value_88;
    int value_8c;
    int target;

    void func_001115C0();
    int func_001116E0();
};

extern Game *data_0022FCE0;
int func_0006F190();

// Slot 1, by the state at +0x7c: 0 sets state 1 and goes on as 1; 1 runs func_001115C0 when func_001116E0 gives 0;
// 2 waits for +0x88 and then sets state 1 when +0x8c is set, 4 otherwise; 3 returns to the state at +0x80 once
// func_0006F190 gives nonzero; 4 passes 2 to func_00111DE0 of object +0x90, sets +0x148 of object 0x1163 and
// runs func_00011BE0 and func_00011C20 on the node. Then advances the two animation frames (+0x5c, +0x6c),
// wrapping them before the last frame.
void Object_001112A0::func_00011C90()
{
    switch (state) {
    case 0:
        state = 1;
    case 1:
        if (!func_001116E0()) {
            func_001115C0();
        }
        break;
    case 2:
        if (value_88) {
            state = value_8c ? 1 : 4;
        }
        break;
    case 3:
        if (func_0006F190()) {
            state = previous;
        }
        break;
    case 4: {
        Object_00111DE0 *object = (Object_00111DE0 *)data_0022FCE0->func_000128C0(target);
        if (object) {
            object->func_00111DE0(2);
        }
        Flag_001117B0 *flag = (Flag_001117B0 *)data_0022FCE0->func_000128C0(0x1163);
        if (flag) {
            flag->value_148 = 1;
        }
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
    }
    frame += 1.0f;
    if (frame >= (float)animation->frames - 1.0f) {
        frame = 0.0f;
    }
    if (overlay) {
        overlayFrame += 1.0f;
        if (overlayFrame >= (float)overlay->frames - 1.0f) {
            overlayFrame = 0.0f;
        }
    }
}
