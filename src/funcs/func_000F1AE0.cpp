/* sym: ??1Object_000F1820@@UAE@XZ = 0x000F1AE0 */
/* sym: ?func_000CD1E0@Object_000F1820@@UAEXXZ = 0x000F1C30 */
/* sym: ?func_00011C90@Object_000F1820@@UAEXXZ = 0x000F0DE0 */
/* sym: ?func_00011C80@Object_000F1820@@UAEXH@Z = 0x000F0F70 */
/* sym: ?func_00011C80_1@Object_000F1820@@UAEXH@Z = 0x000F1170 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060810(int key);
};

struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

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

struct Object_0003E750 {
    void func_0003F280(int index);
};

extern Object_0003E750 data_002314B0;

void func_0005DAA0(void *pointer);

// The base of the owner's behaviours (table 0x1CE304): slot 0 is pure, slots 2 and 3 take an argument, slot 4 is
// the destructor.
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// One of the four entries at 0xd4 (0x24 bytes each).
struct Entry_000F1820 {
    char unknown_00[8];
    void *item;
    char unknown_0c[0x18];
};

// The state machine whose table is at 0x1CF02C (constructor func_000F1820), made by func_000F1FC0.
struct Object_000F1820 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000F1820();

    Object_000C5B50 *owner;
    char unknown_008[0x3c];
    int keys_44[4];
    int keys_54[4];
    int keys_64[4];
    char unknown_074[0x34];
    void *motion;
    void *secondMotion;
    char unknown_0b0[0x24];
    Entry_000F1820 entries[4];
    Item_00017940 *model;
    char unknown_168[4];
    int sounds[4];
    char unknown_17c[0x20];
    int key;
    int handles[3];
};

// Has the owner release the three handles at 0x1a0 (func_000C5B50), drops the twelve keys at 0x44 with object
// 0xe8 (func_00060810) when it exists, the key at 0x19c with data_00251F78 (func_0006DF30), the four ids at 0x16c
// with data_002314B0 (func_0003F280), the model at 0x164 and the four entries' items with data_0022FCE8, and frees
// both motions (func_0005DAA0).
Object_000F1820::~Object_000F1820()
{
    owner->func_000C5B50(&handles[0]);
    owner->func_000C5B50(&handles[1]);
    owner->func_000C5B50(&handles[2]);
    Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (target) {
        for (int i = 0; i < 4; i++) {
            target->func_00060810(keys_44[i]);
            target->func_00060810(keys_54[i]);
            target->func_00060810(keys_64[i]);
        }
    }
    if (key != -1) {
        data_00251F78.func_0006DF30(key);
    }
    int i;
    for (i = 0; i < 4; i++) {
        if (sounds[i] != -1) {
            data_002314B0.func_0003F280(sounds[i]);
        }
    }
    if (model) {
        data_0022FCE8.func_000178D0(model);
    }
    for (i = 0; i < 4; i++) {
        if (entries[i].item) {
            data_0022FCE8.func_00019760(entries[i].item);
        }
    }
    func_0005DAA0(secondMotion);
    func_0005DAA0(motion);
}
