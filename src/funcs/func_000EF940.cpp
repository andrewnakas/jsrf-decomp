/* sym: ??1Object_000EDC30@@UAE@XZ = 0x000EF940 */
/* sym: ??1Object_000CD1E0@@UAE@XZ = 0x000E7EB0 */
/* sym: ?func_00011C90@Object_000CD1E0@@UAEXXZ = 0x000CD200 */
/* sym: ?func_00011C80@Object_000EDC30@@UAEXH@Z = 0x000EDF40 */
/* sym: ?func_00011C80_1@Object_000EDC30@@UAEXH@Z = 0x000EE220 */
/* sym: ?func_000CD210@Object_000EDC30@@UAEXXZ = 0x000EE4C0 */
/* sym: ?func_000CD800@Object_000EDC30@@UAEXXZ = 0x000EE5A0 */
/* sym: ?func_000CD850@Object_000EDC30@@UAEXXZ = 0x000EE600 */
/* sym: ?func_000D77D0@Object_000EDC30@@UAEXXZ = 0x000EFB20 */
/* sym: ?func_000D7880@Object_000EDC30@@UAEXXZ = 0x000EFFF0 */

struct Vector3;
struct Mesh_00017F60;

struct Item_00017940;

struct Object_00016200 {
    void func_000178D0(Item_00017940 *item);
    void func_00019760(void *pointer);
    void func_0001B400(int key);
};

struct Object_0003E750 {
    void func_0003F280(int index);
};

struct Object_0006DB80 {
    void func_0006DF30(int key);
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

void func_0005DAA0(void *pointer);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0xe8.
struct Object_000607B0 {
    void func_00060810(int key);
};

struct Object_000C5B50 {
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);
};

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

// The class whose table is at 0x1CEFAC.
struct Object_000EDC30 : Object_000CD1E0 {
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
    void *handle_0fc;
    int value_100;
    char unknown_104[0x14];
    Mesh_00017F60 *mesh_118;
    const Mesh_00017F60 *template_11c;
    Item_00017940 *handle_120;
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
    char unknown_37c[0x20];
    int key_39c;
    int key_3a0;
    int keys[4];
    int value_3b4;
    int value_3b8;
    int value_3bc;
    int value_3c0;
    int value_3c4;
};

// Hands the owner back the message handles at 0x3b4-0x3bc and those at 0x3c0 and 0x3c4 it still holds, releases the
// keys of object 0xe8 (0x39c, 0x3a0 and the four at 0x3a4 that are set), stops the sound at 0x378 and the effects at
// 0x354-0x35c, releases the handles at 0x350 and 0x120, frees the four sprite meshes and the mesh at 0x118 when set and
// the motion handle at 0xfc.
Object_000EDC30::~Object_000EDC30()
{
    owner->func_000C5B50(&value_3b4);
    owner->func_000C5B50(&value_3b8);
    owner->func_000C5B50(&value_3bc);
    if (owner->func_000C5B70(value_3c0)) {
        owner->func_000C5B50(&value_3c0);
    }
    if (owner->func_000C5B70(value_3c4)) {
        owner->func_000C5B50(&value_3c4);
    }
    Object_000607B0 *lamps = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (lamps) {
        lamps->func_00060810(key_39c);
        lamps->func_00060810(key_3a0);
        for (int i = 0; i < 4; i++) {
            if (keys[i]) {
                lamps->func_00060810(keys[i]);
            }
        }
    }
    if (sound_378 != -1) {
        data_00251F78.func_0006DF30(sound_378);
    }
    if (effect_354 != -1) {
        data_002314B0.func_0003F280(effect_354);
    }
    if (effect_358 != -1) {
        data_002314B0.func_0003F280(effect_358);
    }
    if (effect_35c != -1) {
        data_002314B0.func_0003F280(effect_35c);
    }
    if (handle_350 != -1) {
        data_0022FCE8.func_0001B400(handle_350);
    }
    if (handle_120) {
        data_0022FCE8.func_000178D0(handle_120);
    }
    for (int j = 0; j < 4; j++) {
        if (sprites[j].mesh) {
            data_0022FCE8.func_00019760(sprites[j].mesh);
        }
    }
    if (mesh_118) {
        data_0022FCE8.func_00019760(mesh_118);
    }
    func_0005DAA0(handle_0fc);
}
