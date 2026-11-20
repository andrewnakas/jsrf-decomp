/* cflags: /Oy- */
/* sym: ??0Object_000EDC30@@QAE@PAUDesc_000EDC30@@@Z = 0x000EDC30 */
/* sym: ??0Object_000CD1E0@@QAE@XZ = 0x000CD7D0 */
/* sym: ??1Object_000CD1E0@@UAE@XZ = 0x000E7EB0 */
/* sym: ?func_00011C90@Object_000CD1E0@@UAEXXZ = 0x000CD200 */
/* sym: ?func_00011C80@Object_000EDC30@@UAEXH@Z = 0x000EDF40 */
/* sym: ?func_00011C80_1@Object_000EDC30@@UAEXH@Z = 0x000EE220 */
/* sym: ?func_000CD210@Object_000EDC30@@UAEXXZ = 0x000EE4C0 */
/* sym: ?func_000CD800@Object_000EDC30@@UAEXXZ = 0x000EE5A0 */
/* sym: ?func_000CD850@Object_000EDC30@@UAEXXZ = 0x000EE600 */
/* sym: ?func_000D77D0@Object_000EDC30@@UAEXXZ = 0x000EFB20 */
/* sym: ?func_000D7880@Object_000EDC30@@UAEXXZ = 0x000EFFF0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3;
struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
    int func_0001D810(void *list, int index);
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
extern Mesh_00017F60 data_0021A7E0;
extern Mesh_00017F60 data_0021A81C;
extern char data_0021A900[];
extern char data_0021A3B0[];
extern char data_0021A510[];
extern char data_0021A670[];
extern unsigned char data_00231D40[];

// 24 bytes; 0x231D40 holds a list of them.
struct Entry_000EDC30 {
    int values[6];
};

extern Entry_000EDC30 data_0021A950;

struct List_000EDC30 {
    void *entries;
    int count;
    int unknown_08;
};

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);

struct Vector_000CD7D0 {
    int x;
    int y;
    int z;
};

struct Vector4_000EDC30 {
    float x;
    float y;
    float z;
    float w;
};

struct Node_000EDC30 {
    char unknown_00[0x54];
    Vector4_000EDC30 position;
};

struct Model_000EDC30 {
    char unknown_00[0xc];
    Node_000EDC30 *node;
};

struct Holder_000EDC30 {
    Model_000EDC30 *model;
};

struct Source_000EDC30 {
    void *data;
};

struct Resource_000EDC30 {
    Holder_000EDC30 *holder;
    char unknown_04[0x14];
    Source_000EDC30 *source;
    char unknown_1c[4];
    Source_000EDC30 *sound;
};

struct Desc_000EDC30 {
    char unknown_00[8];
    int id;
    char unknown_0c[0x98];
    unsigned int flags;
};

// Seventeen words; the constructor sets only the first.
struct Block_000EDC30 {
    int kind;
    int unknown_04[16];
};

struct Sprite_000EDC30 {
    int mode;
    int flag;
    Mesh_00017F60 *mesh;
    int value;
    char unknown_10[0x14];
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
    virtual float func_000CD440();
    virtual float func_000CD4F0();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

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

// The class whose table is at 0x1CEFAC.
struct Object_000EDC30 : Object_000CD1E0 {
    Object_000EDC30(Desc_000EDC30 *desc);
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000EDC30();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();

    char unknown_06c[8];
    char *table_074;
    char unknown_078[0x48];
    Vector4_000EDC30 origin;
    char unknown_0d0[0xc];
    int value_0dc;
    char unknown_0e0[0x14];
    Holder_000EDC30 *holder;
    Source_000EDC30 *source;
    int handle_0fc;
    int value_100;
    char unknown_104[0x14];
    Mesh_00017F60 *mesh_118;
    const Mesh_00017F60 *template_11c;
    int handle_120;
    Block_000EDC30 blocks[4];
    Sprite_000EDC30 sprite;
    Sprite_000EDC30 sprites[4];
    char unknown_2e8[0x60];
    int handle_348;
    char unknown_34c[4];
    int handle_350;
    int effect_354;
    int effect_358;
    int effect_35c;
    int value_360;
    int value_364;
    int value_368;
    int value_36c;
    int value_370;
    int value_374;
    int sound_378;
    char unknown_37c[0x38];
    int value_3b4;
    int value_3b8;
    int value_3bc;
};

Object_000EDC30::Object_000EDC30(Desc_000EDC30 *desc)
{
    Resource_000EDC30 *resource = (Resource_000EDC30 *)func_00025700(5, 8, 0, 0);
    holder = resource->holder;
    source = resource->source;
    state = 0;
    value_0dc = 0;
    value_100 = 0;
    origin = holder->model->node->position;
    table_074 = data_0021A900;
    handle_0fc = func_0005E790(source->data, 1);
    mesh_118 = data_0022FCE8.func_00019680(&data_0021A7E0);
    template_11c = &data_0021A7E0;
    int i;
    for (i = 0; i < 4; i++) {
        sprites[i].mesh = data_0022FCE8.func_00019680(&data_0021A81C);
        sprites[i].mode = 0x10;
        sprites[i].flag = 1;
        sprites[i].value = 0;
    }
    for (i = 0; i < 4; i++) {
        memset(&blocks[i], 0, sizeof(blocks[i]));
        blocks[i].kind = 0x43f;
    }
    sprite.mode = 2;
    sprite.flag = 2;
    sprite.mesh = mesh_118;
    handle_120 = data_0022FCE8.func_0001D950(resource->sound->data, desc->id);
    handle_348 = handle_120;
    ((Entry_000EDC30 *)data_00231D40)[0] = data_0021A950;
    ((Entry_000EDC30 *)data_00231D40)[1] = data_0021A950;
    List_000EDC30 list;
    list.entries = data_00231D40;
    list.count = 2;
    list.unknown_08 = 0;
    handle_350 = data_0022FCE8.func_0001D810(&list, -1);
    if (desc->flags & 0x4000) {
        effect_354 = data_002314B0.func_0003EE90(data_0021A3B0, -1, -1, 1, 0.3f, 1, desc->id, -1);
        effect_358 = data_002314B0.func_0003EE90(data_0021A510, -1, -1, 1, 0.3f, 1, desc->id, -1);
        effect_35c = data_002314B0.func_0003EE90(data_0021A670, -1, -1, 1, 0.1f, 1, desc->id, -1);
        data_002314B0.func_0003F410(effect_354, 0);
        data_002314B0.func_0003F410(effect_358, 0);
        data_002314B0.func_0003F410(effect_35c, 0);
        sound_378 = data_00251F78.func_0006DAE0(1, 0, -1, -1);
        if (sound_378 != -1) {
            data_00251F78.func_0006DEB0(sound_378, 0);
        }
    } else {
        effect_354 = -1;
        effect_358 = -1;
        effect_35c = -1;
        sound_378 = -1;
    }
    value_368 = 0;
    value_364 = 0;
    value_360 = 0;
    value_374 = 0;
    value_370 = 0;
    value_36c = 0;
    unknown_68 = 0;
    value_3bc = -1;
    value_3b8 = -1;
    value_3b4 = -1;
}
