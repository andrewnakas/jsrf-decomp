/* sym: ??0Object_00074C60@@QAE@PAUNode@@HIPAUObject_0006A720@@@Z = 0x00074BD0 */
/* sym: ??1Object_00074C60@@UAE@XZ = 0x00074C60 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00074C60@@UAEXXZ = 0x00074C70 */
/* sym: ?func_00011C80@Object_00074C60@@UAEXH@Z = 0x00074CB0 */
/* sym: ?func_00011C80_1@Object_00074C60@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_3@Object_00074C60@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_00074C60@@UAEXH@Z = 0x000B3DE0 */
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

/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* const: 0x20810C */
struct Object_0006A720 {
    int func_0006A720();
    void func_0006A770();
    void func_0006A7C0();
    void func_0006B6A0();
    void func_0006B8F0();
    void func_0006BA80();
    float func_0006C360();
};
struct Item_00016200 {
    int unknown_00;
    Item_00016200 *next;
};

struct Game {
    void *func_000128C0(int id);
};

struct Object_0006A960 {
    void func_0006A960(int value);
};

extern Game *data_0022FCE0;
extern Object_0006A960 data_0020C6C0;

// The class whose table is at 0x1CCC98: overrides slots 1 (74C70), 3 (74CB0), 6 (B3DE0), 12 (B3DE0), 15 (B3DE0).
struct Object_00074C60 : Node {
    virtual ~Object_00074C60();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Object_00074C60(Node *owner, int id, unsigned int flags, Object_0006A720 *model);

    Object_0006A720 *model;
    Item_00016200 first;
    Item_00016200 second;
};

Object_00074C60::Object_00074C60(Node *owner, int id, unsigned int flags, Object_0006A720 *model)
    : Node(owner, id, flags)
{
    this->flags |= 0x20810c;
    this->model = model;
    data_0022FCE0->func_000128C0(7);
    data_0020C6C0.func_0006A960(this->model->func_0006A720());
}
