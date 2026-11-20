/* sym: ??1Object_000C7910@@UAE@XZ = 0x000C7240 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000C7910@@UAEXXZ = 0x000C9280 */
/* sym: ?func_00011C90_1@Object_000C7910@@UAEXXZ = 0x000C7330 */
/* sym: ?func_00011C80@Object_000C7910@@UAEXH@Z = 0x000C74B0 */
/* sym: ?func_00011C80_3@Object_000C7910@@UAEXH@Z = 0x000C7720 */
/* sym: ?func_00011C80_4@Object_000C7910@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_000C60C0@Object_000C7910@@UAEXXZ = 0x000C9EB0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

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

void *func_00025700(unsigned int index, int first, int second, int third);
void func_0005DAA0(void *pointer);

// The player (object 0x2c): one word per slot at 0xfec, cleared when the slot's owner goes.
struct Player_000C7240 {
    char unknown_000[0xfec];
    void *slots[1];
};

struct Holder_000C8680 {
    void *model;
};

struct Resource_000C8680 {
    Holder_000C8680 *holder;
};

// Seventeen words; the constructor zeroes the first three and sets the kind of all six.
struct Block_000C8680 {
    int kind;
    int unknown_04[16];
};

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

// The class whose tables are at 0x1CE1C8 (Node, 77 slots) and 0x1CE1C0 (Object_000C60C0 at +0x44); constructor
// func_000C8680, destructor func_000C7240, deleting destructor 0xC87B0.
struct Object_000C7910 : Node, Object_000C60C0 {
    Object_000C7910(Node *owner, int id, unsigned int flags);
    virtual ~Object_000C7910();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
    virtual void func_000C60C0();
    virtual void func_000C7910();
    virtual void func_000D47F0();
    virtual void func_000C7A70();
    virtual void func_000C7AB0();
    virtual void func_000C7B30();
    virtual void func_000C87D0();
    virtual void func_000C7B90();
    virtual void func_000C7BB0();
    virtual void func_000C7C70();
    virtual void func_000C8870();
    virtual void func_000C88E0();
    virtual void func_000C7CD0();
    virtual void func_000C7CF0();
    virtual void func_000C7D40();
    virtual void func_000C8980();
    virtual void func_000C89F0();
    virtual void func_000C7DB0();
    virtual void func_000C7DD0();
    virtual void func_000C7E20();
    virtual void func_000C8A90();
    virtual void func_000C7DB0_1();
    virtual void func_000C8B30();
    virtual void func_000C7CD0_1();
    virtual void func_000C7E90();
    virtual void func_000C8140();
    virtual void func_000C81C0();
    virtual void func_000C8240();
    virtual void func_000C8BD0();
    virtual void func_000C8C10();
    virtual void func_000C8300();
    virtual void func_000C8F30();
    virtual void func_000CAD70();
    virtual void func_000CAED0();
    virtual void func_000CB130();
    virtual void func_000CB1A0();
    virtual void func_000CB200();
    virtual void func_000CB250();
    virtual void func_000CB2A0();
    virtual void func_000CB360();
    virtual void func_000CB3B0();
    virtual void func_000CB410();
    virtual void func_000CB470();
    virtual void func_000CB4D0();
    virtual void func_000CB530();
    virtual void func_000CB590();
    virtual void func_000CB5F0();
    virtual void func_000CB650();
    virtual void func_000CB6B0();
    virtual void func_000CB720();
    virtual void func_000CB790();
    virtual void func_000CB800();
    virtual void func_000CB870();
    virtual void func_000CB950();
    virtual void func_000CB9C0();
    virtual void func_000CBA30();
    virtual void func_000CBAA0();
    virtual void func_000CBB30();
    virtual void func_000CBB70();
    virtual void func_000CBBD0();
    virtual void func_000CBC20();
    virtual void func_000CBC80();

    char unknown_048[0x48];
    unsigned int flags;
    char unknown_094[4];
    int sound;
    char unknown_09c[0xa0];
    int slot_13c;
    char unknown_140[0x48];
    void *model_188;
    char unknown_18c[0x10];
    void *blocks_19c[3];
    char unknown_1a8[0x50];
    Block_000C8680 blocks[6];
    int value_390;
    int value_394;
    void *mesh_398;
    void *items;
    char unknown_3a0[0x18];
    int effect_3b8;
    int value_3bc;
    int value_3c0;
};

// Clears the player's slot at 0x13c, stops the sound at 0x98 (data_00251F78) and the effect at 0x3b8
// (data_002314B0), releases the mesh at 0x398 (data_0022FCE8) and the three blocks at 0x19c (func_0005DAA0).
Object_000C7910::~Object_000C7910()
{
    if (slot_13c >= 0) {
        Player_000C7240 *player = (Player_000C7240 *)data_0022FCE0->func_000128C0(0x2c);
        if (player) {
            player->slots[slot_13c] = 0;
        }
    }
    if (sound != -1) {
        data_00251F78.func_0006DF30(sound);
    }
    if (effect_3b8 != -1) {
        data_002314B0.func_0003F280(effect_3b8);
    }
    if (mesh_398) {
        data_0022FCE8.func_00019760(mesh_398);
    }
    func_0005DAA0(blocks_19c[0]);
    func_0005DAA0(blocks_19c[1]);
    func_0005DAA0(blocks_19c[2]);
}
