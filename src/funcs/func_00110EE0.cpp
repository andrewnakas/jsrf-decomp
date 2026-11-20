/* const: 0x10003 */
/* sym: ??0Object_001112A0@@QAE@PAUNode@@HIHH@Z = 0x00110EE0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_001112A0@@UAE@XZ = 0x001112A0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Object_001118F0@@QAE@PAUNode@@HII@Z = 0x00111DF0 */
/* sym: ??0Object_000F97D0@@QAE@PAUNode@@HIMMMH@Z = 0x000F97D0 */
/* sym: ??0Object_000F7C50@@QAE@PAUNode@@HIHHHHPAM11PAXHI@Z = 0x000F7C50 */
/* sym: ??0Object_000FBFD0@@QAE@PAUNode@@HIHPAHIH@Z = 0x000FBFD0 */
/* sym: ?func_00011C90@Object_001112A0@@UAEXXZ = 0x001117B0 */
/* sym: ?func_00011C80@Object_001112A0@@UAEXH@Z = 0x00111320 */
/* sym: ?func_00011C90_2@Object_001112A0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_001112A0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_4@Object_001112A0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_001112A0@@UAEXH@Z = 0x000B3DE0 */
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

struct Sprite_00110EE0 {
    char unknown_00[0x24];
    unsigned int flags;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

// What func_0004EA50 reports at +0x114: the course kind and its extras.
struct Course_00110EE0 {
    int kind;
    int value_04;
};

// The block func_0004EA50 fills in.
struct Info_0004D460 {
    char unknown_000[0x114];
    Course_00110EE0 *course;
};

struct Menu_00110EE0 {
    char unknown_000[0x148];
    int value_148;
};

// Object 9: the current stage id at +0x104C (area in the high word, number in the low word).
struct Stage_00110EE0 {
    char unknown_0000[0x104c];
    unsigned int stage;
};

struct Light_00046920 {
    int unknown_00;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    Vector3 direction;
    char unknown_1c[0x24];
    unsigned int color_40;
    int unknown_44;
    unsigned int color_48;
    int unknown_4c;
    int value_50;
    char unknown_54[0x1c];
};

struct Object_00046670 {
    void func_00046700(const Light_00046920 *light);
    void func_00046740(Light_00046920 *light);
    void func_00046940(int enable);
};

struct Object_00043700 {
    int func_00043700();
};

struct Game {
    void *func_000128C0(int id);
    int func_000128E0(int first, int last);
    void func_00012AC0(int first, int second);
};

// The node 0x111DF0 builds (table 0x1D27C8); 0x188 bytes.
struct Object_001118F0 : Node {
    Object_001118F0(Node *owner, int id, unsigned int flags, unsigned int stage);

    char unknown_44[0x144];
};

// The node 0xF97D0 builds; 0x74 bytes.
struct Object_000F97D0 : Node {
    Object_000F97D0(Node *owner, int id, unsigned int flags, float first, float second, float third, int value);

    char unknown_44[0x30];
};

// The node 0xF7C50 builds (table 0x1D0770); 0xCC bytes.
struct Object_000F7C50 : Node {
    Object_000F7C50(Node *owner, int id, unsigned int flags, int first, int second, int third, int fourth,
                    float *position, float *rotation, float *scale, void *block, int value, unsigned int color);

    char unknown_44[0x88];
};

// The node 0xFBFD0 builds (table 0x1D1B68); 0xAC bytes.
struct Object_000FBFD0 : Node {
    Object_000FBFD0(Node *owner, int id, unsigned int flags, int value, int *result, unsigned int color, int mode);

    char unknown_44[0x68];
};

extern "C" void *memset(void *destination, int value, unsigned int size);

extern Game *data_0022FCE0;
extern Vector3 data_00220A58;
extern Object_00043700 data_001FC724;
extern Object_00046670 data_001F93C8;

int func_000F7BE0(unsigned int stage);
void func_0004EA50(Info_0004D460 *info);
void *func_00025700(unsigned int index, int first, int second, int third);
void func_00118780(int value);

// The class whose table is at 0x1D2788.
struct Object_001112A0 : Node {
    Object_001112A0(Node *owner, int id, unsigned int flags, int value, int mode);
    virtual ~Object_001112A0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);

