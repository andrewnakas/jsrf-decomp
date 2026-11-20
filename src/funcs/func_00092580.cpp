struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *position, Vector3 *direction);
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
};

// The player.
struct Object_000A1C50 : Node {
    char unknown_040[0xdc];
    int value_11c;
    char unknown_120[0x2b0];
    Vector3 point_3d0;
    Vector3 first_3dc;
    Vector3 velocity;
    Vector3 second_3f4;
    int value_400;
    Vector3 first_404;
    Vector3 second_410;
    int value_41c;
    char unknown_420[0x838];
    int counter;
    char unknown_c5c[0x48];
    Vector3 position;
    Vector3 previous_cb0;
    char unknown_cbc[0x194];
    int value_e50;
    char unknown_e54[4];
    int value_e58;
    char unknown_e5c[0x280];
    Vector3 first_10dc;
    Vector3 second_10e8;

    void func_0007EB90(unsigned int color, float step);
    void func_0009BE50();
    void func_000A2490();
    int func_00092580();
};

// Called by func_00080340: state 0xb, counter 60, func_000A2490, object 0xe8 handed the point at 0x3d0 (kind 0x18),
// value 0x9d at 0x11c and a black fade over 1/60; moves to the point's x and z, value 0xb at 0xe50, the velocity as a
// share of the last move (0.5, 0.3, 0.5); after func_0009BE50 keeps the two points at 0x3dc and 0x3f4.
int Object_000A1C50::func_00092580()
{
    value_e58 = 0xb;
    counter = 0x3c;
    func_000A2490();
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_000651E0(0x18, &point_3d0, 0);
    }
    value_11c = 0x9d;
    func_0007EB90(0xff000000, 1.0f / 60.0f);
    position.x = point_3d0.x;
    position.z = point_3d0.z;
    value_e50 = 0xb;
    velocity.x = (position.x - previous_cb0.x) * 0.5f;
    velocity.y = (position.y - previous_cb0.y) * 0.3f;
    velocity.z = (position.z - previous_cb0.z) * 0.5f;
    func_0009BE50();
    first_10dc = first_3dc;
    second_10e8.x = second_3f4.x;
    second_10e8.y = second_3f4.y;
    second_10e8.z = second_3f4.z;
    return 1;
}
