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

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1E60();
};

extern Object_00157F10 *data_00257CE8;

// The child of Node whose table is at 0x1CF220 (constructor func_000F5E70, destructor func_000F60C0); slots 16 to
// 52 of its table. The class of the table at 0x1CEAC0 derives from it.
struct Object_000F55E0 : Node {
    virtual void func_000F51A0();
    virtual void func_000F5310();
    virtual void func_000F5380();
    virtual void func_000F53E0();
    virtual void func_000F63E0();
    virtual void func_000F6480();
    virtual void func_000F6500();
    virtual void func_000F54C0();
    virtual void func_000F5510();
    virtual void func_000F5550();
    virtual void func_000F55A0();
    virtual void func_000F6580();
    virtual void func_000F55E0();
    virtual void func_000F6620();
    virtual void func_000F5600();
    virtual void func_000F5620();
    virtual void func_000F66C0();
    virtual void func_000F6700();
    virtual void func_000F5640();
    virtual void func_000F6770();
    virtual void func_000F6B70();
    virtual void func_000F6BF0();
    virtual void func_000F6C40();
    virtual void func_000F6C90();
    virtual void func_000F6D60();
    virtual void func_000F6DD0();
    virtual void func_000F6E30();
    virtual void func_000F6E90();
    virtual void func_000F6F00();
    virtual void func_000F6F70();
    virtual void func_000F6FE0();
    virtual void func_000F7050();
    virtual void func_000F70E0();
    virtual void func_000F7120();
    virtual void func_000F7180();
    virtual void func_000F71D0();
    virtual void func_000F7230();

    char unknown_040[0x50];
    unsigned int bits;
    char unknown_094[0x44];
    int timer;
    char unknown_0dc[0x30];
    unsigned int blinks;
    float shown;
    float fade;
};

// Slot 34: fades the value at 0x114 down by 1/180 to 0; every fourth call (count at 0xd8) toggles the value at 0x110
// between 0 and that fade; after 45 toggles (0x10c) unlinks the object (func_00011BE0), links its child
// (func_00011C20), sets bit 0x20 at 0x90 and runs func_000C1E60 of data_00257CE8.
void Object_000F55E0::func_000F5640()
{
    if (fade > 0.0f) {
        fade -= 1.0f / 180.0f;
        if (fade < 0.0f) {
            fade = 0.0f;
        }
    }
    if (++timer >= 4) {
        timer = 0;
        if (blinks & 1) {
            shown = fade;
        } else {
            shown = 0.0f;
        }
        if (++blinks >= 45) {
            func_00011BE0(this);
            func_00011C20(child);
            bits |= 0x20;
            data_00257CE8->func_000C1E60();
        }
    }
}
