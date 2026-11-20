/* sym: ?func_000C60C0@Object_000C7910@@UAEXXZ = 0x000C9EB0 */
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
    int unknown_40;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The owner (a Node child): flags at 0xa4.
struct Object_000C5B50 : Node {
    char unknown_44[0x60];
    unsigned int flags_a4;
};

struct Slot_000C9EB0 {
    char unknown_00[0x10];
    Object_000C60C0 *current;
};

struct Scene_000C9EB0 {
    char unknown_00[0xd8];
    Slot_000C9EB0 *slot;
};

struct Speed_000C7910 {
    char unknown_00[4];
    Scene_000C9EB0 *scene;
};

struct Object_00157F10 {
    void func_000C1E60();
};

extern Object_00157F10 *data_00257CE8;

// The class whose tables are at 0x1CE1C8 (Node) and 0x1CE1C0 (Object_000C60C0 at +0x44).
struct Object_000C7910 : Node, Object_000C60C0 {
    virtual void func_000C60C0();

    char unknown_48[0x68];
    Object_000C5B50 *owner;
    char unknown_b4[4];
    Object_000C60C0 *next;
    char unknown_bc[0x2f8];
    Speed_000C7910 *speed;
};

// Slot 1 of the second base: hands the scene's current object over to the one at 0xb8 when it is this one,
// unlinks (func_000C60C0), relinks the owner when its flag 0x2000 is set (func_00011BE0, then func_00011C20 on
// its child) and runs func_000C1E60 on data_00257CE8.
inline void relink(Node *node)
{
    if (node) {
        node->func_00011BE0(node);
        node->func_00011C20(node->child);
    }
}

void Object_000C7910::func_000C60C0()
{
    Slot_000C9EB0 *slot = speed->scene->slot;
    if (slot->current == this)
        slot->current = next;
    Object_000C60C0::func_000C60C0();
    if (owner->flags_a4 & 0x2000)
        relink(owner);
    data_00257CE8->func_000C1E60();
}
