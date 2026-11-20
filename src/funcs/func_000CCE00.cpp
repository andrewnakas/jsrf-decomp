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

// What func_00018260 casts a ray through: two counts, at +0x4 and +0x14.
struct Model_00018260 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int unknown_14;
    char unknown_18[0xc];
};

// A contact func_000194B0 picks: a face's point at 0x2c and normal at 0x48, an edge's at 0x50 and 0x6c.
struct Contact_000C4A90 {
    char unknown_00[0x2c];
    Vector3 point;
    char unknown_38[0x10];
    Vector3 normal;
};

struct Edge_000CCE00 {
    char unknown_00[0x50];
    Vector3 point;
    char unknown_5c[0x10];
    Vector3 normal;
};

struct Hits_000C4C60;

struct Hit_00018260 {
    Contact_000C4A90 *faces;
    unsigned int faceCount;
    Contact_000C4A90 *edges;
    unsigned int edgeCount;
};

struct Object_00016200 {
    int func_00018260(Model_00018260 *model, Vector3 *from, Vector3 *to, Hit_00018260 *hit, int mask, int flags);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);

// The owner at 0x4: where it was at 0x44, its speed at 0x5c, lift at 0x60, motion at 0x74 and flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 last;
    int value_50;
    char unknown_54[8];
    float speed;
    float lift;
    char unknown_64[0x10];
    Vector3 motion;
    char unknown_80[0x24];
    unsigned int flags;
};

// The fall of the limits at 0x30: gravity at 0x3c, the fastest fall at 0x40.
struct Limits_000CC020 {
    char unknown_00[0x3c];
    float gravity;
    float limit;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE320 (constructor func_000CC620, destructor func_000CC680).
struct Object_000CCE00 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CCE00();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CBF20();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();
    virtual void func_000CC020();

    void func_000CC390();
    void func_000CCE00();

    Object_000C5B50 *owner;
    char unknown_08[0xc];
    Vector3 position;
    char unknown_20[0x10];
    Limits_000CC020 *limits;
    Vector3 normal;
    char unknown_40[0x50];
    Model_00018260 ray;
    char unknown_b4[0x20];
    Shape_000EC910 shape;
};

// The owner's fall: still and not falling, it only stops. Otherwise a ray from 3 above where the owner was to 1
// below the position (func_00018260 of data_0022FCE8, mask 0xffff) puts the position on the nearest face or edge
// with its normal at 0x34; the shape pushes out of walls (func_000CC390). On ground the motion is the step and the
// lift its height, else the lift falls by the gravity down to the limit and bit 0x80 marks the fall. The owner
// keeps the position.
void Object_000CCE00::func_000CCE00()
{
    if (owner->speed == 0.0f && owner->lift == 0.0f && !(owner->flags & 0x80)) {
        owner->value_50 = 0;
    } else {
        int hit = 0;
        if (ray.count > 0 || ray.unknown_14 > 0) {
            Vector3 from = owner->last;
            from.y += 3.0f;
            Vector3 to = position;
            to.y -= 1.0f;
            Hit_00018260 hits;
            if (data_0022FCE8.func_00018260(&ray, &from, &to, &hits, 0xffff, -1)) {
                Contact_000C4A90 *nearest;
                if (!data_0022FCE8.func_000194B0((Hits_000C4C60 *)&hits, &nearest)) {
                    position = nearest->point;
                    normal = nearest->normal;
                } else {
                    position = ((Edge_000CCE00 *)nearest)->point;
                    normal = ((Edge_000CCE00 *)nearest)->normal;
                }
                hit = 1;
            }
        }
        owner->flags &= ~0x200;
        if (shape.first > 0 || shape.second > 0) {
            func_000CC390();
        }
        if (hit) {
            func_0014C4C0(&owner->motion, &position, &owner->last);
            owner->lift = owner->motion.y;
            owner->flags &= ~0x80;
        } else {
            if (owner->lift > 0.0f) {
                owner->lift = 0;
            }
            owner->lift -= limits->gravity;
            float limit = -limits->limit;
            if (owner->lift < limit) {
                owner->lift = limit;
            }
            owner->value_50 = 0;
            owner->flags |= 0x80;
        }
    }
    owner->last = position;
}