    int value_44;
    Sprite_00110EE0 *sprite_48;
    Sprite_00110EE0 *sprite_4c;
    Sprite_00110EE0 *sprite_50;
    Sprite_00110EE0 *sprite_54;
    Sprite_00110EE0 *animation;
    float frame;
    Sprite_00110EE0 *sprite_60;
    Sprite_00110EE0 *sprite_64;
    Sprite_00110EE0 *sprite_68;
    Sprite_00110EE0 *sprite_6c;
    Vector3 position;
    int value_7c;
    int unknown_80;
    int value_84;
    char unknown_88[0x8];
    int id_90;
    int area;
    int number;
    int mode;
    Course_00110EE0 *course;
};

// Creates the stage select's sprites and child nodes for the current stage, then sets up the light.
Object_001112A0::Object_001112A0(Node *owner, int id, unsigned int flags, int value, int mode)
    : Node(owner, id, flags)
{
    Menu_00110EE0 *menu = (Menu_00110EE0 *)data_0022FCE0->func_000128C0(0x1163);
    if (menu) {
        menu->value_148 = 0;
    }
    value_44 = value;
    this->mode = mode;
    sprite_48 = 0;
    sprite_4c = 0;
    sprite_50 = 0;
    sprite_64 = 0;
    sprite_68 = 0;
    sprite_6c = 0;
    Info_0004D460 info;
    func_0004EA50(&info);
    course = info.course;
    position.x = data_00220A58.x;
    position.y = data_00220A58.y;
    position.z = data_00220A58.z;
    value_7c = 0;
    value_84 = 0;
    unsigned int stage;
    Stage_00110EE0 *current = (Stage_00110EE0 *)data_0022FCE0->func_000128C0(9);
    if (current) {
        stage = current->stage;
        area = ((unsigned short *)&current->stage)[1];
        number = current->stage & 0xffff;
    } else {
        stage = 0;
        area = 1;
        number = 0;
    }
    sprite_48 = (Sprite_00110EE0 *)func_00025700(10, 0, 1, 3);
    sprite_4c = (Sprite_00110EE0 *)func_00025700(10, 0, 1, 4);
    sprite_54 = (Sprite_00110EE0 *)func_00025700(10, 0, 1, 0x6b);
    animation = (Sprite_00110EE0 *)func_00025700(10, 0, 2, 0x12);
    frame = 0.0f;
    sprite_60 = (Sprite_00110EE0 *)func_00025700(10, 0, 1, 0x80);
    id_90 = data_0022FCE0->func_000128E0(0x1208, 0x1288);
    new Object_001118F0((Node *)data_0022FCE0->func_000128C0(9), id_90, 0x10003, stage);
    if (course->value_04) {
        new Object_000F97D0(this, -1, 0x100, 5.0f, 48.0f, 2.0f, course->value_04);
    }
    if (course) {
        if (data_001FC724.func_00043700() == 0) {
            new Object_000F7C50(this, -1, 0x100, 0, -1, course->kind + 0xf, -1, 0, 0, 0, 0, 0, 0);
        } else {
            new Object_000F7C50(this, -1, 0x100, 0, -1, course->kind + 0xf, -1, 0, 0, 0, 0, 0, 0x80000000);
        }
        if (course->kind == 4 || course->kind == 0xc) {
            sprite_64 = (Sprite_00110EE0 *)func_00025700(0xb, 0, 1, 0x10);
            sprite_68 = (Sprite_00110EE0 *)func_00025700(0xb, 0, 4, 7);
        }
    }
    int index = func_000F7BE0(stage);
    new Object_000FBFD0(this, -1, 0x100, index + 0xf, 0, 0x80000000, -1);
    data_0022FCE0->func_00012AC0(0x469696, 1);
    Light_00046920 light;
    memset(&light, 0, sizeof(light));
    light.direction.x = 0.0f;
    light.direction.y = 0.0f;
    light.direction.z = 1.0f;
    light.value_50 = 0;
    light.color_04 = 0xffffff;
    light.color_08 = 0;
    data_001F93C8.func_00046700(&light);
    data_001F93C8.func_00046740(&light);
    data_001F93C8.func_00046940(0);
    func_00118780(1);
}
