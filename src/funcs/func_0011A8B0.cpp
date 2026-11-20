/* sym: ??0Object_0011A210@@QAE@PAUNode@@HI@Z = 0x0011A8B0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_0011A210@@UAE@XZ = 0x0011A210 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Object_0011EDA0@@QAE@PAUNode@@HIHHH@Z = 0x0011F1C0 */
/* sym: ?func_00011C90@Object_0011A210@@UAEXXZ = 0x0011A2C0 */
/* sym: ?func_00011C80@Object_0011A210@@UAEXH@Z = 0x0011A490 */
/* sym: ?func_00011C90_4@Object_0011A210@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_0011A210@@UAEXH@Z = 0x000B3DE0 */
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

struct Sprite_0011A8B0 {
    char unknown_00[0x24];
    unsigned int flags;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct List_000149B0;

struct Object_000149B0 {
    List_000149B0 *func_000149D0();
};

struct Object_00039BE0 : Object_000149B0 {
    void func_00039CB0(unsigned int index);
    int func_00039D10(unsigned int index);
    void func_00039E80(unsigned int index);
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

// The node 0x11F1C0 builds; 0xD8 bytes.
struct Object_0011EDA0 : Node {
    Object_0011EDA0(Node *owner, int id, unsigned int flags, int number, int second, int kind);

    char unknown_44[0x94];
};

extern Game *data_0022FCE0;
extern Object_00039BE0 data_001EFFB0;
extern int data_0021C1FC[];
extern unsigned int data_0021C450[];
extern unsigned int data_0021C234[3][5];
extern int data_00251F20;

void *func_00025700(unsigned int index, int first, int second, int third);
void func_0006F6D0(unsigned int index, int value);

// The class whose table is at 0x1D7C20.
struct Object_0011A210 : Node {
    Object_0011A210(Node *owner, int id, unsigned int flags);
    virtual ~Object_0011A210();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);

    int func_0011A6F0();

    int mode;
    int unknown_48;
    int value_4c;
    int value_50;
    Sprite_0011A8B0 *sprite_54;
    Sprite_0011A8B0 *sprite_58;
    Sprite_0011A8B0 *sprite_5c;
    Sprite_0011A8B0 *sprite_60;
    Sprite_0011A8B0 *sprite_64;
    int value_68;
    Vector3 offset;
    int value_78;
    int value_7c;
    int value_80;
    int ids[5];
};

// Reads the mode from settings object 0x128A, creates the sprites and five child nodes (0x11F1C0), and when the
// game is in state 9 unlocks the current course's entries.
Object_0011A210::Object_0011A210(Node *owner, int id, unsigned int flags)
    : Node(owner, id, flags)
{
    Object_00074E50 *settings = (Object_00074E50 *)data_0022FCE0->func_000128C0(0x128a);
    switch (settings->func_00074E50(6)) {
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 2;
        break;
    case 3:
        mode = 3;
        break;
    default:
        mode = 0;
        break;
    }
    sprite_58 = 0;
    sprite_54 = 0;
    offset.x = -32.0f;
    offset.y = 24.0f;
    offset.z = 1220.0f;
    value_78 = 0;
    value_7c = 0;
    value_80 = 0;
    value_4c = settings->func_00074E50(mode + 8);
    value_50 = value_4c;
    switch (mode) {
    case 0:
        sprite_54 = (Sprite_0011A8B0 *)func_00025700(0x12, 0, 2, 0xa);
        sprite_5c = (Sprite_0011A8B0 *)func_00025700(0x12, 0, 2, 0x15);
        break;
    case 1:
        sprite_54 = (Sprite_0011A8B0 *)func_00025700(0x12, 0, 2, 0xa);
        sprite_5c = (Sprite_0011A8B0 *)func_00025700(0x12, 0, 2, 0x19);
        break;
    case 2:
        sprite_54 = (Sprite_0011A8B0 *)func_00025700(0x12, 0, 2, 0xc);
        sprite_5c = (Sprite_0011A8B0 *)func_00025700(0x12, 0, 2, 0x17);
        break;
    case 3:
        sprite_54 = (Sprite_0011A8B0 *)func_00025700(0x12, 0, 2, 0xb);
        sprite_5c = (Sprite_0011A8B0 *)func_00025700(0x12, 0, 2, 0x13);
        break;
    }
    if (sprite_54) {
        sprite_54->flags &= ~1;
        sprite_54->flags &= ~8;
    }
    if (sprite_5c) {
        sprite_5c->flags &= ~1;
        sprite_5c->flags |= 1;
    }
    sprite_58 = (Sprite_0011A8B0 *)func_00025700(0x12, 0, 2, 0xd);
    if (sprite_58) {
        sprite_58->flags &= ~1;
        sprite_58->flags &= ~8;
    }
    sprite_60 = (Sprite_0011A8B0 *)func_00025700(0x12, 0, 2, 0x42);
    if (sprite_60) {
        sprite_60->flags &= ~1;
        sprite_60->flags |= 1;
    }
    sprite_64 = (Sprite_0011A8B0 *)func_00025700(0x12, 0, 3, 0);
    value_68 = 0;
    int i;
    for (i = 0; i < 5; i++) {
        ids[i] = 0;
    }
    for (i = 0; i < 5; i++) {
        ids[i] = data_0022FCE0->func_000128E0(0x128b, 0x12ab);
        new Object_0011EDA0(this, ids[i], 0x100, i + 1, settings->func_00074E50(6),
                            settings->func_00074E70(settings->func_00074E50(6) + 8, value_4c));
    }
    if ((int)data_001EFFB0.func_000149D0() == 9 && func_0011A6F0()) {
        int course = settings->func_00074E70(mode + 8, value_4c);
        if (!data_001EFFB0.func_00039D10(data_0021C450[data_0021C1FC[course]])) {
            data_001EFFB0.func_00039CB0(data_0021C450[data_0021C1FC[course]]);
            func_0006F6D0(data_0021C450[data_0021C1FC[course]], data_00251F20);
            settings->func_00074F00(5);
            switch (data_0021C1FC[course]) {
            case 0xc:
                for (i = 0; i < 5; i++) {
                    data_001EFFB0.func_00039E80(data_0021C234[0][i]);
                }
                break;
            case 0xe:
                for (i = 0; i < 5; i++) {
                    data_001EFFB0.func_00039E80(data_0021C234[1][i]);
                }
                break;
            case 0x13:
                for (i = 0; i < 5; i++) {
                    data_001EFFB0.func_00039E80(data_0021C234[2][i]);
                }
                break;
            }
        }
    }
}
