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
void __fastcall func_0014C8B0(Vector3 *out, const Vector3 *first, const Vector3 *second, float share);
int func_0014C7D0(float x, float z);
void func_001BAA00();
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

struct Object_00157F10 : Object_000C1440 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

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

// One of the three collision marks (func_00016260's item): its box and its shape at 0x20.
struct Mark_000CA6B0 {
    int mask;
    int value;
    Box_00017CC0 box;
    Model_00018260 shape;
};

struct Object_000C7910 {
    char unknown_00[0x54];
    Angles_000C1300 angles;
    char unknown_60[0x30];
    unsigned int flags;
    char unknown_94[0x3c];
    Vector3 position;
    char unknown_dc[0x14];
    float lifts[3];
    char unknown_fc[0xc];
    Vector3 points[3];
    char unknown_12c[0xac];
    Sphere_000EC910 sphere;
    char unknown_1e8[0x54];
    Item_00016260 item;
    char unknown_280[0x44];
    Mark_000CA6B0 marks[3];
    char unknown_390[0x24];
    Params_000CA920 *params;

    void func_000CA6B0();
    void func_000CA0A0(Item_00016260 *item, Sphere_000EC910 *sphere);
};

// The movement step with flag 0x2000000 (bit 7 set): each of the three points at 0x108 drops on the ground under
// its mark (a ray from 3 above it; bit 28 for an edge, its lift cleared and bit 7 too) or falls by its lift (the
// lift takes the kind's gravity, at most its limit). The position is the middle of the three, pushed out by the
// first item (func_000CA0A0); data_00257CE8 turns the angles at 0x54 toward the way from the third point to the
// middle of the first two (step 0x8000), and the roll at 0x5c follows the way from the second to the first.
void Object_000C7910::func_000CA6B0()
{
    Vector3 ground[3];
    Vector3 middle;
    Vector3 way;
    flags |= 0x80;
    for (int i = 0; i < 3; i++) {
        if (marks[i].shape.count > 0 || marks[i].shape.unknown_14 > 0) {
            Vector3 to = points[i];
            Vector3 from = points[i];
            from.y += 3.0f;
            Hit_00018260 hits;
            if (data_0022FCE8.func_00018260(&marks[i].shape, &from, &to, &hits, 0xffff, -1)) {
                Contact_000C4A90 *nearest;
                if (!data_0022FCE8.func_000194B0((Hits_000C4C60 *)&hits, &nearest)) {
                    ground[i] = nearest->point;
                    flags &= ~0x10000000;
                } else {
                    ground[i] = nearest->edgePoint;
                    flags |= 0x10000000;
                }
                lifts[i] = 0;
                flags &= ~0x80;
                continue;
            }
        }
        ground[i] = points[i];
        ground[i].y += lifts[i];
        lifts[i] -= params->fall->gravity;
        if (lifts[i] > params->fall->limit) {
            lifts[i] = params->fall->limit;
        }
    }
    func_0014C8B0(&middle, &ground[0], &ground[1], 0.5f);
    func_0014C8B0(&position, &middle, &ground[2], 0.5f);
    if (item.shape.first > 0 || item.shape.second > 0) {
        func_000CA0A0(&item, &sphere);
    }
    func_0014C4C0(&way, &middle, &ground[2]);
    data_00257CE8->func_000C1F20(&angles, &way, 0x8000);
    func_0014C4C0(&way, &ground[0], &ground[1]);
    func_001BAA00();
    func_001BB2E0(-angles.x);
    func_001BB330(-angles.y);
    func_001BAC00(&way, &way);
    func_001BAA50();
    angles.z = -func_0014C7D0(way.y, way.x);
}
