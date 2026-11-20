struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// What func_00018260 tests a segment against: two counted parts (+4 and +0x14).
struct Model_00018260 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int unknown_14;
};

// A contact func_000194B0 picks: a face (0x58 bytes) keeps its kind and normal at +0x28 / +0x2c, an edge (0x84 bytes)
// at +0x4c / +0x50.
struct Contact_000C4A90 {
    char unknown_00[0x28];
    int faceKind;
    Vector3 faceNormal;
    char unknown_38[0x14];
    int edgeKind;
    Vector3 edgeNormal;
};

// What func_00018260 reports: two lists.
struct Hit_00018260 {
    Contact_000C4A90 *faces;
    unsigned int faceCount;
    Contact_000C4A90 *edges;
    unsigned int edgeCount;
};

struct Hits_000C4C60;

struct Object_00016200 {
    int func_00018260(Model_00018260 *model, Vector3 *from, Vector3 *to, Hit_00018260 *hit, int mask, int flags);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

// The player.
struct Object_000A1C50 {
    char unknown_0000[0x1e0];
    Model_00018260 model;
    char unknown_01f8[0xf38];
    int found;
    int kind;
    Vector3 normal;

    void func_000870B0(float *position, int *angles);
};

// Casts the player's model (+0x1e0) from 5 above the position down one unit, both turned by the angles, against
// mask 0x40 (func_00018260); on a hit keeps the kind and normal of the nearest face or edge (func_000194B0) at
// +0x1134 / +0x1138 and sets +0x1130.
void Object_000A1C50::func_000870B0(float *position, int *angles)
{
    func_001BAA00();
    func_001BAAA0(position);
    func_001BB2E0(angles[0]);
    func_001BB380(angles[2]);
    func_001BB330(angles[1]);
    Vector3 above = {0.0f, 5.0f, 0.0f};
    Vector3 from;
    func_001BAB20(&from, &above);
    Vector3 below = {0.0f, -1.0f, 0.0f};
    Vector3 to;
    func_001BAB20(&to, &below);
    func_001BAA50();
    Hit_00018260 hit;
    if (data_0022FCE8.func_00018260(&model, &from, &to, &hit, 0x40, -1)) {
        Contact_000C4A90 *nearest;
        if (data_0022FCE8.func_000194B0((Hits_000C4C60 *)&hit, &nearest)) {
            normal = nearest->edgeNormal;
            kind = nearest->edgeKind;
        } else {
            normal = nearest->faceNormal;
            kind = nearest->faceKind;
        }
        found = 1;
    }
}
