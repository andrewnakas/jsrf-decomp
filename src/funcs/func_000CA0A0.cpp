struct Vector3 {
    float x;
    float y;
    float z;
};

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

// A centre and a radius.
struct Sphere_000EC910 {
    Vector3 center;
    float radius;
};

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

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240).
struct Object_000C7910 {
    char unknown_00[0x90];
    unsigned int flags;
    char unknown_94[0x3c];
    Vector3 position;
    char unknown_dc[0x20];
    Vector3 push;

    void func_000CA0A0(Item_00016260 *item, Sphere_000EC910 *sphere);
};

// Tests the item's shape against the sphere (func_0001B5C0 of data_0022FCE8, mask 0xffff). On a hit, the position at
// 0xd0 moves by the mean of the contact points (func_0014C340, func_0014C370), which is also kept at 0xfc, and flag
// 0x200 is set. Unlike func_000CC390, the second list's first point is summed once per contact of that list (the
// pointer does not advance).
void Object_000C7910::func_000CA0A0(Item_00016260 *item, Sphere_000EC910 *sphere)
{
    Hits_000CC390 hits;
    if (data_0022FCE8.func_0001B5C0(&item->shape, sphere, *(int *)&sphere->radius, (int *)&hits, 0xffff, -1)) {
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
        for (index = 0; index < hits.otherCount; index++) {
            func_0014C340(&sum, &other->point);
        }
        func_0014C370(&sum, &sum, 1.0f / (hits.count + hits.otherCount));
        func_0014C340(&position, &sum);
        push = sum;
        flags |= 0x200;
    }
}
