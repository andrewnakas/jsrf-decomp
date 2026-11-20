struct Motion_0005F060;

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

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
float __fastcall func_0014C460(Vector3 *a, const Vector3 *b);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
int func_0014C7D0(float x, float z);
void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void func_001BB5E0();

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 : Object_000C1440 {
    void func_000C1E60();
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    float value_5c;
    char unknown_60[0x44];
    unsigned int flags;
};

// The model (the holder's first word).
struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Holder_000EDC30 {
    Object_00047470 *model;
};

// The motions at 0xf8.
struct Source_000EDC30 {
    char unknown_00[8];
    Motion_0005F060 *motion_08;
    char unknown_0c[0xc];
    Motion_0005F060 *motion_18;
    Motion_0005F060 *motion_1c;
    Motion_0005F060 *motion_20;
};

// The block at 0xd4.
struct Block_000EDC30 {
    int value_00;
    int value_04;
};

extern Block_000EDC30 data_0021A774;
extern Vector3 data_0021A8AC;

// The class of func_000EDC30; these are handlers of its table at 0x21A900.
struct Object_000EDC30 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int timer;
    char unknown_014[0xc0];
    Block_000EDC30 *block;
    char unknown_0d8[4];
    int value_0dc;
    int value_0e0;
    char unknown_0e4[4];
    int value_0e8;
    int value_0ec;
    int count;
    Holder_000EDC30 *holder;
    Source_000EDC30 *source;
    void *handle;
    int value_100;
    char unknown_104[8];
    float time_10c;
    float time_110;
    int value_114;
    char unknown_118[0x264];
    Vector3 point;
    Angles_000C1300 angles;
    Motion_0005F060 *motion;
    float time;

    void func_000EE680();
    void func_000EE7E0();
    void func_000EED40();
};

// A handler of the table at 0x21A900: takes the point at 0x37c (data_0021A8AC from the model's part 1, placed and
// turned with the owner) and turns the angles at 0x388 towards its -z axis (func_000C1F20, step 0x8000); then the
// motion at 0x1c of the source from 0, 0 at 0x114, the block at data_0021A774 and state 6.
void Object_000EDC30::func_000EE680()
{
    Vector3 direction;
    direction.x = 0.0f;
    direction.y = 0.0f;
    direction.z = -1.0f;
    func_001BA9C0();
    func_001BAAA0(&owner->position.x);
    func_001BB330(owner->angles.y + 0x8000);
    func_001BB2E0(owner->angles.x);
    func_001BB380(owner->angles.z);
    holder->model->func_00047970(handle, 0);
    holder->model->func_000480C0(1);
    func_001BAB20(&point, &data_0021A8AC);
    func_001BAC00(&direction, &direction);
    func_001BAA50();
    data_00257CE8->func_000C1F20(&angles, &direction, 0x8000);
    motion = source->motion_1c;
    time = 0.0f;
    value_114 = 0;
    block = &data_0021A774;
    state = 6;
}
