/* sym: ?func_00011C90_4@Object_00113C40@@UAEXXZ = 0x001145F0 */
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


// Menu object 0x1167: its mode at 0x128.
struct Object_00077B70 {
    char unknown_000[0x128];
    int mode;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The pad's stick axes.
extern float data_00251F00;
extern float data_00251F04;

float func_0014C7F0(float value);

// The ticker func_00114080 steps (the same object).
struct Object_00114080 {
    void func_00114080();
};

// The class whose table is at 0x1D2B28.
struct Object_00113C40 : Node {
    virtual ~Object_00113C40();
    virtual void func_00011C90_4();

    char unknown_044[0x58];
    float phase;
    float speed;
    char unknown_0a4[0xc8];
    float value_16c;
    float value_170;
};

// Slot 7: without object 0x1167 runs func_00011BE0 and func_00011C20 on the node. Swings the phase at 0x9c between
// 0 and 1.5 at the speed at 0xa0 / 30; in mode 3 of that object moves 0x16c by stick axis 0x251F04 (clamped to
// [-1, 1]) and 0x170 by axis 0x251F00 (wrapping past either end), each axis only beyond 0.5; then func_00114080.
void Object_00113C40::func_00011C90_4()
{
    Object_00077B70 *menu = (Object_00077B70 *)data_0022FCE0->func_000128C0(0x1167);
    if (!menu) {
        if (this) {
            func_00011BE0(this);
            func_00011C20(child);
        }
        return;
    }
    phase += speed * 0.033333335f;
    if (speed > 0.0f) {
        if (phase >= 1.5f) {
            phase = 1.5f;
            speed = -1.0f;
        }
    } else if (phase <= 0.0f) {
        phase = 0.0f;
        speed = 1.0f;
    }
    if (menu->mode == 3) {
        float axis = data_00251F04;
        if (func_0014C7F0(axis) >= 0.5f) {
            value_16c += axis * 0.01f;
            if (value_16c > 1.0f) {
                value_16c = 1.0f;
            }
            if (value_16c < -1.0f) {
                value_16c = -1.0f;
            }
        }
        axis = data_00251F00;
        if (func_0014C7F0(axis) >= 0.5f) {
            value_170 += axis * 0.01f;
            if (value_170 > 1.0f) {
                value_170 = -1.0f;
            }
            if (value_170 < -1.0f) {
                value_170 = 1.0f;
            }
        }
    }
    ((Object_00114080 *)this)->func_00114080();
}
