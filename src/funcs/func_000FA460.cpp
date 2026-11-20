/* sym: ?func_00011C90@Object_000F98B0@@UAEXXZ = 0x000FA460 */
struct Game {
    void *func_000128C0(int id);
};

struct Block_000FA460 {
    char unknown_00[0x1c];
    int busy;
};

// Object 9 (its block at +0x1040).
struct Stage_000FA460 {
    char unknown_0000[0x1040];
    Block_000FA460 *block;
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
};

// The child of Node whose table is at 0x1D08A0 (constructor func_000F98B0, destructor func_000F9A80); the
// constructor clears *first and sets *second to 1.
struct Object_000F98B0 : Node {
    virtual void func_00011C90();

    char unknown_040[0x1c];
    float time;
    int *first;
    int *second;
    char unknown_068[0x14];
    int phase;

    int func_000FA390();
    void func_000FA070();
    void func_000F9C40();
};

extern Game *data_0022FCE0;

int func_0006F190();

// Slot 1: phase 0 moves to 1; in phase 1, unless func_000FA390 says so, func_000FA070 or (with object 9's word at
// +0x1c of its block set) func_000F9C40; phase 2 returns to 1 once func_0006F190 holds. The time at 0x5c steps by
// 1/60 and wraps at 0.5, and restarts when *second changed meanwhile.
void Object_000F98B0::func_00011C90()
{
    Stage_000FA460 *stage = (Stage_000FA460 *)data_0022FCE0->func_000128C0(9);
    int before = *second;
    switch (phase) {
    case 0:
        phase = 1;
        break;
    case 1:
        if (!func_000FA390() && stage) {
            if (stage->block->busy == 0) {
                func_000FA070();
            } else {
                func_000F9C40();
            }
        }
        break;
    case 2:
        if (func_0006F190()) {
            phase = 1;
        }
        break;
    }
    time += 0.016666668f;
    if (time >= 0.5f) {
        time = 0.0f;
    }
    if (before != *second) {
        time = 0.0f;
    }
}
