/* sym: ??0Object_0010FD30@@QAE@PAUNode@@HIHH@Z = 0x0010FD30 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_0010FD30@@UAE@XZ = 0x0010FEC0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0010FD30@@UAEXXZ = 0x001101E0 */
/* sym: ?func_00011C80@Object_0010FD30@@UAEXH@Z = 0x00110330 */
/* sym: ?func_00011C90_2@Object_0010FD30@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_0010FD30@@UAEXH@Z = 0x000B3DE0 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// The resource the interface at data_00251D74 creates for this node (its slot 9); slot 2 releases it.
struct Interface_0010FD30 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9(int first, int second, Interface_0010FD30 **result);
};

extern Interface_00251D74 *data_00251D74;

struct Object_0006E130 {
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;

struct Object_0003E750 {
    int func_0003E830(int key, int);
};

extern Object_0003E750 data_002314B0;

void *func_00025700(unsigned int first, int second, int third, int fourth);
int func_0003BEC0(int key);

// Objects 0xc to 0xf: the id of their player at 0x8d4.
struct Other_0004AFC0 {
    char unknown_000[0x8d4];
    int unknown_8d4;
};

// The player (only the field used here).
struct Object_000A1C50 {
    char unknown_000[0xfbc];
    int value_fbc;
};

// One of the channels at 0x9c (0x44 bytes each).
struct Channel_0010FD30 {
    int player;
    int number;
    int state;
    char unknown_0c[0x38];
};

// One of the four lines at 0x1ac (0x18 bytes each).
struct Line_0010FD30 {
    char unknown_00[8];
    int value;
    unsigned int color;
    char unknown_10[8];
};

// A direct child of Node (table 0x1D2580, destructor func_0010FEC0) that holds a resource at 0x44.
struct Object_0010FD30 : Node {
    Object_0010FD30(Node *owner, int id, unsigned int flags, int mode, int value);
    virtual ~Object_0010FD30();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);

    char unknown_040[0x004];
    Interface_0010FD30 *resource;
    char unknown_048[4];
    int value;
    int mode;
    int count;
    char unknown_058[0x44];
    Channel_0010FD30 channels[4];
    Line_0010FD30 lines[4];
    int value_20c;
    int unknown_210;
    int unknown_214;
};

// For each of the objects 0xc to 0xf whose player exists, a channel with the player's value at 0xfbc and a number
// from the key of its index (func_0003BEC0 in mode 0, func_0003E830 of data_002314B0 in mode 1); then asks
// data_00251D74 (slot 9, kind 0x10) for the resource: on failure the node unlinks itself, otherwise it takes an id
// from data_00252790 and resets the four lines.
Object_0010FD30::Object_0010FD30(Node *owner, int id, unsigned int flags, int mode, int value)
    : Node(owner, id, flags)
{
    this->mode = mode;
    this->value = value;
    int i;
    for (i = 0; i < 4; i++) {
        channels[i].player = -1;
        channels[i].state = 0;
        channels[i].number = 0;
    }
    unknown_210 = 0;
    unknown_214 = 0;
    count = 0;
    for (i = 0; i < 4; i++) {
        Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(i + 0xc);
        if (other) {
            Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(other->unknown_8d4);
            if (player) {
                channels[count].player = player->value_fbc;
                switch (this->mode) {
                case 0:
                    channels[count].number = func_0003BEC0(i);
                    break;
                case 1:
                    channels[count].number = data_002314B0.func_0003E830(i, 0);
                    break;
                }
                count++;
            }
        }
    }
    resource = 0;
    if (data_00251D74->slot9(0x10, 0, &resource) < 0) {
        func_00011BE0(this);
        func_00011C20(child);
        resource = 0;
    } else {
        value_20c = data_00252790.func_0006E130((int)func_00025700(0x11, 3, 0, 0));
        for (i = 0; i < 4; i++) {
            lines[i].value = -1;
            lines[i].color = 0xffffff;
        }
    }
}
