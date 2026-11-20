/* sym: ??0Object_00086900@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x00086900 */
/* sym: ??0Object_00086960@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000862B0 */
/* sym: ??1Object_00086960@@UAE@XZ = 0x00086460 */
struct Vector3 {
    float x;
    float y;
    float z;
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

// The family of tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210 (constructor 0x862B0, destructor 0x86460).
struct Object_00086960 : Node {
    Object_00086960(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);
    virtual ~Object_00086960();

    char unknown_044[0x58];
    int unknown_9c;
    char unknown_a0[0xac];
};

// The kind whose table is at 0x1CD170 (made by 0x86E30).
struct Object_00086900 : Object_00086960 {
    Object_00086900(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);
};

// Sets +0x9c to 10.
Object_00086900::Object_00086900(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction)
    : Object_00086960(owner, id, flags, position, direction)
{
    unknown_9c = 10;
}
