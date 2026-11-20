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

void func_001BA9C0();
void func_001BB650(float distance);
void func_001BAA50();
void __fastcall func_001BAAA0(float *position);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void func_001BB2B0(float scale);
void __fastcall func_001BB330(int angle);

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *value);
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
    int value_130;

    void func_000CE010();
};

// The handler at 0x216608: under the owner's transform (position, y angle plus a half turn, scale 2) poses the model
// (func_00047970 with the pose at 0x78) and hands node 0xe8 the points 5 units back of its parts 0xf and 0x13
// (func_000480C0, func_001BB650, func_001BAB20) for its keys at 0x12c and 0x130 (func_000606C0). In mode 2, state 4
// and 1 at 0x94.
void Object_000CE220::func_000CE010()
{
    Vector3 point;
    func_001BA9C0();
    func_001BAAA0(&owner->position.x);
    func_001BB330(owner->angles.y + 0x8000);
    func_001BB2B0(2.0f);
    body->model->func_00047970(pose, 0);
    body->model->func_000480C0(0xf);
    func_001BB650(-5.0f);
    func_001BAB20(&point, 0);
    Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (node) {
        node->func_000606C0(value_12c, &point);
    }
    body->model->func_000480C0(0x13);
    func_001BB650(-5.0f);
    func_001BAB20(&point, 0);
    node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (node) {
        node->func_000606C0(value_130, &point);
    }
    func_001BAA50();
    if (mode == 2) {
        state = 4;
        value_94 = 1;
    }
}
