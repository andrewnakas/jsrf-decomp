struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);
void __fastcall func_0014C500(Vector3 *out, const Vector3 *in);
float func_0014C820(float value);
void func_000C5670(void *parent, Vector3 *position, Vector3 *direction, int kind);

struct Object_00047470 {
    void func_00047970(void *data, int value);
    void func_000480C0(unsigned int index);
};

struct Object_000607B0 {
    int func_000651E0(int kind, void *position, Vector3 *direction);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object in data_00257CE4: a point at 0xa0.
struct Object_000C1270 {
    char unknown_00[0xa0];
    Vector3 point;
};

extern Object_000C1270 *data_00257CE4;

// The muzzle point in the model's frame.
extern Vector3 data_0021B868;

struct Node {
    virtual ~Node();

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
    char unknown_34[0x10];
};

struct Object_000F55E0 : Node {
    char unknown_044[4];
    Vector3 position;
    char unknown_054[4];
    int heading;
    char unknown_05c[0xd4];
    Object_00047470 *model;
    char unknown_134[0x14];
    void *motion;

    void func_000F5760(int argument);
};

// Poses the model (motion at 0x148, part 15) at the position and heading, takes the point data_0021B868 and the
// downward axis in that frame and, when `argument` is set, tilts the axis toward 5 above the point at 0xa0 of
// data_00257CE4; then fires from the point along the axis (func_000C5670) and hands the point to object 0xe8 (kind 0x1d).
void Object_000F55E0::func_000F5760(int argument)
{
    Vector3 offset;
    Vector3 direction;
    Vector3 point;
    direction.x = 0.0f;
    direction.y = -1.0f;
    direction.z = 0.0f;
    func_001BA9C0();
    func_001BAAA0(&position.x);
    func_001BB330(heading + 0x8000);
    model->func_00047970(motion, 0);
    model->func_000480C0(0xf);
    func_001BAB20(&point, &data_0021B868);
    func_001BAC00(&direction, &direction);
    func_001BAA50();
    if (argument) {
        offset = data_00257CE4->point;
        offset.y += 5.0f;
        func_0014C500(&offset, &point);
        direction.y = offset.y / func_0014C820(offset.x * offset.x + offset.z * offset.z);
    }
    func_000C5670(0, &point, &direction, 0);
    Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (target) {
        target->func_000651E0(0x1d, &point, 0);
    }
}
