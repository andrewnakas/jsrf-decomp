/* sym: ??0Object_00074260@@QAE@PAUNode@@HIHI@Z = 0x000740A0 */
struct Game {
    void *func_000128C0(int id);
    int func_000128E0(int first, int last);
};

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// The screens made by func_00109690 (table 0x1CCC58, 0xe4 bytes).
struct Object_00074260 : Node {
    Object_00074260(Node *owner, int id, unsigned int flags, int ownerId, unsigned int mode);

    char unknown_040[0xa4];

    void func_000743C0();
};

struct Object_000732A0 {
    void func_000732A0();
};

// Object 0x1163.
struct Object_000FEDB0 {
    void func_000FEEF0(int keep);
    void func_000FEF40(int value, int id);
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 : Node {
    char unknown_0040[0x4c];
    int childId_8c;
    int screenId;
    char unknown_0094[0x162c];
    int value_16c0;
    char unknown_16c4[0x2c];
    int screen;
    char unknown_16f4[0xc];
    unsigned int state;

    void func_001091D0();
    void func_00109690(int screen);
};

extern Game *data_0022FCE0;

// Opens screen 2 to 11 (any other is mode 0x80000001) unless it is already open: closes the current screen
// (func_000743C0) and the object at 0x8c (func_000732A0), resets (func_001091D0), clears bits 28 and 30 at 0x1700,
// tells object 0x1163 (func_000FEEF0, and func_000FEF40 for a mode with bit 26) and makes the new screen with a
// free id from 0x11f7 to 0x1207.
void Object_00107FE0::func_00109690(int screen)
{
    if (screenId != -1) {
        if (this->screen == screen) {
            return;
        }
        Object_00074260 *current = (Object_00074260 *)data_0022FCE0->func_000128C0(screenId);
        if (current) {
            current->func_000743C0();
        }
    }
    if (childId_8c != -1) {
        Object_000732A0 *child = (Object_000732A0 *)data_0022FCE0->func_000128C0(childId_8c);
        if (child) {
            child->func_000732A0();
        }
    }
    unsigned int mode;
    switch (screen) {
    case 2:
        mode = 0x40000001;
        break;
    case 3:
        mode = 0x20000001;
        break;
    case 4:
        mode = 0x18000001;
        break;
    case 5:
        mode = 0x80000002;
        break;
    case 6:
        mode = 0x18000004;
        break;
    case 7:
        mode = 0x20000003;
        break;
    case 8:
        mode = 0x84000000;
        break;
    case 9:
        mode = 0x26000000;
        break;
    case 10:
        mode = 0x6000000;
        break;
    case 11:
        mode = 0x24000000;
        break;
    default:
        mode = 0x80000001;
        break;
    }
    this->screen = screen;
    func_001091D0();
    state &= ~0x50000000;
    Object_000FEDB0 *menu = (Object_000FEDB0 *)data_0022FCE0->func_000128C0(0x1163);
    if (menu) {
        menu->func_000FEEF0(0);
    }
    screenId = data_0022FCE0->func_000128E0(0x11f7, 0x1207);
    if (mode & 0x4000000) {
        menu = (Object_000FEDB0 *)data_0022FCE0->func_000128C0(0x1163);
        menu->func_000FEF40(screenId, value_16c0);
    }
    new Object_00074260(this, screenId, 0x100, id, mode);
}
