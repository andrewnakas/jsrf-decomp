/* sym: ?func_00011C90@Object_000DB3E0@@UAEXXZ = 0x000DB580 */
struct Motion_0005F060;
struct Item_00017940;

struct Item_00016200 {
    Item_00017940 *handle;
    Item_00016200 *next;
};

struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
};

extern Object_00016200 data_0022FCE8;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

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

// The class whose table is at 0x1CE740 (destructor func_000DB520).
struct Object_000DB3E0 : Node {
    virtual ~Object_000DB3E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_044[0x2c];
    Motion_0005F060 *motion;
    float time;
    Item_00016200 link;
};

// Slot 1: hands the link at 0x78 to data_0022FCE8 (func_00016240) and plays the motion at half speed.
void Object_000DB3E0::func_00011C90()
{
    data_0022FCE8.func_00016240(&link);
    func_0005E030(motion, &time, 0.5f, 0);
}
