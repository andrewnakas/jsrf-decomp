/* sym: ?func_00011C90@Object_0011A210@@UAEXXZ = 0x0011A2C0 */
/* sym: ??0Object_0011EDA0@@QAE@PAUNode@@HIHHH@Z = 0x0011F1C0 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

struct Object_00074F00 {
    void func_00074F00(int value);
};

struct Object_00074E50 : Object_00074F00 {
    int func_00074E50(int index);
    int func_00074E70(int list, int index);
};

struct Game {
    void *func_000128C0(int id);
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

int func_00119540(int group, int index, void *position);

struct Object_0011EDA0 : Node {
    Object_0011EDA0(Node *owner, int id, unsigned int flags, int number, int second, int kind);

    char unknown_44[0x94];
};

struct Object_0011A210 : Node {
    virtual void func_00011C90();

    int mode;
    int unknown_48;
    int value_4c;
    int value_50;
    char unknown_54[0x10];
    Motion_0005F060 *motion;
    float time;
    char unknown_6c[0xc];
    unsigned int state;
    int value_7c;
    int value_80;
    int ids[5];
};

// Slot 1: from state 0 or 1 it goes to 3 with the setting mode + 8 of object 0x128a taken as both the shown and the
// current value (0x50, 0x4c); in state 3, when that setting changed: sound 3 of group 8, and the five entries (ids at
// 0x84) are rebuilt: each old node unlinked, a new id in [0x128B, 0x12AB] and a new Object_0011EDA0 numbered from 1
// with setting 6 and entry value_4c of list setting 6 + 8. The value at 0x80 steps by 4 (back to 0 past 255) and the
// time at 0x68 runs over the frames of the motion at 0x64.
void Object_0011A210::func_00011C90()
{
    Object_00074E50 *settings = (Object_00074E50 *)data_0022FCE0->func_000128C0(0x128a);
    switch (state) {
    case 0:
    case 1:
        state = 3;
        value_4c = settings->func_00074E50(mode + 8);
        value_50 = value_4c;
    case 3:
        value_4c = settings->func_00074E50(mode + 8);
        if (value_4c != value_50) {
            func_00119540(8, 3, 0);
            value_50 = value_4c;
            for (int i = 0; i < 5; i++) {
                if (data_0022FCE0->func_000128C0(ids[i])) {
                    Node *node = (Node *)data_0022FCE0->func_000128C0(ids[i]);
                    if (node) {
                        node->func_00011BE0(node);
                        node->func_00011C20(node->child);
                    }
                }
                ids[i] = data_0022FCE0->func_000128E0(0x128b, 0x12ab);
                new Object_0011EDA0(this, ids[i], 0x100, i + 1, settings->func_00074E50(6),
                                    settings->func_00074E70(settings->func_00074E50(6) + 8, value_4c));
            }
        }
        break;
    default:
        return;
    }
    value_80 += 4;
    if (value_80 > 0xff) {
        value_80 = 0;
    }
    if (motion) {
        time += 1.0f;
        if (time >= motion->frames) {
            time = 0.0f;
        }
    }
}
