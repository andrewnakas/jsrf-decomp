/* sym: ?func_00011C90@Object_000FF9B0@@UAEXXZ = 0x000FF9C0 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};


struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

// The parent the constructor marks (bit 30 of its flags at 0x80).
struct Parent_000FF8E0 {
    char unknown_00[0x80];
    unsigned int flags;
};

// A direct child of Node (table 0x1D1C70, destructor func_000FF9B0): three sprites from func_00025700, the second
// chosen by the value at 0x44.
struct Object_000FF9B0 : Node {
    virtual ~Object_000FF9B0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    int unknown_40;
    int value;
    void *sprite_48;
    void *sprite_4c;
    Vector3 position;
    Motion_0005F060 *sprite_5c;
    int unknown_60;
    float time;
    int phase;
    int unknown_6c;
};

// Slot 1: phases 0 and 1 go to 2; in 2 waits for bit 31 of the parent's flags (then 0x6c cleared, phase 4); 4 clears
// the parent's bit 30 (phase 5); 5 unlinks the object (func_00011BE0) and links its child (func_00011C20). The time at
// 0x64 steps by 1 and wraps to 0 at the last frame of the third sprite.
void Object_000FF9B0::func_00011C90()
{
    Parent_000FF8E0 *owner = (Parent_000FF8E0 *)parent;
    switch (phase) {
    case 0:
        phase = 0;
    case 1:
        phase = 2;
        break;
    case 2:
        if (owner->flags & 0x80000000) {
            unknown_6c = 0;
            phase = 4;
        }
        break;
    case 3:
        break;
    case 4:
        owner->flags &= ~0x40000000;
        phase = 5;
        break;
    case 5:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
    time += 1.0f;
    if (time >= sprite_5c->frames - 1.0f) {
        time = 0.0f;
    }
}
