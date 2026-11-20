/* sym: ?func_00011C90@Object_00101BE0@@UAEXXZ = 0x00101DC0 */
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    int func_001084E0(int index);
};

void func_001087D0(int handle, unsigned int count, int *values, int value);

// A direct child of Node (table 0x1D1D90, constructor func_00101BE0, destructor func_00101D60): a four-digit number
// at 0x58 (its digits at 0x48) following entry 10 of its 0x115e-range owner (id at 0x138).
struct Object_00101BE0 : Node {
    virtual void func_00011C90();

    char unknown_040[8];
    int digits[4];
    int shown;
    int value;
    char unknown_060[0xcc];
    unsigned int state;
    unsigned int frame;
    float alpha;
    int ownerId;
    float scale;
};

// Slot 1: with its owner, a new entry 10 (func_001084E0) restarts the frame count and the alpha (back to state 3 from
// a later one) and splits it into the digits. State 0 starts the scale at 0 (state 2), which grows by 0.1 to 1 (state
// 3); 3 waits 120 frames (state 5); 5 fades the alpha by 1/30 to 0 (state 6); 6 unlinks the node.
void Object_00101BE0::func_00011C90()
{
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    if (!owner) {
        return;
    }
    value = owner->func_001084E0(10);
    if (value != shown) {
        frame = 0;
        alpha = 1.0f;
        if (state > 3) {
            state = 3;
        }
        shown = value;
        func_001087D0(value, 4, digits, 0);
    }
    switch (state) {
    case 0:
        frame = 0;
        alpha = 1.0f;
        scale = 0.0f;
        state = 2;
    case 2:
        scale += 0.1f;
        if (scale >= 1.0f) {
            scale = 1.0f;
            state = 3;
        }
        break;
    case 3:
        if (++frame > 120) {
            state = 5;
        }
        break;
    case 5:
        alpha -= 0.033333335f;
        if (alpha < 0.0f) {
            alpha = 0.0f;
            state = 6;
        }
        break;
    case 6:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
}
