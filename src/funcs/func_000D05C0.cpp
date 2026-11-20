/* sym: ?func_00011C90@Object_000D01A0@@UAEXXZ = 0x000D05C0 */
struct Vector3 {
    float x;
    float y;
    float z;
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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


// One of the eight pieces at 0x48.
struct Object_000CFB70 {
    void func_000D0410();
};

// The class whose table is at 0x1CE3B8 (0x90 bytes; destructor 0xCFA90, constructor 0xD01A0): eight
// Object_000CFB70 at 0x48 around the position at 0x74; overrides slots 1 and 3 of Node, slots 12 and 15 hold
// folded thunks.
struct Object_000D01A0 : Node {
    Object_000D01A0(Node *owner, int id, unsigned int flags, Vector3 *position);
    virtual ~Object_000D01A0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    int state;
    Object_000CFB70 *items[8];
    unsigned int timer;
    float fade;
    unsigned int value_70;
    Vector3 position;
    char unknown_80[0xc];
    int texture;
};

// Slot 1: in state 0 runs the eight pieces (func_000D0410) and moves to state 1 after 600 frames; in state 1 runs
// them while the fade at 0x6c falls by 1/60, moving to state 2 at 0; in state 2 sets the flag 1 at 0x70 and, with
// 0x70's flag 2, unlinks the node and its children, then moves to state 3.
void Object_000D01A0::func_00011C90()
{
    switch (state) {
    case 0:
        for (int i = 0; i < 8; i++) {
            items[i]->func_000D0410();
        }
        if (++timer >= 600) {
            timer = 600;
            state = 1;
        }
        break;
    case 1:
        for (int j = 0; j < 8; j++) {
            items[j]->func_000D0410();
        }
        if ((fade -= 0.016666668f) <= 0.0f) {
            fade = 0.0f;
            state = 2;
        }
        break;
    case 2:
        value_70 |= 1;
        if (value_70 & 2) {
            func_00011BE0(this);
            func_00011C20(child);
        }
        state++;
        break;
    }
}
