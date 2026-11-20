struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *position);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void func_001BB2B0(float scale);
void __fastcall func_001BB330(int angle);

struct Node {
    virtual ~Node();

    char unknown_04[0x24];
    Node *child;
    char unknown_2c[0x18];

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

int func_000D0530(Node *owner, Vector3 *position);

// The beam func_000D0530 makes.
struct Object_000CFB00 {
    void func_000CFB00(const Vector3 *from, const Vector3 *to);
};

// The object in data_00257CE4: a point at 0xa0.
struct Object_000C1270 {
    char unknown_00[0xa0];
    Vector3 point_a0;
};

extern Object_000C1270 *data_00257CE4;

extern Vector3 data_002165E0;

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *value);
    int func_000651E0(int kind, void *position, Vector3 *direction);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The owner at 0x4: position at 0x44, angles at 0x50.
struct Object_000C5B50 : Node {
    Vector3 position;
    Angles_000C1300 angles;

    int func_000C5B10(int message, void *data);
};

struct Object_00047470 {
    virtual ~Object_00047470();

    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

// The body at 0x58: its model first.
struct Body_000CF6D0 {
    Object_00047470 *model;
};

// The state handlers of the table at 0x2165F4 (owner at 4).
struct Object_000CE220 {
    int unknown_00;
    Object_000C5B50 *owner;
    int state;
    char unknown_0c[4];
    int value_10;
    char unknown_14[0x44];
    Body_000CF6D0 *body;
    char unknown_5c[0x1c];
    void *pose;
    char unknown_7c[0x18];
    int value_94;
    char unknown_98[4];
    int mode;
    char unknown_a0[0x84];
    int beam;
    char unknown_128[4];
    int value_12c;

    int func_000CE2D0();
    void func_000CF370();
};

// The handler at 0x216610: under the owner's transform (position, y angle plus a half turn, scale 2) poses the model
// and takes the point at data_002165E0 in the frame of its part 0xb. In mode 2: state 9, 5 at 0x94; the old beam
// (id at 0x124) leaves the tree, a new one starts at the point (func_000D0530) aimed at the point at 0xa0 of
// data_00257CE4 (func_000CFB00); node 0xe8 hears of it (kind 0x56, kept at 0x12c) and the owner gets message 0x43.
// Otherwise node 0xe8 gets the point for its key at 0x12c (func_000606C0) and func_000CE2D0 runs.
void Object_000CE220::func_000CF370()
{
    Vector3 point;
    func_001BAA00();
    func_001BAAA0(&owner->position.x);
    func_001BB330(owner->angles.y + 0x8000);
    func_001BB2B0(2.0f);
    body->model->func_00047970(pose, 0);
    body->model->func_000480C0(0xb);
    func_001BAB20(&point, &data_002165E0);
    if (mode == 2) {
        state = 9;
        value_94 = 5;
        Node *old = (Node *)data_0022FCE0->func_000128C0(beam);
        if (old) {
            old->func_00011BE0(old);
            old->func_00011C20(old->child);
        }
        beam = func_000D0530(owner, &point);
        Object_000CFB00 *created = (Object_000CFB00 *)data_0022FCE0->func_000128C0(beam);
        if (created) {
            created->func_000CFB00(&point, &data_00257CE4->point_a0);
        }
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            value_12c = node->func_000651E0(0x56, &point, 0);
        }
        owner->func_000C5B10(0x43, &owner->position);
    } else {
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            node->func_000606C0(value_12c, &point);
        }
        func_000CE2D0();
    }
    func_001BAA50();
}
