/* sym: ??1Object_000967E0@@UAE@XZ = 0x00096920 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90_1@Object_000967E0@@UAEXXZ = 0x00096980 */
/* sym: ?func_00011C80@Object_000967E0@@UAEXH@Z = 0x00096F80 */
/* sym: ?func_00011C90_3@Object_000967E0@@UAEXXZ = 0x00096F60 */
/* sym: ?func_00011C80_1@Object_000967E0@@UAEXH@Z = 0x000967B0 */
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

// A resource the device at data_00251D6C creates; slot 2 releases it and returns the references left.
struct Resource_00096920 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// One of two direct children of Node with the same slots 2, 3, 5 and 6 (tables 0x1CD360 and 0x1CD3E0); this one
// has the table at 0x1CD360 (constructor func_000967E0).
struct Object_000967E0 : Node {
    virtual ~Object_000967E0();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);

    char unknown_040[0xf10];
    Resource_00096920 *resource;
};

// Releases the resource at 0xf50 until no reference is left.
Object_000967E0::~Object_000967E0()
{
    while (resource->slot2()) {
    }
}
