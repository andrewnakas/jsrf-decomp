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
void __fastcall func_001BAA50();
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

// The beam func_000D0530 makes (a Node; its functions are named after func_000CFB00, func_000CFB40 and
// func_000CFB50 by their units).
struct Object_000CFB00 : Node {
    void func_000CFB00(const Vector3 *from, const Vector3 *to);
};

struct Object_000CFB40 {
    int func_000CFB40();
};

struct Object_000CFB50 {
    void func_000CFB50();
};

// The object in data_00257CE4: its point at 0x7c.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 point;
};

extern Object_000C1270 *data_00257CE4;

extern Vector3 data_002165E0;

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *value);
    void func_00060810(int key);
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
    void func_000CF4E0();
};

// The handler at 0x216614: when func_000CE2D0 answers 0, poses the model under the owner's transform, hands node 0xe8
// the point at data_002165E0 in the frame of its part 0xb for its key at 0x12c, aims the beam (id at 0x124) from that
// point to the point of data_00257CE4 (func_000CFB00) and, once the beam is done (func_000CFB40), takes it out of
// the tree: no beam, state 0xa, 6 at 0x94. Otherwise the beam is stopped (func_000CFB50) and node 0xe8 drops the key.
void Object_000CE220::func_000CF4E0()
{
    Vector3 point;
    if (!func_000CE2D0()) {
        func_001BAA00();
        func_001BAAA0(&owner->position.x);
        func_001BB330(owner->angles.y + 0x8000);
        func_001BB2B0(2.0f);
        body->model->func_00047970(pose, 0);
        body->model->func_000480C0(0xb);
        func_001BAB20(&point, &data_002165E0);
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            node->func_000606C0(value_12c, &point);
        }
        func_001BAA50();
        Object_000CFB00 *current = (Object_000CFB00 *)data_0022FCE0->func_000128C0(beam);
        if (current) {
            current->func_000CFB00(&point, &data_00257CE4->point);
            if (!((Object_000CFB40 *)current)->func_000CFB40()) {
                current->func_00011BE0(current);
                current->func_00011C20(current->child);
                beam = -1;
                state = 0xa;
                value_94 = 6;
            }
        }
    } else {
        Object_000CFB50 *current = (Object_000CFB50 *)data_0022FCE0->func_000128C0(beam);
        if (current) {
            current->func_000CFB50();
            beam = -1;
        }
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            node->func_00060810(value_12c);
        }
    }
}
