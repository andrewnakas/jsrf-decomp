/* sym: ??1Object_00101180@@UAE@XZ = 0x00101100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00101180@@UAEXXZ = 0x00101180 */
/* sym: ?func_00011C90_1@Object_00101180@@UAEXXZ = 0x00101190 */
/* sym: ?func_00011C80@Object_00101180@@UAEXH@Z = 0x001011A0 */
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
void __stdcall func_0006EBE0(void *handle);

// An interface the node holds at 0x88; slot 2 releases it.
struct Interface_00100F40 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

// The child of Node whose table is at 0x1D1D48 (constructor func_00100F40).
struct Object_00101180 : Node {
    virtual ~Object_00101180();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    char unknown_040[0x48];
    Interface_00100F40 *resource;
    void *handle;
    char unknown_090[0xfc];
    void *buffer;
};

// Frees the buffer at 0x18c, passes the handle at 0x8c to func_0006EBE0 and releases the interface at 0x88, each
// when there is one.
Object_00101180::~Object_00101180()
{
    if (buffer) {
        operator delete(buffer);
    }
    if (handle) {
        func_0006EBE0(handle);
    }
    if (resource) {
        resource->slot2();
    }
}
