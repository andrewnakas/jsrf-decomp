/* sym: ??1Object_000E45D0@@UAE@XZ = 0x000E3830 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000E45D0@@UAEXXZ = 0x000E4910 */
/* sym: ?func_00011C90_1@Object_000E45D0@@UAEXXZ = 0x000E4F10 */
/* sym: ?func_00011C80@Object_000E45D0@@UAEXH@Z = 0x000E3930 */
/* sym: ?func_00011C80_3@Object_000E45D0@@UAEXH@Z = 0x000E3BB0 */
/* sym: ?func_00011C80_4@Object_000E45D0@@UAEXH@Z = 0x000B3DE0 */
struct Item_00017940;

struct Object_00016200 {
    void func_000178D0(Item_00017940 *item);
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

// The owner at 0xb0.
struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

void func_0005DAA0(void *pointer);

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CED20 (Node) and 0x1CED18 (Object_000C60C0 at +0x44); slot 15 holds a folded
// thunk.
struct Object_000E45D0 : Node, Object_000C60C0 {
    virtual ~Object_000E45D0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_048[0x50];
    int sound_098;
    char unknown_09c[0x14];
    Object_000C5B50 *owner;
    char unknown_0b4[0xb8];
    void *handle_16c;
    void *handle_170;
    char unknown_174[8];
    Item_00017940 *handle_17c;
    char unknown_180[0x74];
    void *mesh_1f4;
    char unknown_1f8[0x18];
    int handle_210;
    int handle_214;
    int effect_218;
    char unknown_21c[8];
    int value_224;
};

// Has the owner at 0xb0 release the handle at 0x224 (func_000C5B50), then releases the sound at 0x98
// (data_00251F78), the effect at 0x218 (data_002314B0), the mesh at 0x1f4, the keys at 0x214 and 0x210 and the
// handle at 0x17c (data_0022FCE8), and the two blocks at 0x170 and 0x16c (func_0005DAA0).
Object_000E45D0::~Object_000E45D0()
{
    owner->func_000C5B50(&value_224);
    if (sound_098 != -1) {
        data_00251F78.func_0006DF30(sound_098);
    }
    if (effect_218 != -1) {
        data_002314B0.func_0003F280(effect_218);
    }
    if (mesh_1f4) {
        data_0022FCE8.func_00019760(mesh_1f4);
    }
    if (handle_214 != -1) {
        data_0022FCE8.func_0001B400(handle_214);
    }
    if (handle_210 != -1) {
        data_0022FCE8.func_0001B400(handle_210);
    }
    if (handle_17c) {
        data_0022FCE8.func_000178D0(handle_17c);
    }
    func_0005DAA0(handle_170);
    func_0005DAA0(handle_16c);
}
