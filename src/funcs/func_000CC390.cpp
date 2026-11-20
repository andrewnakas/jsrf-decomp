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

// A contact of the first list (0x58 bytes): its point at 0x3c.
struct Contact_000C4A90 {
    char unknown_00[0x3c];
    Vector3 point;
    char unknown_48[0x10];
};

// A contact of the second list (0x84 bytes): its point at 0x60.
struct Contact_000CC390 {
    char unknown_00[0x60];
    Vector3 point;
    char unknown_6c[0x18];
};

// What func_0001B5C0 hands back: two lists of contacts with their counts.
struct Hits_000CC390 {
    Contact_000C4A90 *contacts;
    unsigned int count;
    Contact_000CC390 *others;
    unsigned int otherCount;
};

struct Object_00016200 {
    int func_0001B5C0(Shape_000EC910 *shape, Sphere_000EC910 *sphere, int radius, int *hit, int mask, int limit);
};

extern Object_00016200 data_0022FCE8;

void __fastcall func_0014C340(Vector3 *vector, const Vector3 *offset);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);

// The owner at 0x4: flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;
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

    Object_000C5B50 *owner;
    char unknown_08[0xc];
    Vector3 position;
    char unknown_20[0x14];
    Vector3 target;
    char unknown_40[0x94];
    Shape_000EC910 shape;
    Vector3 center;
    int radius;
};

// Tests the collision item at 0xd4 around the point at 0xf8 with the radius at 0x104 (func_0001B5C0 of
// data_0022FCE8, mask 0xffff). On a hit, the position at 0x14 moves by the mean of all contact points of both lists
// (func_0014C340, func_0014C370), which is also kept at 0x34, and the owner gains flag 0x200.
void Object_000CCE00::func_000CC390()
{
    Hits_000CC390 hits;
    if (data_0022FCE8.func_0001B5C0(&shape, (Sphere_000EC910 *)&center, radius, (int *)&hits, 0xffff, -1)) {
        Vector3 sum;
        unsigned int index;
        sum.x = 0.0f;
        sum.y = 0.0f;
        sum.z = 0.0f;
        Contact_000C4A90 *contact = hits.contacts;
        for (index = 0; index < hits.count; index++, contact++) {
            func_0014C340(&sum, &contact->point);
        }
        Contact_000CC390 *other = hits.others;
        for (index = 0; index < hits.otherCount; index++, other++) {
            func_0014C340(&sum, &other->point);
        }
        func_0014C370(&sum, &sum, 1.0f / (hits.count + hits.otherCount));
        func_0014C340(&position, &sum);
        target = sum;
        owner->flags |= 0x200;
    }
}
