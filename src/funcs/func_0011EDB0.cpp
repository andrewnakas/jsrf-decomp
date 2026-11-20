/* sym: ?func_00011C90@Object_0011EDA0@@UAEXXZ = 0x0011EDB0 */
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

struct Object_0011EDA0 : Node {
    virtual ~Object_0011EDA0();
    virtual void func_00011C90();

    char unknown_034[0x9c];
    unsigned int state;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Slot 1 of the table at 0x1D8F20: looks up object 0x128a (and drops the result), then raises a state below 2 to 3.
void Object_0011EDA0::func_00011C90()
{
    data_0022FCE0->func_000128C0(0x128a);
    if (state <= 1) {
        state = 3;
    }
}
