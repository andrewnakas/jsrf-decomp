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

    char unknown_04[0x40];
};

int func_000D09E0(Node *node, Vector3 *point);

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
    char unknown_0c[0x4c];
    Body_000CF6D0 *body;
    char unknown_5c[0x1c];
    void *pose;
    char unknown_7c[0x18];
    int value_94;
    char unknown_98[4];
    int mode;
    char unknown_a0[0x88];
    int value_128;

    void func_000CE2D0();
    void func_000CF6D0();
};

// The handler at 0x216620: outside mode 2 runs func_000CE2D0. In mode 2: state 0xd and 9 at 0x94; under the owner's
// transform (position, y angle plus a half turn, scale 2) poses the model (func_00047970 with the pose at 0x78) and
// takes the place of its part 8 (func_000480C0, func_001BAB20) for func_000D09E0 (kept at 0x128), then sends the
// owner message 0x42 with its position (func_000C5B10).
void Object_000CE220::func_000CF6D0()
{
    Vector3 point;
    if (mode == 2) {
        state = 0xd;
        value_94 = 9;
        func_001BAA00();
        func_001BAAA0(&owner->position.x);
        func_001BB330(owner->angles.y + 0x8000);
        func_001BB2B0(2.0f);
        body->model->func_00047970(pose, 0);
        body->model->func_000480C0(8);
        func_001BAB20(&point, 0);
        func_001BAA50();
        value_128 = func_000D09E0(owner, &point);
        owner->func_000C5B10(0x42, &owner->position);
    } else {
        func_000CE2D0();
    }
}
