/* sym: ??0Object_0011EDA0@@QAE@PAUNode@@HIHHH@Z = 0x0011F1C0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_0011EDA0@@UAE@XZ = 0x0011EDA0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0011EDA0@@UAEXXZ = 0x0011EDB0 */
/* sym: ?func_00011C80@Object_0011EDA0@@UAEXH@Z = 0x0011EDE0 */
/* sym: ?func_00011C90_4@Object_0011EDA0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_0011EDA0@@UAEXH@Z = 0x000B3DE0 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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

struct Matrix_001BA950 {
    float m[4][4];
};

struct Model_0011F1C0 {
    char unknown_00[0x14];
    float position[3];
};

struct Sprite_0011F1C0 {
    char unknown_00[8];
    Model_0011F1C0 *model;
    char unknown_0c[0x18];
    unsigned int flags;
};

struct Vector3_0011F1C0 {
    float x;
    float y;
    float z;
};

struct Info_0011F1C0 {
    int value_00;
    int value_04;
    int value_08;
    int value_0c;
    int value_10;
    int value_14;
    int value_18;
    char unknown_1c[0xc];
};

struct Object_00039BE0 {
    void func_0003A690(int first, int second, int third, void *info);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern Object_00039BE0 data_001EFFB0;
extern int data_0021C098[];
extern int data_0021C510[];
extern Vector3_0011F1C0 data_00225AA0[];

void *func_00025700(unsigned int index, int first, int second, int third);
void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAAE0(float *vector);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void func_001BB230(float x, float y, float z);

// The class whose table is at 0x1D8F20.
struct Object_0011EDA0 : Node {
    Object_0011EDA0(Node *owner, int id, unsigned int flags, int number, int second, int kind);
    virtual ~Object_0011EDA0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);

    void func_0011F120();

    char unknown_44[4];
    int value_48;
    int value_4c;
    int value_50;
    int value_54;
    int value_58;
    int value_5c;
    int value_60;
    int value_64;
    int value_68;
    int value_6c;
    char unknown_070[0xc];
    Sprite_0011F1C0 *sprite_7c;
    Sprite_0011F1C0 *sprite_80;
    Matrix_001BA950 matrix;
    float offset[3];
    unsigned int state;
    int value_d4;
};

// Looks up entry (number - 1, second, kind) in data_001EFFB0, creates the two sprites and keeps the second's
// transform, scaled by 0.45 about its position, in matrix.
Object_0011EDA0::Object_0011EDA0(Node *owner, int id, unsigned int flags, int number, int second, int kind)
    : Node(owner, id, flags)
{
    Info_0011F1C0 info;
    data_0022FCE0->func_000128C0(0x128a);
    value_48 = kind;
    value_50 = second;
    value_4c = number - 1;
    value_54 = data_0021C098[value_48];
    data_001EFFB0.func_0003A690(value_54, value_50, value_4c, &info);
    value_58 = info.value_04;
    value_5c = info.value_00;
    value_60 = info.value_08;
    value_64 = info.value_0c;
    value_68 = (info.value_18 & 0xffff) | (info.value_14 << 16);
    value_6c = info.value_00;
    func_0011F120();
    sprite_7c = 0;
    offset[0] = -32.0f;
    offset[1] = 24.0f;
    offset[2] = 1220.0f;
    state = 0;
    value_d4 = 0;
    sprite_7c = (Sprite_0011F1C0 *)func_00025700(0x12, 0, 2, value_4c + 0xe);
    if (sprite_7c) {
        sprite_7c->flags &= ~1;
        sprite_7c->flags &= ~8;
    }
    sprite_80 = (Sprite_0011F1C0 *)func_00025700(0x12, 0, 2, data_0021C510[value_58] + 0x1d);
    if (sprite_80) {
        sprite_80->flags &= ~1;
        sprite_80->flags &= ~8;
        func_001BAA00();
        func_001BAAE0(sprite_80->model->position);
        func_001BAAA0(&data_00225AA0[value_4c].x);
        func_001BAAA0(sprite_80->model->position);
        func_001BB230(0.45f, 0.45f, 0.45f);
        func_001BAAE0(sprite_80->model->position);
        func_001BA950(&matrix);
        func_001BAA50();
    }
}
