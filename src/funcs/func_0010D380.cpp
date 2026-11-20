/* sym: ?func_00011C90@Object_0010CF70@@UAEXXZ = 0x0010D380 */
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

unsigned int func_0014C6A0(float value);

extern float data_002209D0;

// The interfaces the node holds at 0x44 and 0x168; slot 2 releases one.
struct Interface_0010CF70 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

// The child of Node whose table is at 0x1D2328 (constructor func_0010CF70).
struct Object_0010CF70 : Node {
    virtual ~Object_0010CF70();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_040[4];
    Interface_0010CF70 *first;
    char unknown_048[0x60];
    float baseX;
    int color;
    char unknown_0b0[0x10];
    float x;
    int shownColor;
    unsigned int tint;
    char unknown_0cc[0x10];
    int value_dc;
    char unknown_0e0[0x10];
    float drawX;
    int value_f4;
    unsigned int drawTint;
    char unknown_0fc[0x6c];
    Interface_0010CF70 *second;
    char unknown_16c[0x64];
    float level;
    float limit;
    int owner;
};

// Slot 1: the level at 0x1d0 is entry 3 of the owner's (id at 0x1d8) table (func_001084E0, a float in an int), at
// most the limit at 0x1d4; by the ratio, the x at 0xc0 (and 0xf0) moves from 0xa8 by data_002209D0, 0xac and 0xdc are
// copied on, and the tint at 0xc8 (and 0xf8) runs from (0xff, 0x64, 0xbe) by -100, 255 and -190.
void Object_0010CF70::func_00011C90()
{
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(owner);
    float value;
    *(int *)&value = object->func_001084E0(3);
    level = value;
    if (value > limit) {
        level = limit;
    }
    float ratio = level / limit;
    x = data_002209D0 * ratio + baseX;
    shownColor = color;
    drawX = x;
    value_f4 = value_dc;
    unsigned int tint = ((func_0014C6A0(ratio * -100.0f) + 0x64) << 8) | ((func_0014C6A0(ratio * 255.0f) | 0xffffff00) << 16) |
                        (func_0014C6A0(ratio * -190.0f) + 0xbe);
    this->tint = tint;
    drawTint = tint;
}
