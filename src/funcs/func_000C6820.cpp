struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

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

struct Vector3 {
    float x;
    float y;
    float z;
};

// The part of the collision item func_0001B5C0 tests: two counts, at +0x4 and +0x14.
struct Shape_000EC910 {
    int unknown_00;
    unsigned int first;
    char unknown_08[0xc];
    unsigned int second;
    char unknown_18[0xc];
};

struct Sphere_000EC910;

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

void __fastcall func_0014C340(Vector3 *vector, const Vector3 *offset);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);

// The class whose table is at 0x1CE030 (constructor func_000C6690): overrides slots 1 (C6A90) and 2 (C6B50).
struct Object_000C6690 : Node {
    virtual void func_00011C90_1();

    int target_id;
    Vector3 last;
    Vector3 position;
    Vector3 velocity;
    int value_6c;
    unsigned int time;
    char unknown_74[4];
    unsigned int bounces;
    char unknown_7c[0x20];
    Shape_000EC910 shape;
    Vector3 center;
    int radius;

    void func_000C6820();
};

// Bounces: when the shape at 0x9c has anything to test and the sphere at 0xc0 hits it (func_0001B5C0 of
// data_0022FCE8), the velocity at 0x60 loses 30% and is reflected off the nearest contact's normal
// (func_000194B0, func_0014C800, func_0014C730), the position at 0x54 moves by the contact's point and the bounces at
// 0x78 count up; without a hit the velocity falls by 1/18. The position is kept at 0x48. From the second bounce on,
// 0x6c becomes 1 once the time at 0x70 passes 60.
void Object_000C6690::func_000C6820()
{
    int hit = 0;
    if (shape.first > 0 || shape.second > 0) {
        Hits_000C4C60 hits;
        if (data_0022FCE8.func_0001B5C0(&shape, (Sphere_000EC910 *)&center, radius, (int *)&hits, 0xffff, -1)) {
            Contact_000C4A90 *nearest;
            Vector3 *normal;
            int other = data_0022FCE8.func_000194B0(&hits, &nearest);
            Contact_000C4A90 *contact = nearest;
            if (!other) {
                func_0014C370(&velocity, &velocity, 0.7f);
                normal = &contact->normal;
                func_0014C730(&velocity, normal, func_0014C800(&velocity, normal) * -2.0f);
                func_0014C340(&position, &contact->point);
            } else {
                func_0014C370(&velocity, &velocity, 0.7f);
                normal = &contact->otherNormal;
                func_0014C730(&velocity, normal, func_0014C800(&velocity, normal) * -2.0f);
                func_0014C340(&position, &contact->otherPoint);
            }
            hit = 1;
            bounces++;
        }
    }
    last = position;
    if (!hit) {
        velocity.y -= 0.055555556f;
    }
    if (bounces >= 2) {
        if (++time > 60) {
            value_6c = 1;
        }
    }
}
