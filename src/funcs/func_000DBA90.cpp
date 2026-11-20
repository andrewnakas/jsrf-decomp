/* sym: ??1Object_000DB8F0@@UAE@XZ = 0x000DBA90 */
/* sym: ??1Object_000CD1E0@@UAE@XZ = 0x000E7EB0 */
/* sym: ?func_00011C90@Object_000CD1E0@@UAEXXZ = 0x000CD200 */
/* sym: ?func_00011C80@Object_000DB8F0@@UAEXH@Z = 0x000DBBA0 */
/* sym: ?func_00011C80_1@Object_000DB8F0@@UAEXH@Z = 0x000DBD80 */
/* sym: ?func_000CD210@Object_000DB8F0@@UAEXXZ = 0x000DBF00 */
/* sym: ?func_000CD800@Object_000DB8F0@@UAEXXZ = 0x00011C90 */
/* sym: ?func_000CD850@Object_000DB8F0@@UAEXXZ = 0x000DBF40 */
/* sym: ?func_000D77D0@Object_000DB8F0@@UAEXXZ = 0x000DC490 */
/* sym: ?func_000D7880@Object_000DB8F0@@UAEXXZ = 0x000DC750 */
/* sym: ?func_000CD390@Object_000DB8F0@@UAEHPAUVector3@@M0@Z = 0x000DC290 */
struct Vector3;

struct Mesh_00017F60;
struct Item_00017940;

struct Object_00016200 {
    void func_000178D0(Item_00017940 *item);
    void func_00019760(void *pointer);
};

struct Object_0003E750 {
    void func_0003F280(int effect);
};

struct Object_0006DB80 {
    void func_0006DF30(int sound);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060810(int key);
};

// The object a behaviour serves.
struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

extern Object_00016200 data_0022FCE8;
extern Object_0003E750 data_002314B0;
extern Object_0006DB80 data_00251F78;

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

    Object_000C5B50 *owner;
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
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000DB8F0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    char unknown_06c[8];
    char *table_074;
    char unknown_078[0x20];
    int value_098;
    Vector4_000DB8F0 origin;
    char unknown_0ac[8];
    Holder_000DB8F0 *holder;
    void *mesh_0b8;
    const Mesh_00017F60 *template_0bc;
    Item_00017940 *item_0c0;
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

// Hands the owner back the handles at 0x158 and 0x154, stops the sounds at 0x144 and 0x14c that are set, then the
// effects at 0x140 and 0x134 when set, frees the item at 0xc0 and the mesh at 0xb8.
Object_000DB8F0::~Object_000DB8F0()
{
    owner->func_000C5B50(&value_158);
    owner->func_000C5B50(&value_154);
    Object_000607B0 *player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (player) {
        for (int i = 0; i < 2; i++) {
            if (first_144[i] >= 0) {
                player->func_00060810(first_144[i]);
            }
            if (second_14c[i] >= 0) {
                player->func_00060810(second_14c[i]);
            }
        }
    }
    if (sound_140 != -1) {
        data_00251F78.func_0006DF30(sound_140);
    }
    if (effect_134 != -1) {
        data_002314B0.func_0003F280(effect_134);
    }
    if (item_0c0) {
        data_0022FCE8.func_000178D0(item_0c0);
    }
    if (mesh_0b8) {
        data_0022FCE8.func_00019760(mesh_0b8);
    }
}
