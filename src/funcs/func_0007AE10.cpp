/* sym: ??0Object_0007AF70@@QAE@PAUNode@@HIH@Z = 0x0007AE10 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??1Object_0007AF70@@UAE@XZ = 0x0007AF70 */
/* sym: ?func_00011C90@Object_0007AF70@@UAEXXZ = 0x0007B8D0 */
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

struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

struct Info_0007AE10 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
};

void *func_00025700(unsigned int index, int first, int second, int third);
void func_0004E930(int first, int second, int third);

// The class whose table is at 0x1CCE30: overrides slot 1 of Node.
struct Object_0007AF70 : Node {
    Object_0007AF70(Node *owner, int id, unsigned int flags, int argument);
    virtual ~Object_0007AF70();
    virtual void func_00011C90();

    int unknown_44;
    int unknown_48;
    Info_0007AE10 *info;
    int unknown_50;
    int unknown_54;
    int unknown_58;
    int unknown_5c;
};

// The fourth argument is unused; the only caller (0x4F94A) passes 0.
Object_0007AF70::Object_0007AF70(Node *owner, int id, unsigned int flags, int) : Node(owner, id, flags)
{
    if (data_0022FCE0->func_000127E0(0x1cb)) {
        info = (Info_0007AE10 *)func_00025700(0x15, 0, 1, 0);
        unknown_5c = 1;
    } else {
        info = (Info_0007AE10 *)func_00025700(0x14, 0, 1, 0);
        unknown_5c = 0;
        data_0022FCE0->func_000127C0(0xd, info->unknown_08 - 1);
        data_0022FCE0->func_000127C0(0xe, info->unknown_0c - 1);
        data_0022FCE0->func_000127C0(0xf, info->unknown_10 - 1);
        data_0022FCE0->func_000127C0(0x10, info->unknown_14 - 1);
    }
    data_0022FCE0->func_000127C0(2, info->unknown_04 >> 8 & 0xff);
    data_0022FCE0->func_000127C0(3, info->unknown_04 & 0xff);
    func_0004E930(data_0022FCE0->func_000127E0(2), data_0022FCE0->func_000127E0(3), 0);
    unknown_44 = 0;
    unknown_48 = 0;
    unknown_50 = 1;
    unknown_54 = 1;
    unknown_58 = 1;
}
