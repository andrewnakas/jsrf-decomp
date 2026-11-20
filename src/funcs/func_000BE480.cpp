/* sym: ?func_00011C90_1@Object_000BE1B0@@UAEXXZ = 0x000BE480 */
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


// One of the entries at 0x198 (0x24 bytes): what it points at holds 0 while it is free.
struct Entry_000BE1B0 {
    int *state;
    char unknown_04[0x20];
};

// The child of Node whose table is at 0x1CDB20 (destructor func_000BE1B0; func_000BEA80 builds it).
struct Object_000BE1B0 : Node {
    virtual void func_00011C90_1();

    char unknown_040[0x158];
    Entry_000BE1B0 entries[9];
    char unknown_2dc[0x18];
    int count;
    int busy;
    unsigned int mode;
    char unknown_300[0x10];
    int active;
};

// Slot 2: while active (0x310) in modes 0 to 2, the flag at 0x2f8 says whether any of the entries at 0x198 (count at
// 0x2f4) points at a 0.
void Object_000BE1B0::func_00011C90_1()
{
    if (active && mode <= 2) {
        busy = 0;
        for (int i = 0; i < count; i++) {
            if (entries[i].state && *entries[i].state == 0) {
                busy = 1;
            }
        }
    }
}
