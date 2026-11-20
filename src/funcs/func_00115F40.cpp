/* sym: ?func_00011C80_2@Object_00115E20@@UAEXH@Z = 0x00115F40 */
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
};

struct Object_00115E20 : Node {
    virtual ~Object_00115E20();
    virtual void func_00011C80_2(int message);

    char unknown_034[0x10];
    int value_44;
    char unknown_48[0xc];
    float first;
    float second;
};

void func_0003D5D0(float first, float second, float scale, unsigned int value, float x, float y, int last);

// Override of Node's slot 9 in the class whose table is at 0x1D3770 (the linker folded it with slot 3 of the
// table at 0x1D07F8): for messages 0, 3, 5 and 8 calls func_0003D5D0 with the floats at +0x54 and +0x58, 1.1,
// -1, 1, 1 and the word at +0x44.
void Object_00115E20::func_00011C80_2(int message)
{
    switch (message) {
    case 0:
    case 3:
    case 5:
    case 8:
        func_0003D5D0(first, second, 1.1f, -1, 1.0f, 1.0f, value_44);
        break;
    }
}
