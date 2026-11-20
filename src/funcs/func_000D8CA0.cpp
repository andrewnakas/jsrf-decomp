/* sym: ??1Object_000D8A40@@UAE@XZ = 0x000D8CA0 */
/* sym: ?func_000CD1E0@Object_000D8A40@@UAEXXZ = 0x000D8D80 */
/* sym: ?func_00011C90@Object_000D8A40@@UAEXXZ = 0x000D8E90 */
/* sym: ?func_00011C80@Object_000D8A40@@UAEXH@Z = 0x000D7EC0 */
/* sym: ?func_00011C80_1@Object_000D8A40@@UAEXH@Z = 0x000D8130 */
struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    void func_0003F280(int index);
};

extern Object_0003E750 data_002314B0;

struct Object_0006DB80 {
    void func_0006DF30(int key);
};

extern Object_0006DB80 data_00251F78;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060810(int key);
};

// The owner at 0x4.
struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

void func_0005DAA0(void *pointer);

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE63C (constructor func_000D8A40).
struct Object_000D8A40 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D8A40();

    Object_000C5B50 *owner;
    char unknown_008[0x94];
    int sound_09c;
    char unknown_0a0[0x20];
    void *blocks[3];
    char unknown_0cc[0xc0];
    void *mesh_18c;
    char unknown_190[0x28];
    int effect_1b8;
    char unknown_1bc[8];
    int key_1c4;
    char unknown_1c8[4];
    int handle_1cc;
};

// Stops the sound at 0x9c through object 0xe8 (func_00060810), has the owner release the handle at 0x1cc
// (func_000C5B50), releases the key at 0x1c4 (data_00251F78), the effect at 0x1b8 (data_002314B0) and the mesh at
// 0x18c (data_0022FCE8), and the three blocks at 0xc0 (func_0005DAA0).
Object_000D8A40::~Object_000D8A40()
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_00060810(sound_09c);
    }
    owner->func_000C5B50(&handle_1cc);
    if (key_1c4 != -1) {
        data_00251F78.func_0006DF30(key_1c4);
    }
    if (effect_1b8 != -1) {
        data_002314B0.func_0003F280(effect_1b8);
    }
    if (mesh_18c) {
        data_0022FCE8.func_00019760(mesh_18c);
    }
    func_0005DAA0(blocks[0]);
    func_0005DAA0(blocks[1]);
    func_0005DAA0(blocks[2]);
}
