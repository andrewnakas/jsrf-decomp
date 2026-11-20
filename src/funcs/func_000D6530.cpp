/* sym: ??1Object_000D6350@@UAE@XZ = 0x000D6530 */
/* sym: ??1Object_000CD1E0@@UAE@XZ = 0x000E7EB0 */
/* sym: ?func_00011C90@Object_000CD1E0@@UAEXXZ = 0x000CD200 */
/* sym: ?func_00011C80@Object_000D6350@@UAEXH@Z = 0x000D6640 */
/* sym: ?func_00011C80_1@Object_000D6350@@UAEXH@Z = 0x000D6830 */
/* sym: ?func_000CD210@Object_000D6350@@UAEXXZ = 0x000D6980 */
/* sym: ?func_000CD800@Object_000D6350@@UAEXXZ = 0x000D6A00 */
/* sym: ?func_000CD850@Object_000D6350@@UAEXXZ = 0x000D7950 */
struct Vector3;

struct Mesh_00017F60;

struct Item_00017940;

struct Object_00016200 {
    void func_000178D0(Item_00017940 *item);
    void func_00019760(void *pointer);
};

void func_0005DAA0(void *pointer);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060810(int key);
};

// The object a behaviour serves (the owner type of the Object_000CC600 family).
struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

struct Object_0003E750 {
    void func_0003F280(int key);
};

struct Object_0006DB80 {
    void func_0006DF30(int key);
};

extern Object_00016200 data_0022FCE8;
extern Object_0003E750 data_002314B0;
extern Object_0006DB80 data_00251F78;
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

// The class whose table is at 0x1CE5F0.
struct Object_000D6350 : Object_000CD1E0 {
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
    void *handle_0f4;
    int value_0f8;
    char unknown_0fc[8];
    void *mesh_104;
    const Mesh_00017F60 *template_108;
    Item_00017940 *item_10c;
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
    int keys[4];
    int handle_2cc;
    int handles[4];
};

// Hands the four handles at 0x2d0 back to the owner, releasing through object 0xE8 the keys at 0x2bc that are set,
// then the handle at 0x2cc; stops the sound at 0x2b8 and the effect at 0x2ac, releases the item at 0x10c and the mesh
// at 0x104 and frees the block at 0xf4.
Object_000D6350::~Object_000D6350()
{
    for (int i = 0; i < 4; i++) {
        owner->func_000C5B50(&handles[i]);
        if (keys[i]) {
            Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
            if (node) {
                node->func_00060810(keys[i]);
            }
        }
    }
    owner->func_000C5B50(&handle_2cc);
    if (sound_2b8 != -1) {
        data_00251F78.func_0006DF30(sound_2b8);
    }
    if (effect_2ac != -1) {
        data_002314B0.func_0003F280(effect_2ac);
    }
    if (item_10c) {
        data_0022FCE8.func_000178D0(item_10c);
    }
    if (mesh_104) {
        data_0022FCE8.func_00019760(mesh_104);
    }
    func_0005DAA0(handle_0f4);
}
