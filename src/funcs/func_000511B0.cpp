/* sym: ??1Object_000511B0@@UAE@XZ = 0x000511B0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
// The class whose table at 0x1CD088 holds only its scalar deleting destructor 0x84160 (constructor 0x84010).
struct Object_00084160 {
    virtual ~Object_00084160();
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

// The class whose table is at 0x1CADE8 (constructor 0x561C0; 0x58 bytes).
struct Object_000511B0 : Node {
    virtual ~Object_000511B0();

    char unknown_44[4];
    Object_00084160 *part;
    char unknown_4c[0xc];
};

// Deletes the part at +0x48 (made by the constructor) when there is one.
Object_000511B0::~Object_000511B0()
{
    delete part;
}
