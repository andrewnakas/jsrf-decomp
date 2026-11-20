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

// The object in data_00257CE8; func_00157F10 is the engine's (it returns 0).
struct Object_00157F10 {
    int func_00157F10(void *point, int value);
};

extern Object_00157F10 *data_00257CE8;

struct Object_0006DB80 {
    void func_0006DEB0(int first, int second);
};

extern Object_0006DB80 data_00251F78;

// The parameters at 0x118.
struct Params_000F55E0 {
    char unknown_00[0x38];
    int value_38;
};

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

    char unknown_040[0x38];
    int value_78;
    char unknown_07c[0x14];
    unsigned int flags_90;
    char unknown_094[0x4];
    int value_98;
    char unknown_09c[0x20];
    int state;
    char unknown_0c0[0x58];
    Params_000F55E0 *params;
    char unknown_11c[0x4c];
    int mode;
};

// Slot 17: with flag 0x100 at 0x90, once func_00157F10 of data_00257CE8 no longer holds the point at 0x78 (value 0x38
// of the parameters at 0x118): clears flags 0x101, calls func_0006DEB0 of data_00251F78 with the value at 0x98 (when
// it is not -1) and 1, state 2 and mode 0 (0x168).
void Object_000F55E0::func_000F5310()
{
    if (flags_90 & 0x100) {
        if (!data_00257CE8->func_00157F10(&value_78, params->value_38)) {
            flags_90 &= ~0x101;
            if (value_98 != -1) {
                data_00251F78.func_0006DEB0(value_98, 1);
            }
            state = 2;
            mode = 0;
        }
    }
}
