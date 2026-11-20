/* sym: ?func_00011C90@Object_000FBFD0@@UAEXXZ = 0x000FC250 */
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
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

// The class whose constructor func_000FBFD0 runs entry `mode` (at 0x58) of the member-function table at 0x21FDA8
// on itself (table 0x1D1B68).
struct Object_000FBFD0 : Node {
    virtual void func_00011C90();

    int unknown_040;
    unsigned int bits;
    char unknown_048[0xc];
    int kind;
    int mode;
    unsigned int flags_5c;
    char unknown_060[0x14];
    float alpha;
    char unknown_078[0x18];
    float fade;
    int value_94;
    char unknown_098[0x10];
    float scale;
};

extern void (Object_000FBFD0::*data_0021FDB4[])();

// Slot 1: unless 0x94 is set, with flag 0x10000000 at 0x5c and game value 0xc above 1, the scale at 0xa8 for kinds 9
// (1.4) and 0x2c (1.6) and bit 30 at 0x44. Runs the handler of data_0021FDB4 for the mode at 0x58. Then with bit 29
// at 0x44 the fade (0x90) and alpha (0x74) go down by 0.05 to 0; with bit 28 (and 0x94 not 6) up to 1, and bit 28
// clears when the alpha is full.
void Object_000FBFD0::func_00011C90()
{
    if (!value_94 && (flags_5c & 0x10000000) && (unsigned int)data_0022FCE0->func_000127E0(0xc) > 1) {
        switch (kind) {
        case 9:
            scale = 1.4f;
            break;
        case 0x2c:
            scale = 1.6f;
            break;
        }
        bits |= 0x40000000;
    }
    (this->*data_0021FDB4[mode])();
    if (bits & 0x20000000) {
        fade -= 0.05f;
        if (fade < 0.0f) {
            fade = 0.0f;
        }
        alpha -= 0.05f;
        if (alpha < 0.0f) {
            alpha = 0.0f;
        }
    } else if ((bits & 0x10000000) && value_94 != 6) {
        fade += 0.05f;
        if (fade > 1.0f) {
            fade = 1.0f;
        }
        alpha += 0.05f;
        if (alpha > 1.0f) {
            alpha = 1.0f;
            bits &= ~0x10000000;
        }
    }
}
