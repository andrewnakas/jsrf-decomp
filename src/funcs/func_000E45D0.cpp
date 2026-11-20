/* cflags: /Oy- */
/* sym: ??0Object_000E45D0@@QAE@PAUNode@@HIPAUInit_000E45D0@@@Z = 0x000E45D0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000E45D0@@UAEXXZ = 0x000E4910 */
/* sym: ?func_00011C90_1@Object_000E45D0@@UAEXXZ = 0x000E4F10 */
/* sym: ?func_00011C80@Object_000E45D0@@UAEXH@Z = 0x000E3930 */
/* sym: ?func_00011C80_3@Object_000E45D0@@UAEXH@Z = 0x000E3BB0 */
/* sym: ?func_00011C80_4@Object_000E45D0@@UAEXH@Z = 0x000B3DE0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Mesh_00017FD0;

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Vector4_000E45D0 {
    float x;
    float y;
    float z;
    float w;
};

struct Rotation_000E45D0 {
    int x;
    int y;
    int z;
};

struct Object_00016200 {
    Mesh_00017FD0 *func_000196F0(const Mesh_00017FD0 *mesh);
    int func_0001D810(void *list, int index);
    int func_0001D950(void *source, int id);
};

struct Object_0003E750 {
    int func_0003EE90(void *effect, int first, int second, int third, float scale, int kind, int owner, int fourth);
};

struct Object_0006DB80 {
    int func_0006DAE0(int first, int second, int third, int fourth);
};

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00016200 data_0022FCE8;
extern Object_0003E750 data_002314B0;
extern Object_0006DB80 data_00251F78;
extern Object_00046670 data_001F93C8;
extern Mesh_00017FD0 data_00218AB4;
extern Vector4_000E45D0 data_00218AE4;
extern char data_00218990[];
extern unsigned char data_00231D40[];

struct List_000E45D0 {
    void *entries;
    int count;
    int unknown_08;
};

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Node_000E45D0 {
    char unknown_00[0x54];
    Vector4_000E45D0 position;
};

struct Model_000E45D0 {
    char unknown_00[0xc];
    Node_000E45D0 *node;
};

struct Holder_000E45D0 {
    Model_000E45D0 *model;
};

struct Source_000E45D0 {
    void *data;
};

struct Sound_000E45D0 {
    void *data;
};

struct Resource_000E45D0 {
    Holder_000E45D0 *holder;
    char unknown_04[0x14];
    Source_000E45D0 *source;
    char unknown_1c[4];
    Sound_000E45D0 *sound;
};

struct Init_000E45D0 {
    Vector3 position;
    Rotation_000E45D0 rotation;
    int value_18;
    Vector3 *target;
};

struct Owner_000E45D0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

// Seventeen words; the constructor sets only the first.
struct Block_000E45D0 {
    int kind;
    int unknown_04[16];
};

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

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CED20 (Node) and 0x1CED18 (Object_000C60C0 at +0x44).
struct Object_000E45D0 : Node, Object_000C60C0 {
    Object_000E45D0(Node *owner, int id, unsigned int flags, Init_000E45D0 *init);
    virtual ~Object_000E45D0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Vector3 position;
    Rotation_000E45D0 rotation;
    char unknown_060[0x18];
    Vector4_000E45D0 origin;
    float value_088;
    char unknown_08c[4];
    int value_090;
    char unknown_094[4];
    int sound_098;
    int value_09c;
    char unknown_0a0[0x1c];
    int value_0bc;
    char unknown_0c0[4];
    int value_0c4;
    int value_0c8;
    Vector3 target_0cc;
    int value_0d8;
    Vector3 position_0dc;
    Vector3 position_0e8;
    char unknown_0f4[0x50];
    int value_144;
    int value_148;
    Vector4_000E45D0 value_14c;
    Vector3 *target;
    int value_160;
    Holder_000E45D0 *holder;
    Source_000E45D0 *source;
    int handle_16c;
    int handle_170;
    int value_174;
    char unknown_178[4];
    int handle_17c;
    char unknown_180[0x28];
    Block_000E45D0 block;
    int mode_1ec;
    int flag_1f0;
    Mesh_00017FD0 *mesh_1f4;
    int value_1f8;
    char unknown_1fc[0x14];
    int handle_210;
    int handle_214;
    int effect_218;
    int value_21c;
    int value_220;
    int value_224;
};

Object_000E45D0::Object_000E45D0(Node *owner, int id, unsigned int flags, Init_000E45D0 *init)
    : Node(owner, id, flags)
{
    position = init->position;
    rotation = init->rotation;
    target = init->target;
    value_160 = init->value_18;
    value_090 = 0;
    value_0bc = 0;
    value_0c8 = 0;
    value_0c4 = 0;
    target_0cc = *target;
    position_0e8 = position;
    value_0d8 = 0;
    position_0dc = position;
    value_144 = 0xf;
    value_148 = 0;
    Resource_000E45D0 *resource = (Resource_000E45D0 *)func_00025700(5, 0x10, 0, 0);
    holder = resource->holder;
    origin = holder->model->node->position;
    value_14c = data_00218AE4;
    source = resource->source;
    value_174 = 0;
    handle_16c = func_0005E790(source->data, 1);
    handle_170 = func_0005E790(source->data, 1);
    handle_17c = data_0022FCE8.func_0001D950(resource->sound->data, this->id);
    List_000E45D0 list;
    list.entries = data_00231D40;
    list.count = 2;
    list.unknown_08 = 0;
    handle_210 = data_0022FCE8.func_0001D810(&list, -1);
    list.count = 3;
    handle_214 = data_0022FCE8.func_0001D810(&list, -1);
    mesh_1f4 = data_0022FCE8.func_000196F0(&data_00218AB4);
    mode_1ec = 8;
    flag_1f0 = 1;
    value_1f8 = 0;
    memset(&block, 0, sizeof(block));
    block.kind = 0xf3ff;
    if (((Owner_000E45D0 *)parent)->flags & 0x4000) {
        func_001BA9C0();
        func_001BAAA0(&position.x);
        func_001BB330(rotation.y + 0x8000);
        func_001BB2E0(rotation.x);
        func_001BB380(rotation.z);
        effect_218 = data_002314B0.func_0003EE90(data_00218990, -1, -1, 1, 0.1f, 1, this->id, -1);
        func_001BAA50();
        sound_098 = data_00251F78.func_0006DAE0(1, 0, -1, -1);
    } else {
        effect_218 = -1;
        sound_098 = -1;
    }
    value_21c = 0;
    value_220 = 0;
    value_09c = 0;
    value_224 = -1;
    value_088 = data_001F93C8.func_000466C0(&position, -1);
}
