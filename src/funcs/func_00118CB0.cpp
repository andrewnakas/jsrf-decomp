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
};

struct Entry_00118CB0 {
    unsigned int index;
};

extern Interface_002589F4 *data_002589F4;

// The class whose table is at 0x1D7B20: overrides slots 1, 4 of Node; slots 7, 10, 13 hold folded thunks.
struct Object_00118CB0 : Node {
    virtual ~Object_00118CB0();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_044[0xc];
    Buffer_00118CB0 *buffers[400];
    char unknown_690[0x3884];
    int value_3f14;
    unsigned int count;
    Entry_00118CB0 *entries[256];

    int func_001188C0(unsigned int index, int flag);
};

// Releases the 400 buffers (slot 2) and has data_002589F4 free each index (slot 6), then runs func_001188C0
// for each entry still held.
Object_00118CB0::~Object_00118CB0()
{
    for (unsigned int i = 0; i < 400; i++) {
        if (buffers[i]) {
            buffers[i]->slot2();
            buffers[i] = 0;
            data_002589F4->slot6(i);
        }
    }
    for (unsigned int j = 0; j < count; j++) {
        if (entries[j]) {
            func_001188C0(entries[j]->index, 1);
        }
    }
}
