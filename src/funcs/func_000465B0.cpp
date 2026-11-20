/* sym: ?func_00011C90@Object_00044AE0@@UAEXXZ = 0x000465B0 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
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
    char unknown_34[0x10];
};

int func_000256C0(unsigned int index, int argument);
void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1CA788: overrides slots 1 (465B0), 2 (46630), 3 (45DC0), 4 (AECC0), 5 (45DB0), 6 (45FB0), 11 (AEE80), 12 (461A0), 14 (AEE80), 15 (461A0).
struct Object_00044AE0 : Node {
    virtual ~Object_00044AE0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    char unknown_044[4];
    int unknown_48;
    int unknown_4c;
    char unknown_050[0x28];
    int unknown_78;
    char unknown_07c[0x68];
    void *unknown_e4;
    void *unknown_e8;
    char unknown_0ec[0x854];
    int unknown_940;

    int func_000464C0();
    void func_00044BA0();
    void func_00046340();
    void func_00044C90();
};

// Slot 1: once handler 0xe answers for entry +0x78, takes its two values (+0xe4, +0xe8) and clears +0x940; then,
// unless +0x4c is set, runs func_00046340 and, when +0x48 is set, func_00044C90.
void Object_00044AE0::func_00011C90()
{
    if (unknown_940 && func_000256C0(0xe, unknown_78)) {
        unknown_e4 = func_00025700(0xe, unknown_78, 1, 0);
        unknown_e8 = func_00025700(0xe, unknown_78, 1, 1);
        unknown_940 = 0;
    }
    if (!unknown_4c) {
        func_00046340();
        if (unknown_48) {
            func_00044C90();
        }
    }
}
