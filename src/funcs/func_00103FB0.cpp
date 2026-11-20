/* sym: ?func_00011C90@Object_00103D60@@UAEXXZ = 0x00103FB0 */
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

// The object with the id at 0x138 (one of 0x115e to 0x1162).
struct Object_00107FE0 {
    void func_001077C0(int index);
};

void func_001087D0(int handle, unsigned int count, int *values, int value);

// The resource the interface at data_00251D74 creates for this node (its slot 9); slot 2 releases it.
struct Interface_00103D60 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

// A direct child of Node (constructor func_00103D60) that holds a resource at 0x44.
struct Object_00103D60 : Node {
    virtual ~Object_00103D60();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_040[0x004];
    Interface_00103D60 *resource;
    int first;
    int second;
    int firstDigits[2];
    int secondDigits[2];
    char unknown_060[0xcc];
    int state;
    unsigned int count;
    float fade;
    int target;
};

// Slot 1: state 0 splits the numbers at 0x48 and 0x4c into two digits each (func_001087D0, padded with -1 and 0),
// count 0 and fade 1 (state 2); 2 waits 120 calls (state 3); 3 lowers the fade at 0x134 by 0.05 to 0 (state 4); 4 runs
// func_001077C0(0xc) of the object with the id at 0x138, unlinks itself (func_00011BE0) and links its child.
void Object_00103D60::func_00011C90()
{
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(target);
    switch (state) {
    case 0:
        count = 0;
        fade = 1.0f;
        func_001087D0(first, 2, firstDigits, -1);
        func_001087D0(second, 2, secondDigits, 0);
        state = 2;
        break;
    case 2:
        if (++count >= 120) {
            state = 3;
        }
        break;
    case 3:
        fade -= 0.05f;
        if (fade <= 0.0f) {
            fade = 0.0f;
            state = 4;
        }
        break;
    case 4:
        object->func_001077C0(0xc);
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
}
