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

struct Vector3 {
    float x;
    float y;
    float z;
};

// The owner at 0xb0.
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5B40(int id, void *position);
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);
};

// The child of Node whose table is at 0x1CF220 (constructor func_000F5E70, destructor func_000F60C0); slots 16 to
// 52 of its table. The class of the table at 0x1CEAC0 derives from it.
struct Object_000F55E0 : Node {
    virtual void func_000F51A0();
    virtual void func_000F5310();
    virtual void func_000F5380();
    virtual void func_000F53E0();
    virtual void func_000F63E0();
    virtual void func_000F6480();
    virtual void func_000F6500();
    virtual void func_000F54C0();
    virtual void func_000F5510();
    virtual void func_000F5550();
    virtual void func_000F55A0();
    virtual void func_000F6580();
    virtual void func_000F55E0();
    virtual void func_000F6620();
    virtual void func_000F5600();
    virtual void func_000F5620();
    virtual void func_000F66C0();
    virtual void func_000F6700();
    virtual void func_000F5640();
    virtual void func_000F6770();
    virtual void func_000F6B70();
    virtual void func_000F6BF0();
    virtual void func_000F6C40();
    virtual void func_000F6C90();
    virtual void func_000F6D60();
    virtual void func_000F6DD0();
    virtual void func_000F6E30();
    virtual void func_000F6E90();
    virtual void func_000F6F00();
    virtual void func_000F6F70();
    virtual void func_000F6FE0();
    virtual void func_000F7050();
    virtual void func_000F70E0();
    virtual void func_000F7120();
    virtual void func_000F7180();
    virtual void func_000F71D0();
    virtual void func_000F7230();

    void func_000F5D70(int on);

    char unknown_040[0x8];
    Vector3 position;
    char unknown_054[0x5c];
    Object_000C5B50 *owner;
    char unknown_0b4[0x144];
    int handles[2];
};

// Called by slots 20 and 21: on, moves both handles of the owner at 0xb0 (0x1f8 and 0x1fc) to the position at 0x48
// (func_000C5B40), or gets them with messages 4 and 5 (func_000C5B10) when the owner no longer knows them; off,
// releases the ones it still knows (func_000C5B50).
void Object_000F55E0::func_000F5D70(int on)
{
    if (on) {
        if (owner->func_000C5B70(handles[0])) {
            owner->func_000C5B40(handles[0], &position);
        } else {
            handles[0] = owner->func_000C5B10(4, &position);
        }
        if (owner->func_000C5B70(handles[1])) {
            owner->func_000C5B40(handles[1], &position);
        } else {
            handles[1] = owner->func_000C5B10(5, &position);
        }
    } else {
        if (owner->func_000C5B70(handles[0])) {
            owner->func_000C5B50(&handles[0]);
        }
        if (owner->func_000C5B70(handles[1])) {
            owner->func_000C5B50(&handles[1]);
        }
    }
}
