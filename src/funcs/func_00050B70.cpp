/* sym: ??1Object_00050B70@@UAE@XZ = 0x00050B70 */
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

// The class whose table is at 0x1CACA0 (constructor 0x50AB0; 0x58 bytes).
struct Object_00050B70 : Node {
    virtual ~Object_00050B70();

    char unknown_44[4];
    Object_00084160 *part;
    char unknown_4c[0xc];
};

// Deletes the part at +0x48 (made by the constructor) when there is one.
Object_00050B70::~Object_00050B70()
{
    delete part;
}
