/* sym: ??1Object_000D27F0@@UAE@XZ = 0x000D2AA0 */
/* sym: ?func_000CD1E0@Object_000D27F0@@UAEXXZ = 0x000D2B90 */
/* sym: ?func_00011C90@Object_000D27F0@@UAEXXZ = 0x000D2C50 */
/* sym: ?func_00011C80@Object_000D27F0@@UAEXH@Z = 0x000D2D80 */
/* sym: ?func_00011C80_1@Object_000D27F0@@UAEXH@Z = 0x000D3040 */
struct Object_00016200 {
    void func_00019760(void *pointer);
    void func_0001B400(int key);
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

// The class whose table is at 0x1CE450 (constructor func_000D27F0).
struct Object_000D27F0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D27F0();

    void func_000D27A0();

    Object_000C5B50 *owner;
    char unknown_008[0xedc];
    int sounds[4];
    char unknown_ef4[0x1c];
    void *blocks[3];
    char unknown_f1c[0x70];
    void *mesh_f8c;
    char unknown_f90[0x20];
    void *mesh_fb0;
    char unknown_fb4[0x30];
    int key_fe4;
    int effect_fe8;
    char unknown_fec[8];
    int key_ff4;
    char unknown_ff8[4];
    int handle_ffc;
};

// Has the owner release the handle at 0xffc (func_000C5B50), runs func_000D27A0, releases the key at 0xff4
// (data_00251F78), the effect at 0xfe8 (data_002314B0), the key at 0xfe4 and the meshes at 0xfb0 and 0xf8c
// (data_0022FCE8), and the three blocks at 0xf10 (func_0005DAA0).
Object_000D27F0::~Object_000D27F0()
{
    owner->func_000C5B50(&handle_ffc);
    func_000D27A0();
    if (key_ff4 != -1) {
        data_00251F78.func_0006DF30(key_ff4);
    }
    if (effect_fe8 != -1) {
        data_002314B0.func_0003F280(effect_fe8);
    }
    if (key_fe4 != -1) {
        data_0022FCE8.func_0001B400(key_fe4);
    }
    if (mesh_fb0) {
        data_0022FCE8.func_00019760(mesh_fb0);
    }
    if (mesh_f8c) {
        data_0022FCE8.func_00019760(mesh_f8c);
    }
    func_0005DAA0(blocks[0]);
    func_0005DAA0(blocks[1]);
    func_0005DAA0(blocks[2]);
}
