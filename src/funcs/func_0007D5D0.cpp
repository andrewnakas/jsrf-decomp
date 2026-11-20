/* sym: ??1Object_0007C250@@UAE@XZ = 0x0007D680 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0007C250@@UAEXXZ = 0x0007D6E0 */
/* sym: ?func_00011C80@Object_0007C250@@UAEXH@Z = 0x0007DA30 */
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

/* sym: ??0Object_0007C250@@QAE@PAUNode@@HI@Z = 0x0007D5D0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */

struct Object_00047110 {
    int func_00047110(void *buffer);
};

struct Model_0007D5D0 {
    int unknown_00;
    char unknown_04[0x14];
    int unknown_18;
};

struct Object_000667D0 {
    void func_000667D0();
};

extern Object_00047110 data_001F97A8;
extern Object_000667D0 *data_00251F24;

void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1CCEF8: overrides slots 1 (7D6E0), 3 (7DA30).
struct Object_0007C250 : Node {
    virtual ~Object_0007C250();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    Object_0007C250(Node *owner, int id, unsigned int flags);

    int step;
    int state;
    int unknown_4c[5];
    int unknown_60;
    int unknown_64[3];
    int unknown_70;
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    int unknown_80;
};

Object_0007C250::Object_0007C250(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    step = 0;
    state = 0;
    unknown_4c[0] = 0;
    unknown_4c[1] = 0;
    unknown_4c[2] = 0;
    unknown_4c[3] = 0;
    unknown_4c[4] = 0;
    unknown_64[0] = 0;
    unknown_64[1] = 0;
    unknown_64[2] = 0;
    unknown_70 = 0;
    unknown_78 = 0;
    unknown_74 = data_001F97A8.func_00047110(0);
    Model_0007D5D0 *model = (Model_0007D5D0 *)func_00025700(0x14, 0, 0, 0);
    unknown_7c = model->unknown_00;
    unknown_80 = model->unknown_18;
    data_00251F24->func_000667D0();
}
