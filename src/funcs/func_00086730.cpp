struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C340(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *a, const Vector3 *b);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// The part of the collision item func_0001B5C0 tests: two counts, at +0x4 and +0x14.
struct Shape_000EC910 {
    int unknown_00;
    unsigned int first;
    char unknown_08[0xc];
    unsigned int second;
    char unknown_18[0xc];
};

// The collision item of data_0022FCE8 (func_00016260): a mask, a box (func_00017D90) and a shape.
struct Item_00016260 {
    int mask;
    int value;
    Box_00017CC0 box;
    Shape_000EC910 shape;
};

// What func_0001B5C0 finds and func_000194B0 picks from: a contact with a point and a normal at +0x3c and +0x48,
// or +0x60 and +0x6c.
struct Contact_000C4A90 {
    char unknown_00[0x3c];
    Vector3 point;
    Vector3 normal;
    char unknown_54[0xc];
    Vector3 otherPoint;
    Vector3 otherNormal;
};

struct Sphere_000EC910;

// What func_0001B5C0 hands func_000194B0: two lists of contacts with their counts.
struct Hits_000C4C60 {
    Contact_000C4A90 *contacts;
    unsigned int count;
    Contact_000C4A90 *others;
    unsigned int otherCount;
};

struct Object_00016200 {
    int func_0001B5C0(Shape_000EC910 *shape, Sphere_000EC910 *sphere, int radius, int *hit, int mask, int limit);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

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
    char unknown_34[0x10];
};

// The family of tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210 (constructor 0x862B0, destructor 0x86460).
struct Object_00086960 : Node {
    Vector3 start;
    Vector3 position;
    char unknown_05c[0xc];
    Vector3 velocity;
    char unknown_074[8];
    Vector3 normal;
    char unknown_088[0x10];
    int state;
    char unknown_09c[8];
    unsigned int frames;
    char unknown_0a8[0x14];
    Vector3 point;
    float radius;
    Item_00016260 item;

    void func_00086730();
};

// Counts the frames at +0xa4; when the shape of the collision item has something to test, tests a sphere of the
// radius at +0xc8 around the point at +0xbc (func_0001B5C0) and on a hit moves the position onto the nearest contact
// (func_000194B0, func_0014C340), keeps its normal at +0x7c and, after 120 frames, sets the state to 1. Then keeps
// the step from the start to the position at +0x68 (zero when it has no length) and makes the position the new
// start.
void Object_00086960::func_00086730()
{
    frames++;
    if (item.shape.first > 0 || item.shape.second > 0) {
        Hits_000C4C60 hits;
        if (data_0022FCE8.func_0001B5C0(&item.shape, (Sphere_000EC910 *)&point, *(int *)&radius, (int *)&hits,
                                        0xffff, -1)) {
            Contact_000C4A90 *nearest;
            Contact_000C4A90 *contact;
            if (!data_0022FCE8.func_000194B0(&hits, &nearest)) {
                contact = nearest;
                func_0014C340(&position, &contact->point);
                normal = contact->normal;
            } else {
                contact = nearest;
                func_0014C340(&position, &contact->otherPoint);
                normal = contact->otherNormal;
            }
            if (frames > 0x78) {
                state = 1;
            }
        }
    }
    func_0014C4C0(&velocity, &position, &start);
    if (func_0014C460(&velocity, &velocity) <= 0.0f) {
        velocity.x = 0.0f;
        velocity.y = 0.0f;
        velocity.z = 0.0f;
    }
    start = position;
}
