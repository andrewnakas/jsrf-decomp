/* sym: ??1Object_0003ED40@@UAE@XZ = 0x0003ED40 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void __cdecl operator delete(void *memory);

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

// The node class whose table at 0x1CA510 repeats Node's slots 1 to 15.
struct Object_0003ED40 : Node {
    virtual ~Object_0003ED40();

    char unknown_44[0xc];
    void *buffer;
};

// Frees the buffer at +0x50 when there is one.
Object_0003ED40::~Object_0003ED40()
{
    if (buffer) {
        operator delete(buffer);
    }
}
