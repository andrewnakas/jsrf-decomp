/* sym: ??1Object_001217D0@@UAE@XZ = 0x001217D0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_001217D0@@UAEXXZ = 0x00121980 */
/* sym: ?func_00011C80@Object_001217D0@@UAEXH@Z = 0x00121F10 */
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

struct Row_001217D0 {
    int x[5];
    int y[5];
};

struct Object_00120420 {
    char unknown_0000[0x4088];
    Row_001217D0 rows[4];

    void func_00120420();
    void func_00120510();
    void func_00132550();
    void func_00132580();
    void func_001205A0();
    void func_001205D0();
};

struct Game {
    void func_000127C0(int first, int second);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1D9118: overrides slots 1, 3 of Node.
struct Object_001217D0 : Node {
    Object_001217D0(Node *owner, int id, unsigned int flags);
    virtual ~Object_001217D0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int value_44;
    char unknown_48[0x4];
    Row_001217D0 rows[4];
};

// Runs func_00120510, func_00132580 and func_001205D0 of object 0x1DE2, then restores the y halves of its four
// rows that the constructor saved.
Object_001217D0::~Object_001217D0()
{
    Object_00120420 *scene = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
    scene->func_00120510();
    scene->func_00132580();
    scene->func_001205D0();
    for (int i = 0; i < 4; i++) {
        scene->rows[i].y[0] = rows[i].y[0];
        scene->rows[i].y[1] = rows[i].y[1];
        scene->rows[i].y[2] = rows[i].y[2];
        scene->rows[i].y[3] = rows[i].y[3];
        scene->rows[i].y[4] = rows[i].y[4];
    }
}
