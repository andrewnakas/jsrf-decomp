/* sym: ??1Object_0003C2B0@@UAE@XZ = 0x0003C2B0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
// A Direct3D resource: slot 2 releases it.
struct Resource_0003C2B0 {
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

// The node class whose table is at 0x1CA440: overrides slot 3 (3C310) and slots 4 to 15 with the shared 0xAECC0 / 0xB3DE0.
struct Object_0003C2B0 : Node {
    virtual ~Object_0003C2B0();

    Resource_0003C2B0 *resource;
};

// Releases the resource at +0x44 when there is one.
Object_0003C2B0::~Object_0003C2B0()
{
    if (resource) {
        resource->Release();
    }
}
