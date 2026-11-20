/* sym: ??0Object_00086D30@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x00086D30 */
/* sym: ??0Object_00086960@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000862B0 */
/* sym: ??1Object_00086960@@UAE@XZ = 0x00086460 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The motion values at 0x20DA90: two factors and a step.
struct Motion_00086D30 {
    float scale;
    float lift;
    float step;
};

extern Motion_00086D30 data_0020DA90;

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

    char unknown_044[0x30];
    float scale;
    float lift;
    char unknown_07c[0x20];
    int unknown_9c;
    char unknown_a0[0xc];
    Motion_00086D30 *motion;
    char unknown_b0[0x9c];
};

// The kind whose table is at 0x1CD210 (made by 0x86E30).
struct Object_00086D30 : Object_00086960 {
    Object_00086D30(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);
};

// Points +0xac at the motion values at 0x20DA90, takes their first two into +0x74 and +0x78 and sets +0x9c to 10.
Object_00086D30::Object_00086D30(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction)
    : Object_00086960(owner, id, flags, position, direction)
{
    motion = &data_0020DA90;
    scale = data_0020DA90.scale;
    lift = data_0020DA90.lift;
    unknown_9c = 10;
}
