/* sym: ??1Object_000ECB50@@UAE@XZ = 0x000EBD60 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000ECB50@@UAEXXZ = 0x000ECDB0 */
/* sym: ?func_00011C90_1@Object_000ECB50@@UAEXXZ = 0x000ECE70 */
/* sym: ?func_00011C80@Object_000ECB50@@UAEXH@Z = 0x000EBE70 */
/* sym: ?func_00011C80_3@Object_000ECB50@@UAEXH@Z = 0x000EC0B0 */
/* sym: ?func_00011C80_4@Object_000ECB50@@UAEXH@Z = 0x000B3DE0 */
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

// The part at 0xbc (built by func_000EB830).
struct Part_000EB830 {
    void func_000EB920();
    void func_000EBB50();

    char unknown_00[0x6c];
};

// A drawn block (36 bytes) of the four at 0x1d0.
struct Block_000ECB50 {
    void *mesh;
    char unknown_04[0x18];
    Item_00017940 *item;
    char unknown_20[4];
};

// The class whose tables are at 0x1CEF20 (Node) and 0x1CEF18 (Object_000C60C0 at +0x44); slot 15 holds a folded
// thunk.
struct Object_000ECB50 : Node, Object_000C60C0 {
    virtual ~Object_000ECB50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_048[0x74];
    Part_000EB830 part;
    char unknown_128[0x28];
    void *block_150;
    char unknown_154[0x10];
    int sounds[4];
    char unknown_174[0x50];
    int sound_1c4;
    char unknown_1c8[8];
    Block_000ECB50 blocks[4];
    char unknown_260[0x114];
    int key_374;
};

// Stops the four sounds at 0x164 and the one at 0x1c4 through object 0xe8 (func_00060810), releases the key at 0x374
// (data_00251F78), runs func_000EBB50 and func_000EB920 on the part at 0xbc, frees the item at 0x258 (in the last
// block) and the meshes of the four blocks at 0x1d0 (data_0022FCE8), and the block at 0x150 (func_0005DAA0).
Object_000ECB50::~Object_000ECB50()
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        for (int i = 0; i < 4; i++) {
            object->func_00060810(sounds[i]);
        }
        object->func_00060810(sound_1c4);
    }
    if (key_374 != -1) {
        data_00251F78.func_0006DF30(key_374);
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
    func_0005DAA0(block_150);
}
