/* sym: ??0Object_000F7990@@QAE@PAUNode@@HIHMH@Z = 0x000F7990 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
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
struct Interface_000F7990 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5(void *data, int flags);
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
    virtual long __stdcall slot9(int first, int second, Interface_000F7990 **result);
};

extern Interface_00251D74 *data_00251D74;

// One of the four corners in each of the two quads at 0x4c and 0xac (0x18 bytes each).
struct Corner_000F7990 {
    char unknown_00[8];
    unsigned int color;
    unsigned int specular;
    char unknown_10[8];
};

// A direct child of Node (object 0x1164, table 0x1CF338, destructor func_000F74E0) that holds a resource at 0x48.
struct Object_000F7990 : Node {
    Object_000F7990(Node *owner, int id, unsigned int flags, int mode, float value, int argument);
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

    void func_000F77F0();

    char unknown_040[4];
    int argument;
    Interface_000F7990 *resource;
    Corner_000F7990 first[4];
    Corner_000F7990 second[4];
    int mode_10c;
    int mode_110;
    int unknown_114;
    int unknown_118;
    char unknown_11c[4];
    float scale;
    char unknown_124[4];
    float value;
    float unknown_12c;
};

// Keeps the mode, the value and the argument and asks data_00251D74 (slot 9, kind 2) for the resource: on failure
// the node unlinks itself; otherwise both quads get black (0xff000000) and white (0xffffff) corners, are laid out
// (func_000F77F0) and, when the resource's slot 3 succeeds, handed to its slot 5 before its slot 4.
Object_000F7990::Object_000F7990(Node *owner, int id, unsigned int flags, int mode, float value, int argument)
    : Node(owner, id, flags)
{
    this->argument = argument;
    mode_10c = mode;
    mode_110 = mode;
    scale = 1.0f;
    this->value = value;
    unknown_114 = 0;
    unknown_118 = 0;
    resource = 0;
    unknown_12c = 1.0f;
    if (data_00251D74->slot9(2, 0, &resource) < 0) {
        func_00011BE0(this);
        func_00011C20(child);
        resource = 0;
    } else {
        for (int i = 0; i < 4; i++) {
            first[i].color = 0xff000000;
            first[i].specular = 0xffffff;
            second[i].color = 0xff000000;
            second[i].specular = 0xffffff;
        }
        func_000F77F0();
        if (resource->slot3() >= 0) {
            resource->slot5(first, 0);
            resource->slot5(second, 0);
            resource->slot4();
        }
    }
}
