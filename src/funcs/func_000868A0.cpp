struct Vector3 {
    float x;
    float y;
    float z;
};

// The motion values (0x20DA90 for the kind at 0x1CD210): two factors and the fall per frame.
struct Motion_00086D30 {
    float scale;
    float lift;
    float step;
};

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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
    Vector3 start;
    Vector3 position;
    Vector3 direction;
    char unknown_068[0xc];
    float scale;
    float lift;
    char unknown_07c[0x2c];
    unsigned int frames;
    Motion_00086D30 *motion;

    void func_000868A0();
};

// Moves the position along the direction by the scale at +0x74 and up by the lift at +0x78, takes the motion's fall
// off the lift and, after 1200 frames, takes the object and everything below it out (func_00011BE0, func_00011C20).
void Object_00086960::func_000868A0()
{
    position.x += direction.x * scale;
    position.z += direction.z * scale;
    position.y += lift;
    lift -= motion->step;
    frames++;
    if (frames > 1200) {
        func_00011BE0(this);
        func_00011C20(child);
    }
}
