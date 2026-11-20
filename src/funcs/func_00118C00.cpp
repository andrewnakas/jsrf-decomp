/* sym: ??0Object_00118CB0@@QAE@PAUNode@@HI@Z = 0x00118C00 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00118CB0@@UAE@XZ = 0x00118CB0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00118CB0@@UAEXXZ = 0x00118610 */
/* sym: ?func_00011C90_2@Object_00118CB0@@UAEXXZ = 0x00118630 */
/* sym: ?func_00011C90_4@Object_00118CB0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00118CB0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_00118CB0@@UAEXXZ = 0x000AECC0 */
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

struct Buffer_00118CB0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Interface_002589F4 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6(unsigned int index);
    virtual long __stdcall slot7();
    virtual long __stdcall slot8(void *block);
};

struct Entry_00118CB0 {
    unsigned int index;
};

extern Interface_002589F4 *data_002589F4;

long __stdcall func_00168130(Interface_002589F4 *sound, const char *path, void **image);
extern "C" void *memset(void *destination, int value, unsigned int size);

// The class whose table is at 0x1D7B20: overrides slots 1, 4 of Node; slots 7, 10, 13 hold folded thunks.
struct Object_00118CB0 : Node {
    Object_00118CB0(Node *owner, int id, unsigned int flags);
    virtual ~Object_00118CB0();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    int value_44;
    void *image_48;
    int value_4c;
    Buffer_00118CB0 *buffers[400];
    char unknown_690[0x10];
    char block_6a0[0x10];
    int value_6b0;
    char unknown_6b4[0x3860];
    int value_3f14;
    unsigned int count;
    Entry_00118CB0 *entries[256];

    int func_001188C0(unsigned int index, int flag);
};

// Clears everything past the Node, hands block_6a0 to data_002589F4 (slot 8) and loads the sound effects image.
Object_00118CB0::Object_00118CB0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    memset(&value_44, 0, sizeof(*this) - 0x44);
    data_002589F4->slot8(block_6a0);
    image_48 = 0;
    value_4c = 1;
    func_00168130(data_002589F4, "D:\\Media\\Sounds\\dsstdfx.bin", &image_48);
    value_6b0 = 1;
    value_3f14 = -1;
}
