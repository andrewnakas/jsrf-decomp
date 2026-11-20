/* sym: ?func_00011C90@Object_001197F0@@UAEXXZ = 0x00119EC0 */
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
    int mode;
    char unknown_48[0xc];
    int active;
    char unknown_58[0xc];
    unsigned int flags_64;
    char unknown_68[0x2c];

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// The class whose table is at 0x1D7B60 (named after its destructor).
struct Object_001197F0 : Node {
    virtual ~Object_001197F0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int func_00119800();
    void func_00119C20();
    void func_00119CE0();
    void func_00119DA0();
    void func_00119DE0();
    void func_00119E20();
    void func_00119E60();
};

struct Object_00137910 {
    int func_00137920();
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Slot 1: unless func_00137920 of object 0x1deb gives 2, runs func_00011BE0 and func_00011C20 on the node; then,
// while active, mode 0 or 4 goes to mode 1, and mode 1 runs func_00119800 and the step its flags at +0x64 ask for.
void Object_001197F0::func_00011C90()
{
    if (((Object_00137910 *)data_0022FCE0->func_000128C0(0x1deb))->func_00137920() != 2) {
        if (this) {
            func_00011BE0(this);
            func_00011C20(child);
        }
    }
    if (active) {
        switch (mode) {
        case 0:
        case 4:
            mode = 1;
            break;
        case 1:
            func_00119800();
            if (flags_64 & 5) {
                func_00119C20();
            } else if (flags_64 & 0xa) {
                func_00119CE0();
            } else if (flags_64 & 0x10) {
                func_00119E20();
            } else if (flags_64 & 0x20) {
                func_00119E60();
            } else if (flags_64 & 0x40) {
                func_00119DE0();
            } else if (flags_64 & 0x80) {
                func_00119DA0();
            }
            break;
        }
    }
}
