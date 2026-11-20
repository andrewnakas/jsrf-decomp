/* sym: ??1Object_0010D820@@UAE@XZ = 0x0010D9D0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0010D820@@UAEXXZ = 0x0010DA30 */
/* sym: ?func_00011C80@Object_0010D820@@UAEXH@Z = 0x0010DC60 */
/* sym: ?func_00011C90_2@Object_0010D820@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_0010D820@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_0010D820@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_0010D820@@UAEXXZ = 0x000AECC0 */
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

// The resource the interface at data_00251D74 creates for this node (its slot 9); slot 2 releases it.
struct Interface_0010D820 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

// A direct child of Node (constructor func_0010D820) that holds a resource at 0x50.
struct Object_0010D820 : Node {
    virtual ~Object_0010D820();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_040[0x010];
    Interface_0010D820 *resource;
};

// Releases the resource when there is one.
Object_0010D820::~Object_0010D820()
{
    if (resource) {
        resource->slot2();
        resource = 0;
    }
}
