/* const: 0x200000 */
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

// What func_00018260 casts a ray through: two counts, at +0x4 and +0x14.
struct Model_00018260 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int unknown_14;
    char unknown_18[0xc];
};

// A contact func_000194B0 picks: the point a face was hit at 0x2c, an edge at 0x50.
struct Contact_000C4A90 {
    char unknown_00[0x2c];
    Vector3 point;
    char unknown_38[0x18];
    Vector3 edgePoint;
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

// The fall of a kind: what is taken off the vertical speed each step, and its limit.
struct Fall_000CA920 {
    char unknown_00[0x3c];
    float gravity;
    float limit;
};

struct Params_000CA920 {
    char unknown_00[0x30];
    Fall_000CA920 *fall;
};

struct Object_000C7910 {
    char unknown_00[0x48];
    Vector3 last;
    int value_54;
    char unknown_58[8];
    float speed;
    float lift;
    char unknown_68[0x28];
    unsigned int flags;
    char unknown_94[0x28];
    int mode;
    char unknown_c0[4];
    Vector3 motion;
    Vector3 position;
    Vector3 previous;
    char unknown_e8[0x84];
    float mark;
    char unknown_170[0x68];
    Sphere_000EC910 sphere;
    Sphere_000EC910 sphere2;
    char unknown_1f8[0x20];
    Model_00018260 ray;
    Item_00016260 item;
    Item_00016260 item2;
    char unknown_2c4[0xf0];
    Params_000CA920 *params;

    void func_000CA6B0();
    void func_000CA920();
    void func_000CA0A0(Item_00016260 *item, Sphere_000EC910 *sphere);
    void func_000CA1C0(Item_00016260 *item, Sphere_000EC910 *sphere);
};

// One step of the movement from the last position (0x48, kept at 0xdc) to the new one at 0xd0; nothing with flag
// 0x100 or 0x4000000. With flag 0x2000000 func_000CA6B0 moves it; without bit 7 and with no speed or lift it stays.
// Otherwise a ray from 3 above the last position to 1 below the new one (not below with flag 0x200000) puts it on the
// ground at the hit face or edge (bit 28 for an edge), and both collision items push it out (func_000CA0A0,
// func_000CA1C0). On the ground the motion is kept at 0xc4 (its y as the lift unless flag 0x200000) and bit 7
// cleared; in the air the lift falls by the kind's gravity to its limit (a rising lift is cut first unless flag
// 0x200000), and bit 7 marks the height it left at 0x16c: 30 below it, mode 0x1b and flag 0x400000.
void Object_000C7910::func_000CA920()
{
    previous = last;
    if (flags & 0x4000100) {
        return;
    }
    flags &= ~0x200;
    if (flags & 0x2000000) {
        func_000CA6B0();
        last = position;
        return;
    }
    if (!(flags & 0x80) && speed == 0.0f && lift == 0.0f) {
        last = position;
        return;
    }
    int hit = 0;
    if (ray.count > 0 || ray.unknown_14 > 0) {
        Vector3 from = last;
        from.y += 3.0f;
        Vector3 to = position;
        if (!(flags & 0x200000)) {
            to.y -= 1.0f;
        }
        Hit_00018260 hits;
        if (data_0022FCE8.func_00018260(&ray, &from, &to, &hits, 0xffff, -1)) {
            Contact_000C4A90 *nearest;
            if (!data_0022FCE8.func_000194B0((Hits_000C4C60 *)&hits, &nearest)) {
                hit = 1;
                flags &= ~0x10000000;
                position = nearest->point;
            } else {
                hit = 1;
                flags |= 0x10000000;
                position = nearest->edgePoint;
            }
        }
    }
    if (item.shape.first > 0 || item.shape.second > 0) {
        func_000CA0A0(&item, &sphere);
    }
    if (item2.shape.first > 0 || item2.shape.second > 0) {
        func_000CA1C0(&item2, &sphere2);
    }
    if (hit) {
        func_0014C4C0(&motion, &position, &last);
        if (!(flags & 0x200000)) {
            lift = motion.y;
        }
        flags &= ~0x80;
    } else {
        if (!(flags & 0x200000) && lift > 0.0f) {
            lift = 0;
        }
        lift -= params->fall->gravity;
        float limit = -params->fall->limit;
        if (lift < limit) {
            lift = limit;
        }
        value_54 = 0;
        if (flags & 0x80) {
            if (!(flags & 0x400000) && mark - position.y > 30.0f) {
                mode = 0x1b;
                flags |= 0x400000;
            }
        } else {
            flags |= 0x80;
            mark = position.y;
        }
    }
    last = position;
}
