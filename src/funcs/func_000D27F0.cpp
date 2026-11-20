/* cflags: /Oy- */
/* sym: ??0Object_000D27F0@@QAE@PAUDesc_000D27F0@@@Z = 0x000D27F0 */
/* sym: ??1Object_000CC600@@UAE@XZ = 0x000E7EB0 */
/* sym: ?func_000CD1E0@Object_000D27F0@@UAEXXZ = 0x000D2B90 */
/* sym: ?func_00011C90@Object_000D27F0@@UAEXXZ = 0x000D2C50 */
/* sym: ?func_00011C80@Object_000D27F0@@UAEXH@Z = 0x000D2D80 */
/* sym: ?func_00011C80_1@Object_000D27F0@@UAEXH@Z = 0x000D3040 */
extern "C" void *memset(void *destination, int value, unsigned int size);
extern "C" void *memcpy(void *destination, const void *source, unsigned int size);

struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
    int func_0001D810(void *list, int index);
    void func_0001B4C0(int handle, int flags);
};

struct Object_0003E750 {
    int func_0003EE90(void *effect, int first, int second, int third, float scale, int kind, int owner, int fourth);
    void func_0003F410(int key, int value);
};

struct Object_0006DB80 {
    int func_0006DAE0(int first, int second, int third, int fourth);
};

extern Object_00016200 data_0022FCE8;
extern Object_0003E750 data_002314B0;
extern Object_0006DB80 data_00251F78;
extern Mesh_00017F60 data_00216958;
extern Mesh_00017F60 data_00216994;
extern char data_00216830[];
extern unsigned char data_00231D40[];

// 24 bytes; 0x231D40 holds 300 of them, filled from the one at 0x216A74.
struct Entry_000D27F0 {
    int values[6];
};

extern Entry_000D27F0 data_00216A74;

struct List_000D27F0 {
    void *entries;
    int count;
    int unknown_08;
};

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);
int func_0005E7B0(void *target, int first, int second, int third, int fourth);

struct Vector4_000D27F0 {
    float x;
    float y;
    float z;
    float w;
};

struct Node_000D27F0 {
    char unknown_00[0x54];
    Vector4_000D27F0 position;
};

struct Model_000D27F0 {
    int unknown_00;
    int unknown_04;
    void *target;
    Node_000D27F0 *node;
};

struct Holder_000D27F0 {
    Model_000D27F0 *model;
};

struct Source_000D27F0 {
    void *data;
    char unknown_04[0xac];
    int value_b0;
};

struct Resource_000D27F0 {
    Holder_000D27F0 *holder;
    char unknown_04[0x14];
    Source_000D27F0 *source;
};

struct Desc_000D27F0 {
    char unknown_00[8];
    int owner;
    char unknown_0c[0x98];
    unsigned int flags;
};

// Seventeen words; the constructor sets only the first.
struct Block_000D27F0 {
    int kind;
    int unknown_04[16];
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE450.
struct Object_000D27F0 : Object_000CC600 {
    Object_000D27F0(Desc_000D27F0 *desc);
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D27F0();

    int unknown_004;
    int value_008;
    char unknown_00c[0x50];
    Vector4_000D27F0 position;
    char unknown_06c[0xe88];
    Holder_000D27F0 *holder;
    Model_000D27F0 *model_ef8;
    int value_efc;
    Source_000D27F0 *source;
    int value_f04;
    int value_f08;
    int value_f0c;
    int handle_f10;
    int handle_f14;
    int handle_f18;
    int value_f1c;
    int value_f20;
    int value_f24;
    char unknown_f28[8];
    int value_f30;
    int value_f34;
    int value_f38;
    int value_f3c;
    Block_000D27F0 block;
    int mode_f84;
    int flag_f88;
    Mesh_00017F60 *mesh_f8c;
    int value_f90;
    char unknown_f94[0x14];
    int mode_fa8;
    int flag_fac;
    Mesh_00017F60 *mesh_fb0;
    int value_fb4;
    char unknown_fb8[0x2c];
    int handle_fe4;
    int effect_fe8;
    int value_fec;
    int value_ff0;
    int sound_ff4;
    int value_ff8;
    int value_ffc;
};

Object_000D27F0::Object_000D27F0(Desc_000D27F0 *desc)
{
    Resource_000D27F0 *resource = (Resource_000D27F0 *)func_00025700(5, 0xb, 0, 0);
    holder = resource->holder;
    source = resource->source;
    value_efc = 6;
    position = holder->model->node->position;
    value_008 = 0;
    value_f34 = 0;
    value_f30 = 0;
    value_f38 = 0;
    value_f1c = 0;
    value_f24 = 0;
    value_f20 = 0;
    value_f04 = source->value_b0;
    value_f0c = 0;
    value_f08 = 0;
    value_f3c = 1;
    handle_f10 = func_0005E790(source->data, 1);
    handle_f14 = func_0005E790(source->data, 1);
    handle_f18 = func_0005E790(source->data, 1);
    func_0005E7B0(holder->model->target, handle_f10, 0, value_f04, 0);
    memset(&block, 0, sizeof(block));
    block.kind = 0x13f;
    mesh_f8c = data_0022FCE8.func_00019680(&data_00216958);
    mode_f84 = 2;
    flag_f88 = 1;
    value_f90 = 0;
    mesh_fb0 = data_0022FCE8.func_00019680(&data_00216994);
    flag_fac = 1;
    value_fb4 = 0;
    mode_fa8 = 0x20;
    *(Entry_000D27F0 *)data_00231D40 = data_00216A74;
    memcpy(data_00231D40 + sizeof(Entry_000D27F0), data_00231D40, 299 * sizeof(Entry_000D27F0));
    List_000D27F0 list;
    list.entries = data_00231D40;
    list.count = 300;
    list.unknown_08 = 0;
    handle_fe4 = data_0022FCE8.func_0001D810(&list, -1);
    data_0022FCE8.func_0001B4C0(handle_fe4, 0);
    if (desc->flags & 0x4000) {
        effect_fe8 = data_002314B0.func_0003EE90(data_00216830, -1, -1, 1, 6.0f, 2, desc->owner, -1);
        data_002314B0.func_0003F410(effect_fe8, 0);
        sound_ff4 = data_00251F78.func_0006DAE0(1, 0, -1, -1);
    } else {
        effect_fe8 = -1;
        sound_ff4 = -1;
    }
    value_ff8 = 0;
    value_fec = 0;
    value_ff0 = 0;
    Resource_000D27F0 *other = (Resource_000D27F0 *)func_00025700(5, 0x12, 0, 0);
    if (other) {
        model_ef8 = other->holder->model;
    } else {
        model_ef8 = 0;
    }
    value_ffc = -1;
}
