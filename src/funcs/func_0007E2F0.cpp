/* sym: ??1Object_0007E2F0@@UAE@XZ = 0x0007E2F0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void func_0007E0E0();
void func_00025000();

// A Direct3D resource: slot 2 releases it.
struct Resource_0007E2F0 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall Release();
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

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

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    char unknown_44[0x50];
    int unknown_94;
};

// The node class whose table is at 0x1CCFB8 (constructor 0x7E6A0; 0xbc bytes).
struct Object_0007E2F0 : Object_00012170 {
    virtual ~Object_0007E2F0();

    char unknown_98[0x20];
    Resource_0007E2F0 *resource;
};

// Runs func_0007E0E0 and func_00025000, then releases the resource at +0xb8 when there is one.
Object_0007E2F0::~Object_0007E2F0()
{
    func_0007E0E0();
    func_00025000();
    if (resource) {
        resource->Release();
    }
}
