/* sym: ??0Object_000E0440@@QAE@PAUDesc_000E0440@@@Z = 0x000E0440 */
/* sym: ??1Object_000E0440@@UAE@XZ = 0x000E05E0 */
/* sym: ??0Object_000CD1E0@@QAE@XZ = 0x000CD7D0 */
/* sym: ??1Object_000CD1E0@@UAE@XZ = 0x000E7EB0 */
/* sym: ?func_00011C90@Object_000CD1E0@@UAEXXZ = 0x000CD200 */
/* sym: ?func_00011C80@Object_000E0440@@UAEXH@Z = 0x000E0710 */
/* sym: ?func_00011C80_1@Object_000E0440@@UAEXH@Z = 0x000E08A0 */
/* sym: ?func_000CD210@Object_000E0440@@UAEXXZ = 0x000E0A20 */
/* sym: ?func_000CD800@Object_000E0440@@UAEXXZ = 0x00011C90 */
/* sym: ?func_000CD850@Object_000E0440@@UAEXXZ = 0x000E1780 */
/* sym: ?func_000D77D0@Object_000E0440@@UAEXXZ = 0x000E1450 */
/* sym: ?func_000D7880@Object_000E0440@@UAEXXZ = 0x000E16F0 */
/* sym: ?func_000CD390@Object_000E0440@@UAEXXZ = 0x000E1000 */
struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
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
extern Mesh_00017F60 data_00217DCC;
extern char data_00217DFC[];
extern char data_00217C58[];

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);

struct Vector_000CD7D0 {
    int x;
    int y;
    int z;
};

struct Vector4_000E0440 {
    float x;
    float y;
    float z;
    float w;
};

struct Node_000E0440 {
    char unknown_00[0x54];
    Vector4_000E0440 position;
};

struct Model_000E0440 {
    char unknown_00[0xc];
    Node_000E0440 *node;
};

struct Body_000E0440 {
    char unknown_00[0x74];
    float range;
    char unknown_78[4];
    float scale;
};

struct Holder_000E0440 {
    int unknown_00;
    Model_000E0440 *model;
    Body_000E0440 *body;
};

struct Source_000E0440 {
    void *data;
};

struct Resource_000E0440 {
    Holder_000E0440 *holder;
    char unknown_04[0x14];
    Source_000E0440 *source;
    char unknown_1c[4];
    Source_000E0440 *sound;
};

struct Desc_000E0440 {
    char unknown_00[8];
    int id;
    char unknown_0c[0x98];
    unsigned int flags;
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

// The class whose table is at 0x1CE804; slot 6 is empty (folded with Node's).
struct Object_000E0440 : Object_000CD1E0 {
    Object_000E0440(Desc_000E0440 *desc);
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000E0440();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();
    virtual void func_000CD390();

    char unknown_06c[8];
    char *table_074;
    char unknown_078[0x28];
    int value_0a0;
    Vector4_000E0440 origin;
    char unknown_0b4[4];
    Holder_000E0440 *holder;
    Source_000E0440 *source;
    int handle_0c0;
    char unknown_0c4[8];
    int value_0cc;
    int value_0d0;
    char unknown_0d4[0x10];
    Mesh_00017F60 *mesh_0e4;
    const Mesh_00017F60 *template_0e8;
    int mode_0ec;
    int flag_0f0;
    char unknown_0f4[0x1c];
    int effect_110;
    int value_114;
    int value_118;
    int sound_11c;
    int value_120;
    int value_124;
    int value_128;
    int value_12c;
    int value_130;
    int value_134;
};

Object_000E0440::Object_000E0440(Desc_000E0440 *desc)
{
    Resource_000E0440 *resource = (Resource_000E0440 *)func_00025700(5, 6, 0, 0);
    holder = resource->holder;
    source = resource->source;
    Body_000E0440 *body = holder->body;
    body->range = 300.0f;
    body->scale = 3.0f;
    state = 0;
    value_0a0 = 0;
    value_0cc = 0;
    value_0d0 = 0;
    origin = holder->model->node->position;
    table_074 = data_00217DFC;
    handle_0c0 = func_0005E790(source->data, 1);
    mesh_0e4 = data_0022FCE8.func_00019680(&data_00217DCC);
    template_0e8 = &data_00217DCC;
    mode_0ec = 2;
    flag_0f0 = 1;
    if (desc->flags & 0x4000) {
        effect_110 = data_002314B0.func_0003EE90(data_00217C58, -1, -1, 1, 0.3f, 1, desc->id, -1);
        data_002314B0.func_0003F410(effect_110, 0);
        sound_11c = data_00251F78.func_0006DAE0(1, 0, -1, -1);
    } else {
        effect_110 = -1;
        sound_11c = -1;
    }
    value_114 = 0;
    value_118 = 0;
    value_124 = -1;
    value_120 = -1;
    value_134 = -1;
    value_130 = -1;
    value_12c = -1;
    value_128 = -1;
}
