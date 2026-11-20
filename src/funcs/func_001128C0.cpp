/* sym: ?func_00011C90_4@Object_001128B0@@UAEXXZ = 0x001128C0 */
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

struct Animation_001128C0 {
    short unknown_0;
    short frames;
};

struct Object_00077B70 {
    int func_00077B70(int index);
};

// The class whose table is at 0x1D2A00 (destructor 0x1128B0): this unit's function is its override of Node's
// slot 7.
struct Object_001128B0 : Node {
    virtual ~Object_001128B0();
    virtual void func_00011C90_4();

    char unknown_44[0x30];
    Animation_001128C0 *first;
    float firstFrame;
    char unknown_7c[0xc];
    Animation_001128C0 *second;
    float secondFrame;
    char unknown_90[4];
    Animation_001128C0 *third;
    float thirdFrame;
    char unknown_9c[0x114];
    int value;
    float timer;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Slot 7: counts the timer down from 1 second; without object 0x1167 stops there; notes entry 0 of that object
// (func_00077B70) and clears the timer when it changed; then steps the three animations.
void Object_001128B0::func_00011C90_4()
{
    timer -= 1.0f / 60.0f;
    if (timer <= 0.0f) {
        timer = 1.0f;
    }
    Object_00077B70 *object = (Object_00077B70 *)data_0022FCE0->func_000128C0(0x1167);
    if (!object) {
        return;
    }
    if (value != object->func_00077B70(0)) {
        value = object->func_00077B70(0);
        timer = 0;
    }
    firstFrame += 1.0f;
    if (firstFrame >= first->frames - 1.0f) {
        firstFrame = 0;
    }
    secondFrame += 1.0f;
    if (secondFrame >= second->frames - 1.0f) {
        secondFrame = 0;
    }
    thirdFrame += 1.0f;
    if (thirdFrame >= third->frames - 1.0f) {
        thirdFrame = 0;
    }
}
