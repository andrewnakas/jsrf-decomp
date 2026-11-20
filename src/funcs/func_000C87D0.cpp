// The owner type of the Object_000CC600 family.
struct Object_000C5B50 {
    int func_000C5B10(int first, int second);
    void func_000C5B40(int id, void *position);
};

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

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240; a second base with the table at
// 0x1CE1C0 sits at 0x44, not declared here). Slots 16 to 76 of its table.
struct Object_000C7910 : Node {
    virtual void func_000C7910();
    virtual void func_000D47F0();
    virtual void func_000C7A70();
    virtual void func_000C7AB0();
    virtual void func_000C7B30();
    virtual void func_000C87D0();
    virtual void func_000C7B90();
    virtual void func_000C7BB0();
    virtual void func_000C7C70();
    virtual void func_000C8870();
    virtual void func_000C88E0();
    virtual void func_000C7CD0();
    virtual void func_000C7CF0();
    virtual void func_000C7D40();
    virtual void func_000C8980();
    virtual void func_000C89F0();
    virtual void func_000C7DB0();
    virtual void func_000C7DD0();
    virtual void func_000C7E20();
    virtual void func_000C8A90();
    virtual void func_000C7DB0_1();
    virtual void func_000C8B30();
    virtual void func_000C7CD0_1();
    virtual void func_000C7E90();
    virtual void func_000C8140();
    virtual void func_000C81C0();
    virtual void func_000C8240();
    virtual void func_000C8BD0();
    virtual void func_000C8C10();
    virtual void func_000C8300();
    virtual void func_000C8F30();
    virtual void func_000CAD70();
    virtual void func_000CAED0();
    virtual void func_000CB130();
    virtual void func_000CB1A0();
    virtual void func_000CB200();
    virtual void func_000CB250();
    virtual void func_000CB2A0();
    virtual void func_000CB360();
    virtual void func_000CB3B0();
    virtual void func_000CB410();
    virtual void func_000CB470();
    virtual void func_000CB4D0();
    virtual void func_000CB530();
    virtual void func_000CB590();
    virtual void func_000CB5F0();
    virtual void func_000CB650();
    virtual void func_000CB6B0();
    virtual void func_000CB720();
    virtual void func_000CB790();
    virtual void func_000CB800();
    virtual void func_000CB870();
    virtual void func_000CB950();
    virtual void func_000CB9C0();
    virtual void func_000CBA30();
    virtual void func_000CBAA0();
    virtual void func_000CBB30();
    virtual void func_000CBB70();
    virtual void func_000CBBD0();
    virtual void func_000CBC20();
    virtual void func_000CBC80();

    char unknown_40[8];
    int value_48;
    char unknown_4c[8];
    float value_54;
    char unknown_58[8];
    float speed;
    char unknown_64[0x28];
    int value_8c;
    unsigned int flags;
    char unknown_94[0x1c];
    Object_000C5B50 *owner;
    char unknown_b4[8];
    int state;
    char unknown_c0[0x28];
    float value_e8;
    int timer;
    char unknown_f0[0xcc];
    int value_1bc;

    int func_000C8500();
    float func_000C9CC0();
    void func_000CA070();
};

// Slot 21: tells the owner at 0xb0 the id at 0x8c and the field at 0x48 (func_000C5B40), runs func_000C9CC0 and
// func_000CA070; unless flag 4 is set and func_000C8500 holds it: while 0xe8 is not below 0 the timer counts,
// else, without flag 0x80, 0x54 and the speed at 0x60 are cleared, flag 0x8000, state 6, 0x1bc = 3, and the owner
// gets 18 (func_000C5B10).
void Object_000C7910::func_000C87D0()
{
    owner->func_000C5B40(value_8c, &value_48);
    func_000C9CC0();
    func_000CA070();
    if ((flags & 4) && func_000C8500()) {
        return;
    }
    if (value_e8 < 0.0f) {
        if (!(flags & 0x80)) {
            state = 6;
            value_54 = 0.0f;
            value_1bc = 3;
            flags |= 0x8000;
            speed = 0.0f;
            owner->func_000C5B10(18, (int)&value_48);
        }
    } else {
        timer++;
    }
}
