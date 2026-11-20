/* sym: ??1Object_00044AE0@@UAE@XZ = 0x00044AE0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void __cdecl operator delete(void *memory);

// A Direct3D resource: slot 2 releases it.
struct Resource_00044AE0 {
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

// The node class whose table is at 0x1CA788.
struct Object_00044AE0 : Node {
    virtual ~Object_00044AE0();

    char unknown_044[0x38];
    Resource_00044AE0 *texture;
    char unknown_080[0x5c];
    void *first;
    char unknown_0e0[0x58];
    void *second;
    char unknown_13c[0x7fc];
    Resource_00044AE0 *buffer;
    void *third;
};

// Frees the blocks at +0xdc, +0x138 and +0x93c that are set, then releases the resource at +0x938 and the texture at
// +0x7c until their counts reach 0 (clearing +0x7c).
Object_00044AE0::~Object_00044AE0()
{
    if (first) {
        operator delete(first);
    }
    if (second) {
        operator delete(second);
    }
    if (third) {
        operator delete(third);
    }
    if (buffer) {
        while (buffer->Release()) {
        }
    }
    if (texture) {
        while (texture->Release()) {
        }
        texture = 0;
    }
}
