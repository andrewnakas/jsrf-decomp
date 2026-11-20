/* sym: ?func_00011C90_1@Object_000AE220@@UAEXXZ = 0x000AE430 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The first part of a mesh: a centre and an extent.
struct Part_00017F60 {
    Vector3 center;
    float radius;
    Vector3 extent;
    char unknown_1c[8];
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BB270(float *scale);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);

// A point and a value handed to the part.
struct Record_00015D10 {
    Vector3 point;
    int value;
};

struct Object_00015D50 {
    void func_00015520();
    void func_00015D10(const Record_00015D10 *record);
};

// One of the motions touching the node (0x1a4), linked through 0x38: its state at 0, a value at 0x28 and a direction
// at 0x2c.
struct Motion_000AE430 {
    int state;
    char unknown_04[0x24];
    int value;
    Vector3 direction;
    Motion_000AE430 *next;
};

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD730).
struct Object_000AE220 : Node {
    virtual void func_00011C90_1();

    char unknown_040[0xa0];
    int seen;
    int value_e4;
    char unknown_0e8[0xc];
    Object_00015D50 *part;
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_11c[0x74];
    int mode;
    float reach;
    char unknown_198[0xc];
    Motion_000AE430 *motion;
    char unknown_1a8[0x14];
    Part_00017F60 *parts;
};

// Slot 2: in mode 1 when seen (0xe0, 0xe4), and in mode 8, the first motion in state 0 hands its direction scaled by
// 0x194, carried through the frame of the mesh's first part, to the part (func_00015D10); then the part is drawn at
// the node's position, angles and scale (func_00015520) and the seen words are cleared.
void Object_000AE220::func_00011C90_1()
{
    switch (mode) {
    case 1:
        if (!seen || !value_e4) {
            break;
        }
    case 8:
        for (Motion_000AE430 *motion = this->motion; motion; motion = motion->next) {
            if (motion->state == 0) {
                Vector3 scaled;
                func_0014C370(&scaled, &motion->direction, reach);
                func_001BA9C0();
                func_001BAAA0(&parts->center.x);
                func_001BAC50(angles, 0);
                func_001BB270(&scale.x);
                Vector3 point;
                func_001BAB20(&point, &scaled);
                Record_00015D10 record;
                record.point.x = point.x;
                record.point.y = point.y;
                record.point.z = point.z;
                record.value = motion->value;
                if (part) {
                    part->func_00015D10(&record);
                }
                func_001BAA50();
                break;
            }
        }
        break;
    }
    if (part) {
        func_001BA9C0();
        func_001BAAA0(&position.x);
        func_001BAC50(angles, 0);
        func_001BB270(&scale.x);
        part->func_00015520();
        func_001BAA50();
    }
    seen = 0;
    value_e4 = 0;
}
