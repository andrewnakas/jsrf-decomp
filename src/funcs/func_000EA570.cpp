/* sym: ??1Object_000EA3B0@@UAE@XZ = 0x000EA570 */
/* sym: ?func_000CD1E0@Object_000EA3B0@@UAEXXZ = 0x000EA6A0 */
/* sym: ?func_00011C90@Object_000EA3B0@@UAEXXZ = 0x000E96E0 */
/* sym: ?func_00011C80@Object_000EA3B0@@UAEXH@Z = 0x000E97F0 */
/* sym: ?func_00011C80_1@Object_000EA3B0@@UAEXH@Z = 0x000E9A40 */
struct Item_00017940;

struct Object_00016200 {
    void func_000178D0(Item_00017940 *item);
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

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

void func_0005DAA0(void *pointer);

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The part at 0x30 (built by func_000EB830).
struct Part_000EB830 {
    void func_000EB920();
    void func_000EBB50();

    char unknown_00[0x6c];
};

// A drawn block (36 bytes) of the four at 0x158.
struct Block_000EA3B0 {
    void *mesh;
    char unknown_04[0x18];
    Item_00017940 *item;
    char unknown_20[4];
};

// The object func_000EA3B0 builds (0x1f4 bytes; table 0x1CEE78).
struct Object_000EA3B0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000EA3B0();

    char unknown_004[0x2c];
    Part_000EB830 part;
    char unknown_09c[0x44];
    int sounds[4];
    char unknown_0f0[0x10];
    int sound_100;
    int sounds_104[3];
    char unknown_110[0x18];
    void *block_128;
    char unknown_12c[0x2c];
    Block_000EA3B0 blocks[4];
    char unknown_1e8[4];
    int key_1ec;
};

// Stops the four sounds at 0xe0, the one at 0x100 and the three at 0x104 (each group only when its first is set)
// through object 0xe8, releases the key at 0x1ec (data_00251F78), runs func_000EBB50 and func_000EB920 on the part
// at 0x30, frees the item at 0x1e0 (in the last block) and the meshes of the four blocks at 0x158 (data_0022FCE8),
// and the block at 0x128 (func_0005DAA0).
Object_000EA3B0::~Object_000EA3B0()
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        if (sounds[0]) {
            for (int i = 0; i < 4; i++) {
                object->func_00060810(sounds[i]);
            }
        }
        if (sound_100) {
            object->func_00060810(sound_100);
        }
        if (sounds_104[0]) {
            for (int i = 0; i < 3; i++) {
                object->func_00060810(sounds_104[i]);
            }
        }
    }
    if (key_1ec != -1) {
        data_00251F78.func_0006DF30(key_1ec);
    }
    part.func_000EBB50();
    part.func_000EB920();
    if (blocks[3].item) {
        data_0022FCE8.func_000178D0(blocks[3].item);
    }
    for (int j = 0; j < 4; j++) {
        if (blocks[j].mesh) {
            data_0022FCE8.func_00019760(blocks[j].mesh);
        }
    }
    func_0005DAA0(block_128);
}
