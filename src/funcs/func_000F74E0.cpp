/* sym: ??1Object_000F7990@@UAE@XZ = 0x000F74E0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000F7990@@UAEXXZ = 0x000F7540 */
/* sym: ?func_00011C80@Object_000F7990@@UAEXH@Z = 0x000F7720 */
/* sym: ?func_00011C90_2@Object_000F7990@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000F7990@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_4@Object_000F7990@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_000F7990@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000F7990@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_000F7990@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_8@Object_000F7990@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_4@Object_000F7990@@UAEXH@Z = 0x000B3DE0 */
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
struct Interface_000F7990 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

// A direct child of Node (constructor func_000F7990) that holds a resource at 0x48.
struct Object_000F7990 : Node {
    virtual ~Object_000F7990();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    char unknown_040[0x008];
    Interface_000F7990 *resource;
};

// Releases the resource when there is one.
Object_000F7990::~Object_000F7990()
{
    if (resource) {
        resource->slot2();
        resource = 0;
    }
}
