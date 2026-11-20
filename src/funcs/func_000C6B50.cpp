/* sym: ?func_00011C90_1@Object_000C6690@@UAEXXZ = 0x000C6B50 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct State_000C6B50 {
    char unknown_00[0x18];
    int active;
};

struct Target_000C6B50 {
    char unknown_00[0x44];
    State_000C6B50 *state;
};

// The class whose table is at 0x1CE030 (constructor func_000C6690): overrides slots 1 (C6A90) and 2 (C6B50).
struct Object_000C6690 : Node {
    virtual void func_00011C90_1();

    int target_id;
    char unknown_48[0x24];
    int value_6c;

    void func_000C6820();
};

// Slot 2: while the object whose id is at 0x44 exists: when its state (0x44) is active (0x18), runs func_000C6820
// unless 0x6c is set; otherwise 0x6c becomes 2.
void Object_000C6690::func_00011C90_1()
{
    Target_000C6B50 *target = (Target_000C6B50 *)data_0022FCE0->func_000128C0(target_id);
    if (target) {
        if (target->state->active) {
            if (!value_6c) {
                func_000C6820();
            }
        } else {
            value_6c = 2;
        }
    }
}
