struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

struct Entry_000607B0 : Node {
    char unknown_044[0x1cc];
    int unknown_210;
    char unknown_214[0x8];
    int unknown_21c;
    char unknown_220[0x2c];
    int unknown_24c;
    char unknown_250[0xc];
    int unknown_25c;
    char unknown_260[0x4];
    int unknown_264;
};

struct Object_000607B0 {
    int func_00060A40(Entry_000607B0 *entry);
};

// The size an entry needs: 0x1558, 12 bytes per +0x25c and, per frame (+0x25c + 1 times +0x21c times +0x210 sixtieths
// plus one, at most +0x24c), 0xb5 bytes plus 16, 24 or 0x70 by the kind at +0x264.
int Object_000607B0::func_00060A40(Entry_000607B0 *entry)
{
    int count = (entry->unknown_25c + 1) * entry->unknown_21c * entry->unknown_210 / 60 + 1;
    if (entry->unknown_24c < count) {
        count = entry->unknown_24c;
    }
    int size = count * 0xb5 + entry->unknown_25c * 12 + 0x1558;
    switch (entry->unknown_264) {
    case 0:
        size += count * 16;
        break;
    case 1:
        size += count * 24;
        break;
    case 2:
        size += count * 0x70;
        break;
    }
    return size;
}
