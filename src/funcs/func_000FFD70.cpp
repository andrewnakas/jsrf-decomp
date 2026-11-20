/* sym: ?func_00011C90@Object_000FFB90@@UAEXXZ = 0x000FFD70 */
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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    int func_001084E0(int index);
};

void func_001087D0(int handle, unsigned int count, int *values, int value);

// The resource the interface at data_00251D74 creates for this node (its slot 9); slot 2 releases it.
struct Interface_000FFB90 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

// A count shown with its digits: the value and the one shown.
struct Count_000FFB90 {
    int value;
    int shown;
};

// A direct child of Node (table 0x1D1CB0, destructor func_000FFD10): entries 0xd, 0xe and 0xf of its 0x115e-range
// owner (id at 0x120) at 0x88 with their digits at 0x48 (four, four and eight), drawn with a resource at 0x44.
struct Object_000FFB90 : Node {
    virtual void func_00011C90();

    int unknown_040;
    Interface_000FFB90 *resource;
    int first[4];
    int second[4];
    int third[8];
    Count_000FFB90 counts[3];
    char unknown_0a0[0x60];
    int texture;
    char unknown_104[4];
    int value_108;
    unsigned int state;
    unsigned int timer;
    float scale;
    float first_118;
    float second_11c;
    int ownerId;
};

// Slot 1: follows the owner's entries 0xd, 0xe and 0xf; when one changes it shows them again (timer 0, scale 1,
// fade 0) and a node past state 3 goes back to 4. States: 0 restarts into 2; 2 fades the first part in by 0.1 into
// 1, 1 the second into 3, 4 the first again into 3; 3 waits 120 calls into 5; 5 shrinks the scale by 1/30 into 6;
// 6 unlinks the node.
void Object_000FFB90::func_00011C90()
{
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    if (owner == 0) {
        return;
    }
    counts[0].value = owner->func_001084E0(0xd);
    counts[1].value = owner->func_001084E0(0xe);
    counts[2].value = owner->func_001084E0(0xf);
    if (counts[0].value != counts[0].shown || counts[1].value != counts[1].shown ||
        counts[2].value != counts[2].shown) {
        counts[0].shown = counts[0].value;
        counts[1].shown = counts[1].value;
        counts[2].shown = counts[2].value;
        func_001087D0(counts[0].value, 4, first, -1);
        func_001087D0(counts[1].value, 4, second, -1);
        func_001087D0(counts[2].value, 8, third, -1);
        timer = 0;
        scale = 1.0f;
        first_118 = 0.0f;
        if (state >= 3) {
            state = 4;
        }
    }
    switch (state) {
    case 0:
        timer = 0;
        scale = 1.0f;
        first_118 = 0.0f;
        second_11c = 0.0f;
        state = 2;
    case 2:
        first_118 += 0.1f;
        if (first_118 >= 1.0f) {
            first_118 = 1.0f;
            state = 1;
        }
        break;
    case 1:
        second_11c += 0.1f;
        if (second_11c >= 1.0f) {
            second_11c = 1.0f;
            state = 3;
        }
        break;
    case 3:
        if (++timer > 120) {
            state = 5;
        }
        break;
    case 4:
        first_118 += 0.1f;
        if (first_118 >= 1.0f) {
            first_118 = 1.0f;
            state = 3;
        }
        break;
    case 5:
        scale -= 1.0f / 30.0f;
        if (scale < 0.0f) {
            scale = 0.0f;
            state = 6;
        }
        break;
    case 6:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
}
