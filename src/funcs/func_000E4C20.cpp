struct Vector3 {
    float x;
    float y;
    float z;
};

// What func_00018260 tests a segment against: two counted parts (+4 and +0x14).
struct Model_00018260 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int unknown_14;
};

// A face func_00018260 reports (0x58 bytes).
struct Face_000E4540 {
    char unknown_00[0x38];
    float distance;
    char unknown_3c[0x1c];
};

// An edge func_00018260 reports (0x84 bytes).
struct Edge_000E4540 {
    char unknown_00[0x5c];
    float distance;
    char unknown_60[0x24];
};

// What func_00018260 reports: two lists.
struct Hit_00018260 {
    Face_000E4540 *faces;
    unsigned int faceCount;
    Edge_000E4540 *edges;
    unsigned int edgeCount;
};

// A contact func_000194B0 or func_000E4540 picks: a face keeps a point at +0x2c and its distance at +0x38, an edge
// at +0x50 / +0x5c.
struct Contact_000C4A90 {
    union {
        struct {
            char unknown_00[0x2c];
            Vector3 point;
            float distance;
        } face;
        struct {
            char unknown_00[0x50];
            Vector3 point;
            float distance;
        } edge;
    };
};

struct Hits_000C4C60;

struct Object_00016200 {
    int func_00018260(Model_00018260 *model, Vector3 *from, Vector3 *to, Hit_00018260 *hit, int mask, int flags);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C340(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __fastcall func_0014C8B0(Vector3 *out, const Vector3 *first, const Vector3 *second, float share);

// The Node + Object_000C60C0 class whose table is at 0x1CEC10 (constructor func_000E45D0).
struct Object_000E45D0 {
    char unknown_000[0xbc];
    unsigned int state;
    char unknown_0c0[0x1c];
    Vector3 point_dc;
    Vector3 point_e8;
    Vector3 value_f4;
    char unknown_100[0xc8];
    Model_00018260 model;
    char unknown_1e0[0x18];
    int value_1f8;

    int func_000E4540(Hit_00018260 *hit, void **nearest);
    void func_000E4C20();
};

// State 1 with 0x1f8 set (unless 2), state 3 from 2 without. Then, when the model at 0x1c8 has parts, sweeps it from
// 0xdc to 0xe8 (func_000194B0 picks the contact) and back (func_000E4540 picks); a way-back contact nearer 0xdc than
// the first one's distance cancels the first. Both: 0xe8 goes halfway between the two points; only the first: 0xe8
// moves by the vector at 0xf4 times 10; only the way back: times -10.
void Object_000E45D0::func_000E4C20()
{
    if (value_1f8 != 0) {
        if (state != 2) {
            state = 1;
        }
    } else if (state == 2) {
        state = 3;
    }
    if (model.count > 0 || model.unknown_14 != 0) {
        int found = 0;
        int back = 0;
        Hit_00018260 hit;
        Vector3 ahead;
        float reach;
        if (data_0022FCE8.func_00018260(&model, &point_dc, &point_e8, &hit, 0xffff, -1)) {
            Contact_000C4A90 *nearest;
            if (!data_0022FCE8.func_000194B0((Hits_000C4C60 *)&hit, &nearest)) {
                ahead = nearest->face.point;
                reach = nearest->face.distance;
            } else {
                ahead = nearest->edge.point;
                reach = nearest->edge.distance;
            }
            found = 1;
        }
        Vector3 behind;
        if (data_0022FCE8.func_00018260(&model, &point_e8, &point_dc, &hit, 0xffff, -1)) {
            Contact_000C4A90 *nearest;
            if (!func_000E4540(&hit, (void **)&nearest)) {
                behind = nearest->face.point;
            } else {
                behind = nearest->edge.point;
            }
            back = 1;
            if (found && func_0014C530(&point_dc, &behind) < reach) {
                found = 0;
            }
        }
        if (found) {
            if (back) {
                func_0014C8B0(&point_e8, &ahead, &behind, 0.5f);
            } else {
                Vector3 step = value_f4;
                func_0014C370(&step, &step, 10.0f);
                func_0014C340(&point_e8, &step);
            }
        } else if (back) {
            Vector3 step = value_f4;
            func_0014C370(&step, &step, -10.0f);
            func_0014C340(&point_e8, &step);
        }
    }
}
