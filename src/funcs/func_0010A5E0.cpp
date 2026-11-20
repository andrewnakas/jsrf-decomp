/* sym: ?func_00011C90@Object_0010A390@@UAEXXZ = 0x0010A5E0 */
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

// The child of Node whose table is at 0x1D20A0 (constructor func_0010A390): a seven-digit number at 0xa0 (its digits
// at 0x4c) rolling to the one at 0xa4 (the digits that change at 0x68).
struct Object_0010A390 : Node {
    virtual void func_00011C90();

    char unknown_040[0xc];
    int digits[7];
    int changing[7];
    char unknown_084[0x1c];
    int shown;
    int value;
    char unknown_0a8[0xc4];
    int state;
    unsigned int frame;
    float roll;
    int ownerId;
};

// Slot 1: follows entry 6 of its 0x115e-range owner (func_001084E0). State 0 takes it and its digits; in state 1 a
// new value marks the digits that change (the others -1 at 0x68) and starts state 3, which rolls them over 20 frames
// (0x174 = frame * 0.05 * 19) and then shows the new digits.
void Object_0010A390::func_00011C90()
{
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    switch (state) {
    case 0:
        shown = value = owner->func_001084E0(6);
        func_001087D0(shown, 7, digits, 0);
        for (int j = 0; j < 7; j++) {
            changing[j] = -1;
        }
        state = 1;
    case 1:
        value = owner->func_001084E0(6);
        if (value != shown) {
            func_001087D0(shown, 7, digits, 0);
            func_001087D0(value, 7, changing, 0);
            for (int i = 0; i < 7; i++) {
                if (changing[i] == digits[i]) {
                    changing[i] = -1;
                }
            }
            shown = value;
            state = 3;
            frame = 0;
            roll = 0.0f;
        }
        break;
    case 3:
        frame++;
        float t = frame * 0.05f;
        roll = t * 19.0f;
        if (frame > 19) {
            state = 1;
            for (int j = 0; j < 7; j++) {
                changing[j] = -1;
            }
            func_001087D0(shown, 7, digits, 0);
        }
        break;
    }
}
