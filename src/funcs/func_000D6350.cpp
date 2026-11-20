/* sym: ??0Object_000D6350@@QAE@PAUDesc_000D6350@@@Z = 0x000D6350 */
/* sym: ??1Object_000D6350@@UAE@XZ = 0x000D6530 */
/* sym: ??0Object_000CD1E0@@QAE@XZ = 0x000CD7D0 */
/* sym: ??1Object_000CD1E0@@UAE@XZ = 0x000E7EB0 */
/* sym: ?func_00011C90@Object_000CD1E0@@UAEXXZ = 0x000CD200 */
/* sym: ?func_00011C80@Object_000D6350@@UAEXH@Z = 0x000D6640 */
/* sym: ?func_00011C80_1@Object_000D6350@@UAEXH@Z = 0x000D6830 */
/* sym: ?func_000CD210@Object_000D6350@@UAEXXZ = 0x000D6980 */
/* sym: ?func_000CD800@Object_000D6350@@UAEXXZ = 0x000D6A00 */
/* sym: ?func_000CD850@Object_000D6350@@UAEXXZ = 0x000D7950 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
    int func_0001D950(void *source, int id);
};

struct Object_0003E750 {
    int func_0003EE90(void *effect, int first, int second, int third, float scale, int kind, int owner, int fourth);
    void func_0003F410(int key, int value);
};

struct Object_0006DB80 {
    int func_0006DAE0(int first, int second, int third, int fourth);
    void func_0006DEB0(int key, int value);
};

extern Object_00016200 data_0022FCE8;
extern Object_0003E750 data_002314B0;
extern Object_0006DB80 data_00251F78;
extern Mesh_00017F60 data_00217114;
extern char data_0021718C[];
extern char data_00216FC0[];

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);

struct Vector_000CD7D0 {
    int x;
    int y;
    int z;
};

struct Vector4_000D6350 {
    float x;
    float y;
    float z;
    float w;
};

struct Node_000D6350 {
    char unknown_00[0x54];
    Vector4_000D6350 position;
};

struct Model_000D6350 {
    char unknown_00[0xc];
    Node_000D6350 *node;
    char unknown_10[0x34];
    unsigned int key;
};

struct Holder_000D6350 {
    Model_000D6350 *model;
    char unknown_04[4];
    Model_000D6350 *shadow;
};

struct Source_000D6350 {
    void *data;
};

struct Resource_000D6350 {
    Holder_000D6350 *holder;
    char unknown_04[0x14];
    Source_000D6350 *source;
    char unknown_1c[4];
    Source_000D6350 *sound;
};

struct Desc_000D6350 {
    char unknown_00[8];
    int id;
    char unknown_0c[0x98];
    unsigned int flags;
};

// Seventeen words; the constructor sets only the first.
struct Block_000D6350 {
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

struct Object_000CD1E0 : Object_000CC600 {
    Object_000CD1E0();
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CD1E0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual void func_000CD440();
    virtual float func_000CD4F0();
    virtual void func_000CD390();

    int unknown_04;
    int state;
    int unknown_0c;
    int unknown_10;
    char unknown_14[0xc];
    Vector_000CD7D0 unknown_20;
    char unknown_2c[0xc];
    int unknown_38;
    int unknown_3c;
    int unknown_40;
    int unknown_44;
    int unknown_48;
    char unknown_4c[0x1c];
    int unknown_68;
};

// The class whose table is at 0x1CE5F0.
struct Object_000D6350 : Object_000CD1E0 {
    Object_000D6350(Desc_000D6350 *desc);
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D6350();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();

    char unknown_06c[8];
    char *table_074;
    char unknown_078[0x58];
    Vector4_000D6350 origin;
    char unknown_0e0[0xc];
    Holder_000D6350 *holder;
    Source_000D6350 *source;
    int handle_0f4;
    int value_0f8;
    char unknown_0fc[8];
    Mesh_00017F60 *mesh_104;
    const Mesh_00017F60 *template_108;
    int handle_10c;
    Block_000D6350 blocks[4];
    int mode_220;
    int flag_224;
    char unknown_228[0x7c];
    int handle_2a4;
    char unknown_2a8[4];
    int effect_2ac;
    int value_2b0;
    int value_2b4;
    int sound_2b8;
};

Object_000D6350::Object_000D6350(Desc_000D6350 *desc)
{
    Resource_000D6350 *resource = (Resource_000D6350 *)func_00025700(5, 9, 0, 0);
    holder = resource->holder;
    source = resource->source;
    holder->model->key = 0x299d7657;
    holder->shadow->key = 0x299d7657;
    state = 0;
    value_0f8 = 0;
    origin = holder->model->node->position;
    table_074 = data_0021718C;
    handle_0f4 = func_0005E790(source->data, 1);
    mesh_104 = data_0022FCE8.func_00019680(&data_00217114);
    template_108 = &data_00217114;
    for (int i = 0; i < 4; i++) {
        memset(&blocks[i], 0, sizeof(blocks[i]));
        blocks[i].kind = 0x43f;
    }
    mode_220 = 0x10;
    flag_224 = 1;
    handle_10c = data_0022FCE8.func_0001D950(resource->sound->data, desc->id);
    handle_2a4 = handle_10c;
    if (desc->flags & 0x4000) {
        effect_2ac = data_002314B0.func_0003EE90(data_00216FC0, -1, -1, 1, 0.2f, 1, desc->id, -1);
        data_002314B0.func_0003F410(effect_2ac, 0);
        sound_2b8 = data_00251F78.func_0006DAE0(1, 0, -1, -1);
        if (sound_2b8 != -1) {
            data_00251F78.func_0006DEB0(sound_2b8, 0);
        }
    } else {
        effect_2ac = -1;
        sound_2b8 = -1;
    }
    value_2b0 = 0;
    value_2b4 = 0;
}
