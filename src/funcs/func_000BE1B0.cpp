/* sym: ??1Object_000BE1B0@@UAE@XZ = 0x000BE1B0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000BE1B0@@UAEXXZ = 0x000BE280 */
/* sym: ?func_00011C90_1@Object_000BE1B0@@UAEXXZ = 0x000BE480 */
/* sym: ?func_00011C80@Object_000BE1B0@@UAEXH@Z = 0x000BE4E0 */
/* sym: ?func_00011C90_2@Object_000BE1B0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000BE1B0@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000BE1B0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_3@Object_000BE1B0@@UAEXH@Z = 0x000B3DE0 */
struct Item_00017940;

struct Object_00016200 {
    void func_000178D0(Item_00017940 *item);
};

extern Object_00016200 data_0022FCE8;

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

extern Object_0006E130 data_00252790;

// The interface at 0x170: slot 5 takes the value at 0x174, slot 2 releases it.
struct Interface_000BE1B0 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5(int value);
};

struct Node {
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// One of the entries at 0x198 (0x24 bytes): what it points at holds 0 while it is free.
struct Entry_000BE1B0 {
    int *state;
    char unknown_04[0x20];
};

// One of the six buffers at 0x264 (0x18 bytes).
struct Buffer_000BE1B0 {
    void *data;
    char unknown_04[0x14];
};

// The child of Node whose table is at 0x1CDB20 (func_000BEA80 builds it): overrides slots 1 to 6 and 12.
struct Object_000BE1B0 : Node {
    virtual ~Object_000BE1B0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);

    char unknown_040[0x130];
    Interface_000BE1B0 *player;
    int value_174;
    int hasItem;
    Item_00017940 *item;
    char unknown_180[0x18];
    Entry_000BE1B0 entries[5];
    char unknown_24c[0x18];
    Buffer_000BE1B0 buffers[6];
    int count;
    int busy;
    unsigned int mode;
    char unknown_300[0xc];
    int texture;
    int active;
};

// Releases the item at 0x17c (when 0x178 is set), frees the six buffers at 0x264, releases the texture at 0x30c
// (data_00252790) and, while active (0x310), hands the interface at 0x170 the value at 0x174 (slot 5) and
// releases it.
Object_000BE1B0::~Object_000BE1B0()
{
    if (hasItem) {
        data_0022FCE8.func_000178D0(item);
    }
    for (int i = 0; i < 6; i++) {
        if (buffers[i].data) {
            delete buffers[i].data;
        }
    }
    data_00252790.func_0006E7B0(texture);
    if (active) {
        player->slot5(value_174);
        player->slot2();
    }
}
