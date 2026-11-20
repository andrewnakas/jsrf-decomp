/* sym: ?func_00011C90_3@Object_00044AE0@@UAEXXZ = 0x00045DB0 */
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

// Slot 5: runs slot 2 when +0x78 is 0x64.
void Object_00044AE0::func_00011C90_3()
{
    if (unknown_78 == 0x64) {
        func_00011C90_1();
    }
}
