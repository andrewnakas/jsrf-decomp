struct Vector3 {
    float x;
    float y;
    float z;
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

    char unknown_40[0x20];
    Vector3 velocity;
    char unknown_6c[0x24];
    unsigned int flags;
    char unknown_94[0x28];
    int state;
    char unknown_c0[0x10];
    Vector3 position;
    char unknown_dc[0x10];
    int timer;
    char unknown_f0[0x3c];
    float scaleX;
    char unknown_130[4];
    float scaleZ;
    char unknown_138[0x30];
    int stillCount;
    char unknown_16c[0x50];
    int value_1bc;
    char unknown_1c0[4];
    int phase;

    float func_000CA2F0();
};

// Slot 25: moves the position at 0xd0 by the speed at 0x60 (scaled by 0x12c and 0x134 on x and z) and 0x64 on y;
// in phase 2, flag 0x8000, state 12, the timer and the speed at 0x60 cleared.
void Object_000C7910::func_000C8870()
{
    position.x += scaleX * velocity.x;
    position.y += velocity.y;
    position.z += scaleZ * velocity.x;
    if (phase == 2) {
        flags |= 0x8000;
        state = 12;
        timer = 0;
        velocity.x = 0.0f;
    }
}
