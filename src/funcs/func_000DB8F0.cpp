/* sym: ??0Object_000DB8F0@@QAE@PAUDesc_000DB8F0@@@Z = 0x000DB8F0 */
/* sym: ??1Object_000DB8F0@@UAE@XZ = 0x000DBA90 */
/* sym: ??0Object_000CD1E0@@QAE@XZ = 0x000CD7D0 */
/* sym: ??1Object_000CD1E0@@UAE@XZ = 0x000E7EB0 */
/* sym: ?func_00011C90@Object_000CD1E0@@UAEXXZ = 0x000CD200 */
/* sym: ?func_00011C80@Object_000DB8F0@@UAEXH@Z = 0x000DBBA0 */
/* sym: ?func_00011C80_1@Object_000DB8F0@@UAEXH@Z = 0x000DBD80 */
/* sym: ?func_000CD210@Object_000DB8F0@@UAEXXZ = 0x000DBF00 */
/* sym: ?func_000CD800@Object_000DB8F0@@UAEXXZ = 0x00011C90 */
/* sym: ?func_000CD850@Object_000DB8F0@@UAEXXZ = 0x000DBF40 */
/* sym: ?func_000D77D0@Object_000DB8F0@@UAEXXZ = 0x000DC490 */
/* sym: ?func_000D7880@Object_000DB8F0@@UAEXXZ = 0x000DC750 */
/* sym: ?func_000CD390@Object_000DB8F0@@UAEXXZ = 0x000DC290 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
    int func_0001D950(void *source, int id);
};

struct Object_0003E750 {
    int func_0003EE90(void *effect, int first, int second, int third, float scale, int kind, int owner, int fourth);
};

struct Object_0006DB80 {
    int func_0006DAE0(int first, int second, int third, int fourth);
};

extern Object_00016200 data_0022FCE8;
extern Object_0003E750 data_002314B0;
extern Object_0006DB80 data_00251F78;
extern Mesh_00017F60 data_00217724;
extern char data_0021779C[];
extern char data_002175B0[];

void *func_00025700(unsigned int index, int first, int second, int third);

struct Vector_000CD7D0 {
    int x;
    int y;
    int z;
};

struct Vector4_000DB8F0 {
    float x;
    float y;
    float z;
    float w;
};

struct Node_000DB8F0 {
    char unknown_00[0x54];
    Vector4_000DB8F0 position;
};

struct Model_000DB8F0 {
    char unknown_00[0xc];
    Node_000DB8F0 *node;
};

struct Body_000DB8F0 {
    char unknown_00[0x74];
    float range;
    char unknown_78[4];
    float scale;
};

struct Holder_000DB8F0 {
    Model_000DB8F0 *model;
    Body_000DB8F0 *body;
};

struct Source_000DB8F0 {
    void *data;
};

struct Resource_000DB8F0 {
    Holder_000DB8F0 *holder;
    char unknown_04[0x14];
    Source_000DB8F0 *source;
    char unknown_1c[4];
    Source_000DB8F0 *sound;
};

struct Desc_000DB8F0 {
    char unknown_00[8];
    int id;
    char unknown_0c[0x98];
    unsigned int flags;
};

// Seventeen words; the constructor sets only the first.
struct Block_000DB8F0 {
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

// The class whose table is at 0x1CE780; slot 6 is empty (folded with Node's).
struct Object_000DB8F0 : Object_000CD1E0 {
    Object_000DB8F0(Desc_000DB8F0 *desc);
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000DB8F0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();
    virtual void func_000CD390();

    char unknown_06c[8];
    char *table_074;
    char unknown_078[0x20];
    int value_098;
    Vector4_000DB8F0 origin;
    char unknown_0ac[8];
    Holder_000DB8F0 *holder;
    Mesh_00017F60 *mesh_0b8;
    const Mesh_00017F60 *template_0bc;
    int handle_0c0;
    Block_000DB8F0 block;
    int mode_108;
    int flag_10c;
    char unknown_110[0x1c];
    int handle_12c;
    char unknown_130[4];
    int effect_134;
    int value_138;
    int value_13c;
    int sound_140;
    int first_144[2];
    int second_14c[2];
    int value_154;
    int value_158;
};

Object_000DB8F0::Object_000DB8F0(Desc_000DB8F0 *desc)
{
    Resource_000DB8F0 *resource = (Resource_000DB8F0 *)func_00025700(5, 7, 0, 0);
    holder = resource->holder;
    Body_000DB8F0 *body = holder->body;
    body->range = 300.0f;
    body->scale = 3.0f;
    state = 0;
    value_098 = 0;
    origin = holder->model->node->position;
    table_074 = data_0021779C;
    mesh_0b8 = data_0022FCE8.func_00019680(&data_00217724);
    template_0bc = &data_00217724;
    handle_0c0 = data_0022FCE8.func_0001D950(resource->sound->data, desc->id);
    handle_12c = handle_0c0;
    memset(&block, 0, sizeof(block));
    block.kind = 0x43f;
    mode_108 = 2;
    flag_10c = 1;
    if (desc->flags & 0x4000) {
        effect_134 = data_002314B0.func_0003EE90(data_002175B0, -1, -1, 1, 1.0f, 1, desc->id, -1);
        sound_140 = data_00251F78.func_0006DAE0(1, 0, -1, -1);
    } else {
        effect_134 = -1;
        sound_140 = -1;
    }
    value_138 = 0;
    value_13c = 0;
    for (int i = 0; i < 2; i++) {
        first_144[i] = -1;
        second_14c[i] = -1;
    }
    value_158 = -1;
    value_154 = -1;
}
