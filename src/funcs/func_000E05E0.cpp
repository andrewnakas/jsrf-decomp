/* sym: ??1Object_000E0440@@UAE@XZ = 0x000E05E0 */
/* sym: ??1Object_000CD1E0@@UAE@XZ = 0x000E7EB0 */
/* sym: ?func_00011C90@Object_000CD1E0@@UAEXXZ = 0x000CD200 */
/* sym: ?func_00011C80@Object_000E0440@@UAEXH@Z = 0x000E0710 */
/* sym: ?func_00011C80_1@Object_000E0440@@UAEXH@Z = 0x000E08A0 */
/* sym: ?func_000CD210@Object_000E0440@@UAEXXZ = 0x000E0A20 */
/* sym: ?func_000CD800@Object_000E0440@@UAEXXZ = 0x00011C90 */
/* sym: ?func_000CD850@Object_000E0440@@UAEXXZ = 0x000E1780 */
/* sym: ?func_000D77D0@Object_000E0440@@UAEXXZ = 0x000E1450 */
/* sym: ?func_000D7880@Object_000E0440@@UAEXXZ = 0x000E16F0 */
/* sym: ?func_000CD390@Object_000E0440@@UAEHPAUVector3@@M0@Z = 0x000E1000 */
struct Vector3;

struct Mesh_00017F60;

struct Object_00016200 {
    void func_00019760(void *pointer);
};

struct Object_0003E750 {
    void func_0003F280(int effect);
};

struct Object_0006DB80 {
    void func_0006DF30(int sound);
};

extern Object_00016200 data_0022FCE8;
extern Object_0003E750 data_002314B0;
extern Object_0006DB80 data_00251F78;

void func_0005DAA0(void *handle);

// The object a behaviour serves.
struct Object_000C5B50 {
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);
};

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

// The class whose table is at 0x1CE804; slot 6 is empty (folded with Node's).
struct Object_000E0440 : Object_000CD1E0 {
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000E0440();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    char unknown_06c[8];
    char *table_074;
    char unknown_078[0x28];
    int value_0a0;
    Vector4_000E0440 origin;
    char unknown_0b4[4];
    Holder_000E0440 *holder;
    Source_000E0440 *source;
    void *handle_0c0;
    char unknown_0c4[8];
    int value_0cc;
    int value_0d0;
    char unknown_0d4[0x10];
    void *mesh_0e4;
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

// Hands the owner back the message handles at 0x134, 0x130, 0x12c and 0x128 it still holds, stops the sound at 0x11c
// and the effect at 0x110 when set, frees the mesh at 0xe4 when set and the motion handle at 0xc0.
Object_000E0440::~Object_000E0440()
{
    if (owner->func_000C5B70(value_134)) {
        owner->func_000C5B50(&value_134);
    }
    if (owner->func_000C5B70(value_130)) {
        owner->func_000C5B50(&value_130);
    }
    if (owner->func_000C5B70(value_12c)) {
        owner->func_000C5B50(&value_12c);
    }
    if (owner->func_000C5B70(value_128)) {
        owner->func_000C5B50(&value_128);
    }
    if (sound_11c != -1) {
        data_00251F78.func_0006DF30(sound_11c);
    }
    if (effect_110 != -1) {
        data_002314B0.func_0003F280(effect_110);
    }
    if (mesh_0e4) {
        data_0022FCE8.func_00019760(mesh_0e4);
    }
    func_0005DAA0(handle_0c0);
}
