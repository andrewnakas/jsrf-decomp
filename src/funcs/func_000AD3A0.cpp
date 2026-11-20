struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    Node *func_00011BD0();
};

// The path the object follows (its parent).
struct Object_000B45A0 {
    void func_000B46D0(int index, float time, Vector3 *out);
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD6E8).
struct Object_000ACFB0 : Node {
    char unknown_040[0x178];
    int reverse;
    float time;
    char unknown_1c0[4];
    float step;

    int func_000AD3A0();
};

// Which side of its path the object turns to: samples the parent path's two tracks at the time and one step on (track
// 1 first, or 0 when 0x1b8 is set) and returns 0 when the three points are in line, else 1 or 2 by the sign of the
// turn on the ground plane.
int Object_000ACFB0::func_000AD3A0()
{
    Object_000B45A0 *path = (Object_000B45A0 *)func_00011BD0();
    Vector3 points[3];
    if (!reverse) {
        path->func_000B46D0(1, time + step, &points[0]);
        path->func_000B46D0(0, time + step, &points[1]);
        path->func_000B46D0(0, time, &points[2]);
    } else {
        path->func_000B46D0(0, time + step, &points[0]);
        path->func_000B46D0(1, time + step, &points[1]);
        path->func_000B46D0(1, time, &points[2]);
    }
    Vector3 u;
    Vector3 v;
    u.x = points[1].x - points[2].x;
    u.y = points[1].y - points[2].y;
    u.z = points[1].z - points[2].z;
    v.x = points[0].x - points[2].x;
    v.y = points[0].y - points[2].y;
    v.z = points[0].z - points[2].z;
    float turn = u.z * v.x - u.x * v.z;
    if (turn == 0.0f) {
        return 0;
    }
    if (turn > 0.0f) {
        return 1;
    }
    return 2;
}
