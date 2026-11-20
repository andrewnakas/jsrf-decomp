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

    Node *func_00011BD0();
};

// The player's parent (table 0x1CD570): the mode at 0x8b4.
struct Object_000A6980 : Node {
    char unknown_040[0x874];
    int mode;
};

// The player (object 0x2c).
struct Object_000A1C50 : Node {
    char unknown_040[0xdc];
    int value_11c;
    char unknown_120[0x8ec];
    int value_a0c;
    char unknown_a10[0x230];
    float value_c40;
    char unknown_c44[0x54];
    int ownerId;
    char unknown_c9c[0x188];
    int value_e24;
    char unknown_e28[0x28];
    int value_e50;
    char unknown_e54[4];
    int value_e58;
    char unknown_e5c[4];
    int value_e60;
    char unknown_e64[0x150];
    int value_fb4;
    char unknown_fb8[0x1b0];
    int value_1168;
    int value_116c;

    void func_0007FD20();
    void func_000A1D30();
    void func_000A2020();
    void func_0009C4D0();
    void func_0009C600();
};

// Move 0x16: as func_0009C4D0, first letting the object kept by id at 0xc98 go (func_000A2020) when there is one;
// state 2 at 0xe58, 0x15 at 0x11c, and its parent in mode 12.
void Object_000A1C50::func_0009C600()
{
    value_e50 = 0x16;
    if (ownerId > 0) {
        func_000A2020();
    }
    value_a0c = 1;
    value_e24 = 0;
    value_e60 = 0;
    value_fb4 = -1;
    value_c40 = 1.0f;
    value_116c = 0;
    value_1168 = 0;
    func_000A1D30();
    value_e58 = 2;
    value_11c = 0x15;
    func_0007FD20();
    ((Object_000A6980 *)func_00011BD0())->mode = 12;
}
