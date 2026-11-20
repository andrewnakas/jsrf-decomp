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

    char unknown_04[0x40];
};

extern Vector3 data_002165E0;

struct Object_000607B0 {
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
    char unknown_a0[0x8c];
    int value_12c;

    int func_000CE2D0();
    void func_000CF2A0();
};

// The handler at 0x21660C: in mode 2, state 8, 4 at 0x94 and 0x10 cleared; under the owner's transform (position,
// y angle plus a half turn, scale 2) poses the model (func_00047970 with the pose at 0x78) and takes the point at
// data_002165E0 in the frame of its part 0xb (func_000480C0, func_001BAB20); tells node 0xe8 about it (kind 0x55, kept
// at 0x12c) and sends the owner message 0x40 with it (func_000C5B10). Then, in every mode, func_000CE2D0.
void Object_000CE220::func_000CF2A0()
{
    Vector3 point;
    if (mode == 2) {
        state = 8;
        value_94 = 4;
        value_10 = 0;
        func_001BAA00();
        func_001BAAA0(&owner->position.x);
        func_001BB330(owner->angles.y + 0x8000);
        func_001BB2B0(2.0f);
        body->model->func_00047970(pose, 0);
        body->model->func_000480C0(0xb);
        func_001BAB20(&point, &data_002165E0);
        func_001BAA50();
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            value_12c = node->func_000651E0(0x55, &point, 0);
        }
        owner->func_000C5B10(0x40, &point);
    }
    func_000CE2D0();
}
