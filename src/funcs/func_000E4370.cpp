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

struct Object_00047470 {
    virtual ~Object_00047470();

    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Model_000E4370 {
    Object_00047470 *object;
};

struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5B40(int id, void *position);
    int func_000C5B70(int handle);
};

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;

int func_0014C7D0(float first, float second);
float func_0014C820(float value);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void func_001BB5E0();

struct Object_000E45D0 {
    char unknown_000[0x48];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_060[0x50];
    Object_000C5B50 *owner;
    char unknown_0b4[0x10];
    int yaw;
    int pitch;
    Vector3 target_0cc;
    char unknown_0d8[0x6c];
    int value_144;
    char unknown_148[0x1c];
    Model_000E4370 *model;
    char unknown_168[0xbc];
    int effect;

    int func_000E4370();
};

// Aims at the target at 0xcc: poses the model at the position and angles, takes the muzzle point (the origin through
// the matrix) and keeps an effect (id at 0x224) of the owner at 0xb0 there (message 0x14 starts one). The offset to
// the target, through the inverse of the matrix, gives the pitch (at most 0x2000 either way) and the yaw; the
// angles at 0xc8 and 0xc4 turn towards them by the step at 0x144 (func_000C1450). Returns how far the yaw is still off.
int Object_000E45D0::func_000E4370()
{
    func_001BA9C0();
    func_001BAAA0(&position.x);
    func_001BB330(angles.y + 0x8000);
    func_001BB2E0(angles.x);
    func_001BB380(angles.z);
    model->object->func_00047970(0, 0);
    model->object->func_000480C0(2);
    Vector3 muzzle;
    func_001BAB20(&muzzle, 0);
    Vector3 offset;
    func_0014C4C0(&offset, &target_0cc, &muzzle);
    if (owner->func_000C5B70(effect)) {
        owner->func_000C5B40(effect, &muzzle);
    } else {
        effect = owner->func_000C5B10(0x14, &muzzle);
    }
    func_001BB5E0();
    func_001BAC00(&offset, &offset);
    func_001BAA50();
    int angle;
    if (offset.y > 0.0f) {
        angle = func_0014C7D0(offset.y, func_0014C820(offset.x * offset.x + offset.z * offset.z));
        if (angle > 0x2000) {
            angle = 0x2000;
        }
    } else if (offset.y < 0.0f) {
        angle = func_0014C7D0(offset.y, func_0014C820(offset.x * offset.x + offset.z * offset.z));
        if (angle < -0x2000) {
            angle = -0x2000;
        }
    } else {
        angle = 0;
    }
    pitch = data_00257CE8->func_000C1450(pitch, angle, value_144);
    int heading = (short)(func_0014C7D0(offset.x, offset.z) - 0x8000);
    yaw = (short)data_00257CE8->func_000C1450(yaw, heading, value_144);
    return heading - yaw;
}
