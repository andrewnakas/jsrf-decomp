/* sym: ?func_00011C90@Object_000432E0@@UAEXXZ = 0x00043370 */
struct Item_000162A0 {
    char unknown_00[0xc];
    Item_000162A0 *head;
    Item_000162A0 **tail;
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
};

extern Object_00016200 data_0022FCE8;

// An entry of the table at +0x44 (0x54 bytes).
struct Entry_00043370 {
    char unknown_00[0x18];
    int unknown_18;
    int unknown_1c;
    char unknown_20[0x10];
    Item_000162A0 item;
    char unknown_44[0x10];
};

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

// The class whose table is at 0x1CA678 (constructor 0x43C00, destructor 0x432E0): overrides slot 1.
struct Object_000432E0 : Node {
    virtual void func_00011C90();

    Entry_00043370 *entries;
    unsigned int count;
};

// Slot 1: hands the item at +0x30 of each entry whose +0x18 and +0x1c are set to func_000162A0 of 0x22FCE8.
void Object_000432E0::func_00011C90()
{
    for (unsigned int i = 0; i < count; i++) {
        if (entries[i].unknown_18 && entries[i].unknown_1c) {
            data_0022FCE8.func_000162A0(&entries[i].item);
        }
    }
}
