/* sym: ??1Object_00110830@@UAE@XZ = 0x00110830 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00110830@@UAEXXZ = 0x00110890 */
/* sym: ?func_00011C80@Object_00110830@@UAEXH@Z = 0x00110B40 */
/* sym: ?func_00011C90_2@Object_00110830@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_00110830@@UAEXH@Z = 0x000B3DE0 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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

struct Interface_00110830 {
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
    virtual long __stdcall slot9(int first, int second, Interface_00110830 **result);
};

struct Object_0006E130 {
    int func_0006E130(void *data);
};

struct Entry_00110830 {
    char unknown_00[0x10];
    int value_10;
    unsigned int color_14;
};

extern Interface_00251D74 *data_00251D74;
extern Object_0006E130 data_00252790;

void *func_00025700(unsigned int first, int second, int third, int fourth);

// The class whose table is at 0x1D26A8: overrides slots 1, 3 of Node; slots 4, 6 hold folded thunks.
struct Object_00110830 : Node {
    Object_00110830(Node *owner, int id, unsigned int flags, int first, int second, int mode, int *result);
    virtual ~Object_00110830();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);

    Interface_00110830 *interface_44;
    char unknown_48[0x70];
    Entry_00110830 entries[4];
    char unknown_118[0xc];
    int value_124;
    int value_128;
    int value_12c;
    char unknown_130[4];
    int *result_134;
    int value_138;
    int mode_13c;
    float value_140;
    int value_144;
};

// Releases interface_44 (slot 2).
Object_00110830::~Object_00110830()
{
    if (interface_44) {
        interface_44->slot2();
        interface_44 = 0;
    }
}
