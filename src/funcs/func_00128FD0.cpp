/* sym: ??0Object_00127E60@@QAE@PAUNode@@HI@Z = 0x00128FD0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00127E60@@UAE@XZ = 0x00127E60 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00127E60@@UAEXXZ = 0x00129180 */
/* sym: ?func_00011C80@Object_00127E60@@UAEXH@Z = 0x0012B280 */
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

struct Row_00127E60 {
    int x[5];
    int y[5];
};

struct Entry_00227768 {
    int value_0;
    int value_4;
    int value_8;
};

struct Object_00120420 {
    char unknown_0000[0x1c8];
    int value_1c8;
    int value_1cc;
    char unknown_01d0[0x4];
    int value_1d4;
    char unknown_01d8[0x4];
    int value_1dc;
    char unknown_01e0[0x40];
    int value_220;
    int value_224;
    char unknown_0228[0x250];
    Entry_00227768 entry_478;
    char unknown_0484[0x420];
    int ids[4];
    char unknown_08b4[0x58];
    short value_90c;
    char unknown_090e[0x2ba];
    float value_bc8;
    char unknown_0bcc[0x34bc];
    Row_00127E60 rows[4];
    char unknown_4128[0x30];
    float value_4158;

    void func_00120420();
    void func_001205A0();
    void func_001205D0();
    void func_00122300();
    void func_0012BDA0();
    void func_0012BDF0();
    void func_0012EB90(int first, int second);
    void func_00130780();
    void func_001307C0();
    void func_00132BC0();
};

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern Object_0006E130 data_00252790;
extern Entry_00227768 data_00227768[];

// The class whose table is at 0x1DA350: overrides slots 1, 3 of Node.
struct Object_00127E60 : Node {
    Object_00127E60(Node *owner, int id, unsigned int flags);
    virtual ~Object_00127E60();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int value_44;
    int value_48;
    char unknown_04c[0x4];
    int value_50;
    int value_54;
    int value_58;
    int value_5c;
    char unknown_060[0x1c];
    int value_7c;
    char unknown_080[0xc];
    Row_00127E60 rows[4];
};

// Saves the y halves of the four rows of object 0x1DE2 and runs its func_00130780, func_0012BDF0 and
// func_001205A0; when its word at +0x90c is set, also sets mode 2 and loads entry value_48 of data_00227768.
Object_00127E60::Object_00127E60(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    Object_00120420 *scene = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
    this->flags |= 0x200;
    value_44 = 0;
    value_48 = 0;
    value_50 = 0;
    value_54 = 0;
    value_58 = 0;
    value_5c = 0;
    value_7c = 0;
    scene->value_4158 = 1.0f;
    for (int i = 0; i < 4; i++) {
        rows[i].y[0] = scene->rows[i].y[0];
        rows[i].y[1] = scene->rows[i].y[1];
        rows[i].y[2] = scene->rows[i].y[2];
        rows[i].y[3] = scene->rows[i].y[3];
        rows[i].y[4] = scene->rows[i].y[4];
    }
    scene->func_00130780();
    scene->func_0012BDF0();
    scene->func_001205A0();
    if (scene->value_90c != 0) {
        Object_00120420 *other = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
        value_44 = 2;
        other->value_bc8 = -482.0f;
        scene->value_1d4 = 1;
        scene->value_1c8 = 0;
        value_48 = scene->value_1dc;
        scene->func_00132BC0();
        scene->func_00122300();
        scene->value_1cc = 0x11;
        scene->entry_478.value_0 = data_00227768[value_48].value_0;
        scene->entry_478.value_4 = data_00227768[value_48].value_4;
        scene->entry_478.value_8 = data_00227768[value_48].value_8;
        scene->func_0012EB90(scene->value_220, scene->value_224);
    }
}
