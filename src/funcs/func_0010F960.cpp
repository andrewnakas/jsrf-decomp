/* sym: ?func_00011C90@Object_0010F950@@UAEXXZ = 0x0010F960 */
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


// A direct child of Node (table 0x1D2538, constructor func_0010F870, destructor func_0010F950).
struct Object_0010F950 : Node {
    virtual ~Object_0010F950();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);

    int unknown_040;
    unsigned int value;
    int mode;
    unsigned int frame;
    void *sprites[6];
    int state;
    unsigned int count;
    unsigned int laps;
    Vector3 position;
    float fade;
};

// Slot 1: states 0 and 1 step the frame at 0x4c every tenth call through 6 frames, four times (0x70), then go to 2
// (with a value at 0x44) or 3; 2 steps it every tenth call until it reaches the value (then 3); 3 raises the fade at
// 0x80 by 1/30 up to 1 (then 4); 5 unlinks the object (func_00011BE0) and links its child (func_00011C20).
void Object_0010F950::func_00011C90()
{
    switch (state) {
    case 0:
        laps = 0;
        count = 0;
        state = 1;
    case 1:
        if (++count >= 10) {
            count = 0;
            if (++frame >= 6) {
                frame = 0;
                if (++laps >= 4) {
                    state = value ? 2 : 3;
                }
            }
        }
        break;
    case 2:
        if (++count >= 10) {
            count = 0;
            if (++frame == value) {
                state = 3;
            }
        }
        break;
    case 3:
        fade += 1.0f / 30.0f;
        if (fade >= 1.0f) {
            fade = 1.0f;
            state = 4;
        }
        break;
    case 5:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
}
