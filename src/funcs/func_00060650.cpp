/* sym: ??1Object_00060650@@UAE@XZ = 0x00060650 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00060650@@UAEXXZ = 0x00060AC0 */
/* sym: ?func_00011C90_2@Object_00060650@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00060650@@UAEXXZ = 0x000AECC0 */
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

struct Interface_00251DAC {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

extern Interface_00251DAC *data_00251DAC;

// The class whose table is at 0x1CB000: overrides slots 1 (60AC0), 4 (AECC0), 10 (AECC0).
struct Object_00060650 : Node {
    virtual ~Object_00060650();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_6();

    Object_00060650(Node *owner, int id, unsigned int flags, int unused);

    int unknown_44;
    int unknown_48;
    int unknown_4c;
};

// Releases the shared interface at 0x251DAC until its count reaches zero.
Object_00060650::~Object_00060650()
{
    if (data_00251DAC) {
        while (data_00251DAC->slot2()) {
        }
        data_00251DAC = 0;
    }
}
