/* sym: ??1Object_000CE9D0@@UAE@XZ = 0x000CEC70 */
/* sym: ?func_000CD1E0@Object_000CE9D0@@UAEXXZ = 0x000CED90 */
/* sym: ?func_00011C90@Object_000CE9D0@@UAEXXZ = 0x000CDAC0 */
/* sym: ?func_00011C80@Object_000CE9D0@@UAEXH@Z = 0x000CDCF0 */
/* sym: ?func_00011C80_1@Object_000CE9D0@@UAEXH@Z = 0x000CDE90 */
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

struct Object_000607B0 {
    void func_00060810(int key);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object a behaviour serves.
struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

struct Object_00015D50 {
    virtual ~Object_00015D50();
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The behaviour func_000CE9D0 builds (0x140 bytes, table 0x1CE3A0); 0x4 holds the object it serves.
struct Object_000CE9D0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CE9D0();

    Object_000C5B50 *owner;
    char unknown_08[0x58];
    Object_00015D50 *first;
    Object_00015D50 *second;
    char unknown_68[0x10];
    void *handle_78;
    void *handle_7c;
    char unknown_80[0x2c];
    void *mesh_ac;
    char unknown_b0[0x20];
    void *mesh_d0;
    char unknown_d4[0x20];
    void *mesh_f4;
    char unknown_f8[0x18];
    int effect;
    char unknown_114[8];
    int sound;
    char unknown_120[0x14];
    int key;
    int handle;
};

// Hands the owner back its handle at 0x138 (func_000C5B50), gives the key at 0x134 back to node 0xe8 when it is
// set, stops the sound at 0x11c and the effect at 0x110 when set, frees the meshes at 0xf4, 0xd0 and 0xac when set,
// the motion handles at 0x78 and 0x7c, and deletes the objects at 0x64 and 0x60.
Object_000CE9D0::~Object_000CE9D0()
{
    owner->func_000C5B50(&handle);
    if (key >= 0) {
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            node->func_00060810(key);
        }
    }
    if (sound != -1) {
        data_00251F78.func_0006DF30(sound);
    }
    if (effect != -1) {
        data_002314B0.func_0003F280(effect);
    }
    if (mesh_f4) {
        data_0022FCE8.func_00019760(mesh_f4);
    }
    if (mesh_d0) {
        data_0022FCE8.func_00019760(mesh_d0);
    }
    if (mesh_ac) {
        data_0022FCE8.func_00019760(mesh_ac);
    }
    func_0005DAA0(handle_78);
    func_0005DAA0(handle_7c);
    delete second;
    delete first;
}
