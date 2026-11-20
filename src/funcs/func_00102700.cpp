/* sym: ?func_00011C90@Object_00102480@@UAEXXZ = 0x00102700 */
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

int func_0003BF40(Vector3 *position);

// The objects with ids 0x115e to 0x1162 (table 0x1D2020): flags at 0x1700.
struct Object_00107FE0 {
    char unknown_0000[0x1700];
    unsigned int flags;
};

struct Object_000FC4D0 {
    void func_000FC4D0(unsigned int flag, int set);
};

// A direct child of Node (table 0x1D1DD0, destructor func_00102480).
struct Object_00102480 : Node {
    virtual ~Object_00102480();
    virtual void func_00011C90();

    char unknown_40[0x14];
    int owner;
    int mode;
    char unknown_5c[4];
    Vector3 position;
    char unknown_6c[0x34];
    float fade;
    int state;
    char unknown_a8[4];
    int other;
    int finished;

    void func_001025B0();
};

// Slot 1: in mode 1 places the position at 0x60 (func_0003BF40). States: 0 and 1 (and 6) fade 0xa0 in over 30 frames
// to state 2; 2 waits in mode 1 for flag 0x20000000 of the owner (0x54), then goes to 4 and sets that flag on the
// object at 0xac; 3 and 4 fade out to 7 and 5; 5 waits for the owner's flag to clear, goes to 6 and on the object at
// 0xac clears it and sets 0x10000000; 7 unlinks the node once 0xb0 is set. Then aims it (func_001025B0).
void Object_00102480::func_00011C90()
{
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(owner);
    if (mode == 1) {
        func_0003BF40(&position);
    }
    switch (state) {
    case 0:
        fade = 0.0f;
        state = 1;
    case 1:
    case 6:
        fade += 0.033333335f;
        if (fade >= 1.0f) {
            fade = 1.0f;
            state = 2;
        }
        break;
    case 2:
        if (mode == 1 && object && (object->flags & 0x20000000)) {
            state = 4;
            Object_000FC4D0 *target = (Object_000FC4D0 *)data_0022FCE0->func_000128C0(other);
            if (target) {
                target->func_000FC4D0(0x20000000, 1);
            }
        }
        break;
    case 3:
        fade -= 0.033333335f;
        if (fade <= 0.0f) {
            fade = 0.0f;
            state = 7;
        }
        break;
    case 4:
        fade -= 0.033333335f;
        if (fade <= 0.0f) {
            fade = 0.0f;
            state = 5;
        }
        break;
    case 5:
        if (mode == 1 && object && !(object->flags & 0x20000000)) {
            state = 6;
            Object_000FC4D0 *target = (Object_000FC4D0 *)data_0022FCE0->func_000128C0(other);
            if (target) {
                target->func_000FC4D0(0x20000000, 0);
                target->func_000FC4D0(0x10000000, 1);
            }
        }
        break;
    case 7:
        if (finished) {
            func_00011BE0(this);
            func_00011C20(child);
        }
        break;
    }
    func_001025B0();
}
