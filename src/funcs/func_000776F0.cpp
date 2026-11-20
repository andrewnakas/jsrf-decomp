/* sym: ?func_00011C90@Object_000780F0@@UAEXXZ = 0x000776F0 */
int func_00024650();
void func_00024620(unsigned int color, float step);

struct Game {
    void func_000126D0(int argument);
};

extern Game *data_0022FCE0;

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

// The class whose table is at 0x1CCD18 (constructor 0x78520, destructor 0x780F0): overrides slot 1.
struct Object_000780F0 : Node {
    virtual void func_00011C90();

    char unknown_044[0xe4];
    int unknown_128;
};

// Slot 1: once, when func_00024650 says so, runs func_000126D0 of the game (1), fades to black over 12 frames
// (func_00024620) and sets +0x128.
void Object_000780F0::func_00011C90()
{
    if (!unknown_128 && func_00024650()) {
        data_0022FCE0->func_000126D0(1);
        func_00024620(0, 1.0f / 12.0f);
        unknown_128 = 1;
    }
}
