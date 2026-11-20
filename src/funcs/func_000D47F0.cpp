struct Object_0006DB80 {
    void func_0006DEB0(int key, int value);
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

// The base whose table holds this function at slot 17 in six classes' tables (0x1CE1C8 and others).
struct Object_000C7910 : Node {
    virtual void func_000C7910();
    virtual void func_000D47F0();
    virtual void func_000C7A70();
    virtual void func_000C7AB0();
    virtual void func_000C7B30();
    virtual void func_000C87D0();
    virtual void func_000C7B90();
    virtual void func_000C7BB0();
    virtual void func_000C7C70();
    virtual void func_000C8870();
    virtual void func_000C88E0();
    virtual void func_000C7CD0();
    virtual void func_000C7CF0();
    virtual void func_000C7D40();
    virtual void func_000C8980();
    virtual void func_000C89F0();
    virtual void func_000C7DB0();
    virtual void func_000C7DD0();
    virtual void func_000C7E20();
    virtual void func_000C8A90();
    virtual void func_000C7DB0_1();
    virtual void func_000C8B30();
    virtual void func_000C7CD0_1();
    virtual void func_000C7E90();
    virtual void func_000C8140();
    virtual void func_000C81C0();
    virtual void func_000C8240();
    virtual void func_000C8BD0();
    virtual void func_000C8C10();
    virtual void func_000C8300();
    virtual void func_000C8F30();

    char unknown_44[0x4c];
    unsigned int flags;
    char unknown_94[4];
    int sound;
    char unknown_9c[0x20];
    int state;
    char unknown_c0[0xfc];
    int value_1bc;
};

extern Object_0006DB80 data_00251F78;

// Slot 17: unless flag 0x100 is set, turns on the sound at +0x98 (when there is one) through func_0006DEB0; then
// with flag 0x10 sets state 3 (+0xbc) and +0x1bc to 1, without flag 1 sets state 2 and +0x1bc to 7, and otherwise
// runs slot 46.
void Object_000C7910::func_000D47F0()
{
    if (!(flags & 0x100) && sound != -1) {
        data_00251F78.func_0006DEB0(sound, 1);
    }
    if (flags & 0x10) {
        state = 3;
        value_1bc = 1;
    } else if (!(flags & 1)) {
        state = 2;
        value_1bc = 7;
    } else {
        func_000C8F30();
    }
}
