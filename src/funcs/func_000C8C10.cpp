struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *position);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Object_000607B0 {
    int func_000651E0(int kind, void *position, Vector3 *direction);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0003E750 {
    void func_0003F280(int effect);
};

extern Object_0003E750 data_002314B0;

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240).
struct Object_000C7910 : Node, Object_000C60C0 {
    virtual void func_000C8C10();

    Vector3 last;
    Angles_000C1300 angles;
    float speed;
    float lift;
    char unknown_068[0x28];
    unsigned int flags;
    char unknown_094[8];
    int value_9c;
    char unknown_0a0[0x1c];
    int value_bc;
    char unknown_0c0[0x2c];
    int value_ec;
    char unknown_0f0[0x7c];
    float height;
    char unknown_170[0x14];
    Object_00047470 *model;
    char unknown_188[0x14];
    void *pose;
    char unknown_1a0[0x24];
    int count;
    char unknown_1c8[0x1f0];
    int effect;

    void func_000C8600();
};

// Slot 44: moves (func_000C8600); unless flag 0x80 is set with the height at 0x16c at most 200 above the last
// position, it lands: flag 0x2000, 0xbc = 0x1d, 0x1c4 = 2, speeds and 0xec cleared; under its transform (position,
// angles with y turned half round) the model is posed (func_00047970 with the pose at 0x19c) and node 0xe8 starts
// effect 0x26 at its part 8 one above the ground (func_000480C0, func_001BAB20, func_000651E0); the effect at 0x3b8
// stops (func_0003F280) and becomes -1, and 0x9c = 1.
void Object_000C7910::func_000C8C10()
{
    func_000C8600();
    if ((flags & 0x80) && !(height - last.y > 200.0f)) {
        return;
    }
    flags |= 0x2000;
    value_bc = 0x1d;
    count = 2;
    value_ec = 0;
    speed = 0.0f;
    lift = 0.0f;
    func_001BA9C0();
    func_001BAAA0(&last.x);
    func_001BB330(angles.y + 0x8000);
    func_001BB2E0(angles.x);
    func_001BB380(angles.z);
    model->func_00047970(pose, 0);
    model->func_000480C0(8);
    Vector3 point;
    func_001BAB20(&point, 0);
    func_001BAA50();
    point.y = last.y + 1.0f;
    Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (node) {
        node->func_000651E0(0x26, &point, 0);
    }
    data_002314B0.func_0003F280(effect);
    effect = -1;
    value_9c = 1;
}
