/* sym: ?func_00011C90_1@Object_000ECB50@@UAEXXZ = 0x000ECE70 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void func_000FEC30(int value, const Vector3 *position);

// The object a behaviour serves (at 0xb0).
struct Object_000C5B50 {
    char unknown_00[0x9c];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;
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

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The four sizes of the part.
struct Sizes_000ECE70 {
    float values[4];
};

// The 0x6c-byte part at 0x30 of Object_000EA3B0 and at 0xbc of Object_000ECB50.
struct Part_000EB830 {
    char unknown_00[0x4c];
    Sizes_000ECE70 sizes;
    char unknown_5c[0x10];

    int func_000EBBF0(unsigned int *flags);
};

// The class whose tables are at 0x1CEF20 (Node) and 0x1CEF18 (Object_000C60C0 at +0x44).
struct Object_000ECB50 : Node, Object_000C60C0 {
    virtual ~Object_000ECB50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000EC910();

    Vector3 position;
    char unknown_054[0x3c];
    unsigned int flags_90;
    char unknown_094[8];
    int value_9c;
    char unknown_0a0[0x10];
    Object_000C5B50 *owner;
    char unknown_0b4[8];
    Part_000EB830 part;
    int state;
    int value_12c;
};

// Slot 2: unless the flag 0x4000000 is set at 0x90, runs func_000EC910 and the part's func_000EBBF0 on the owner's
// flags, setting 0x2000000 when one of the part's four sizes changed; once all four effects are on, sets 0x4000000
// with state 5, 1 at 0x9c and 0 at 0x12c, else hands the position to func_000FEC30 with the owner's 0x9c.
void Object_000ECB50::func_00011C90_1()
{
    if (!(flags_90 & 0x4000000)) {
        func_000EC910();
        Sizes_000ECE70 before = part.sizes;
        unsigned int count = part.func_000EBBF0(&owner->flags);
        for (unsigned int i = 0; i < 4; i++) {
            if (before.values[i] != part.sizes.values[i]) {
                flags_90 |= 0x2000000;
                break;
            }
        }
        if (count >= 4) {
            flags_90 |= 0x4000000;
            state = 5;
            value_9c = 1;
            value_12c = 0;
            return;
        }
        func_000FEC30(owner->value_9c, &position);
    }
}
