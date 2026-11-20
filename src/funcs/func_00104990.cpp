/* sym: ?func_00011C90@Object_001047B0@@UAEXXZ = 0x00104990 */
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


struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    int func_001084E0(int index);
};

void func_000F7BC0(int index);
void func_001087D0(int handle, unsigned int count, int *values, int value);

// A direct child of Node (constructor func_001047B0, table 0x1D1F18, destructor func_00104930).
struct Object_001047B0 : Node {
    virtual void func_00011C90();

    char unknown_040[8];
    int digits[3];
    char unknown_054[0xc8];
    int count;
    int last;
    char unknown_124[4];
    int state;
    unsigned int timer;
    int alpha;
    int owner;
};

// Slot 1: the count at 0x11c is entry 0xb of the owner's (id at 0x134) table plus 1 (func_001084E0); a new count
// restarts it: timer 0, alpha 0xff, func_000F7BC0(0xf), the count in three digits at 0x48 (func_001087D0), then it
// waits 120 calls, fades the alpha by 10 to 0 and unlinks itself (func_00011BE0, func_00011C20).
void Object_001047B0::func_00011C90()
{
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(owner);
    if (object) {
        int value = object->func_001084E0(0xb) + 1;
        count = value;
        if (value != last) {
            state = 0;
        }
        switch (state) {
        case 0:
            timer = 0;
            alpha = 0xff;
            last = value;
            state = 1;
            func_000F7BC0(0xf);
        case 1:
            func_001087D0(count, 3, digits, 0);
            state = 3;
            break;
        case 3:
            if (++timer > 120) {
                state = 5;
            }
            break;
        case 5:
            alpha -= 10;
            if (alpha < 0) {
                alpha = 0;
                state = 6;
            }
            break;
        case 6:
            func_00011BE0(this);
            func_00011C20(child);
            break;
        }
    }
}
