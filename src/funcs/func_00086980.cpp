/* sym: ??0Object_00086980@@QAE@PAUNode@@HIPAUVector3@@1H@Z = 0x00086980 */
/* sym: ??0Object_00086960@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000862B0 */
/* sym: ??1Object_00086960@@UAE@XZ = 0x00086460 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *a, const Vector3 *b);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A player (object 4 and on): its position at +0xca4.
struct Object_000A1C50 {
    char unknown_000[0xca4];
    Vector3 position;
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

    Vector3 start;
    Vector3 position;
    Vector3 direction;
    char unknown_068[0xc];
    float scale;
    float lift;
    char unknown_07c[0x20];
    int unknown_9c;
    int still;
    char unknown_a4[8];
    Motion_00086D30 *motion;
    char unknown_b0[0xa8];
};

// The kind whose table is at 0x1CD1C0 (made by 0x86E30): aimed at the object with the id at +0x158.
struct Object_00086980 : Object_00086960 {
    Object_00086980(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction, int target);

    int target;
    int unknown_15c;
    int unknown_160;
};

// Points +0xac at the motion values at 0x20DA90 (taking their first two), sets +0x15c and +0x160 to 1, +0x9c to 10
// and keeps the target id. With no direction of its own (+0xa0) it heads for the target's position seen from the
// start, flattened (0, 0, 1 when there is no target or no distance), and clears +0xa0.
Object_00086980::Object_00086980(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction,
                                 int target)
    : Object_00086960(owner, id, flags, position, direction)
{
    motion = &data_0020DA90;
    scale = data_0020DA90.scale;
    lift = data_0020DA90.lift;
    unknown_9c = 10;
    this->target = target;
    unknown_15c = 1;
    unknown_160 = 1;
    if (still) {
        Object_000A1C50 *object = (Object_000A1C50 *)data_0022FCE0->func_000128C0(target);
        if (object) {
            Vector3 way;
            func_0014C4C0(&way, &object->position, &start);
            way.y = 0.0f;
            if (func_0014C460(&way, &way) > 0.0f) {
                this->direction = way;
            } else {
                this->direction.x = 0.0f;
                this->direction.z = 1.0f;
            }
        } else {
            this->direction.x = 0.0f;
            this->direction.z = 1.0f;
        }
        still = 0;
    }
}
