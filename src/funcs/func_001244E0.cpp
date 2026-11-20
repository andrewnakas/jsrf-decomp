/* const: 0x40000 */
/* const: 0x80000 */
/* sym: ??0Object_00124700@@QAE@PAUNode@@HI@Z = 0x001244E0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00124700@@UAE@XZ = 0x00124700 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00124700@@UAEXXZ = 0x00125100 */
/* sym: ?func_00011C80@Object_00124700@@UAEXH@Z = 0x00124BD0 */
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

struct Row_00124700 {
    int x[5];
    int y[5];
};

struct Object_00120420 {
    char unknown_0000[0x4088];
    Row_00124700 rows[4];

    void func_00120420();
    void func_00120510();
    void func_00132550();
    void func_00132580();
    void func_001205A0();
    void func_001205D0();
};

struct Object_00039BE0 {
    int func_0003A820(int first, int second, int third);
    int func_0003A870(int first, int second, int third);
};

struct Game {
    void func_000127C0(int first, int second);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern Object_00039BE0 data_001EFFB0;
extern void *data_00258F74;
extern void *data_00258F78;
extern void *data_00258F7C;
extern void *data_00258F80;
extern void *data_00258F84;


// The class whose table is at 0x1DA2C0: overrides slots 1, 3 of Node.
struct Object_00124700 : Node {
    Object_00124700(Node *owner, int id, unsigned int flags);
    virtual ~Object_00124700();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int value_44;
    char unknown_48[0x10];
    Row_00124700 rows[4];
};

// Sets flag 0x20, allocates five buffers, runs func_00120420, func_00132550 and func_001205A0 of object 0x1DE2,
// fills the object's first row from data_001EFFB0 and keeps a copy of its four rows.
Object_00124700::Object_00124700(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    this->flags |= 0x20;
    value_44 = 0;
    Object_00120420 *scene = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
    data_00258F74 = operator new(0x8000);
    data_00258F78 = operator new(0x8000);
    data_00258F7C = operator new(0x40000);
    data_00258F80 = operator new(0x40000);
    data_00258F84 = operator new(0x80000);
    scene->func_00120420();
    scene->func_00132550();
    scene->func_001205A0();
    data_0022FCE0->func_000127C0(0x1c8, 1);
    scene->rows[0].y[0] = data_001EFFB0.func_0003A820(0, 0, 0);
    scene->rows[0].y[1] = data_001EFFB0.func_0003A820(0, 1, 0);
    scene->rows[0].y[2] = data_001EFFB0.func_0003A820(0, 2, 0);
    scene->rows[0].y[3] = data_001EFFB0.func_0003A820(0, 3, 0);
    scene->rows[0].y[4] = data_001EFFB0.func_0003A820(0, 4, 0);
    scene->rows[0].x[0] = data_001EFFB0.func_0003A870(0, 0, 0);
    scene->rows[0].x[1] = data_001EFFB0.func_0003A870(0, 1, 0);
    scene->rows[0].x[2] = data_001EFFB0.func_0003A870(0, 2, 0);
    scene->rows[0].x[3] = data_001EFFB0.func_0003A870(0, 3, 0);
    scene->rows[0].x[4] = data_001EFFB0.func_0003A870(0, 4, 0);
    for (int i = 0; i < 4; i++) {
        rows[i].y[0] = scene->rows[i].y[0];
        rows[i].x[0] = scene->rows[i].x[0];
        rows[i].y[1] = scene->rows[i].y[1];
        rows[i].x[1] = scene->rows[i].x[1];
        rows[i].y[2] = scene->rows[i].y[2];
        rows[i].x[2] = scene->rows[i].x[2];
        rows[i].y[3] = scene->rows[i].y[3];
        rows[i].x[3] = scene->rows[i].x[3];
        rows[i].y[4] = scene->rows[i].y[4];
        rows[i].x[4] = scene->rows[i].x[4];
    }
}
