/* sym: ?func_00011C90@Object_00080070@@UAEXXZ = 0x00080080 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Entry_0003E720 {
    char unknown_00[0xac];
    int unknown_ac;
    int unknown_b0;
};

struct Object_0003E750 {
    Entry_0003E720 *func_0003E720(int key);
};

extern Object_0003E750 data_002314B0;

// The class whose table is at 0x1CD048 (0x54 bytes): a countdown that, when it runs out, writes its pair of values
// into the entry registered under its key and kills itself with everything below it.
struct Object_00080070 : Node {
    virtual ~Object_00080070();
    virtual void func_00011C90();

    int timer;
    int key;
    int value[2];
};

void Object_00080070::func_00011C90()
{
    if (--timer == 0) {
        Entry_0003E720 *entry = data_002314B0.func_0003E720(key);
        if (entry) {
            entry->unknown_ac = value[0];
            entry->unknown_b0 = value[1];
        }
        func_00011BE0(this);
        func_00011C20(child);
    }
}
