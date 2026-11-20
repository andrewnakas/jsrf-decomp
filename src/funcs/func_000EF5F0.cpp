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

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;

// The body at 0x4: position at 0x44, angles at 0x50.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;

    int func_000C5B10(int message, void *data);
    void func_000C5B40(int id, void *position);
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);
};

int func_0014C7D0(float first, float second);
float func_0014C820(float value);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void func_001BB5E0();

struct Object_000EDC30 {
    char unknown_000[4];
    Object_000C5B50 *body;
    char unknown_008[0xd8];
    int yaw;
    int pitch;
    char unknown_0e8[0x2d4];
    int effect;

    void func_000EF5F0();
};

// Aims at the object at data_00257CE4 from the point 18 above the body (turned with it): the offset, through the
// inverse of the body's matrix, gives a yaw that the angle at 0xe0 turns towards by 0x3c (func_000C1450) while it is
// off, keeping effect 0x28 (0x3bc) running at the body, or stops that effect once on target; the pitch (at most
// 0xaaa up and 0x2b3 down) turns the angle at 0xe4 the same way.
void Object_000EDC30::func_000EF5F0()
{
    Vector3 point;
    point.x = 0.0f;
    point.y = 18.0f;
    point.z = 0.0f;
    func_001BAA00();
    func_001BAAA0(&body->position.x);
    func_001BB330(body->angles.y + 0x8000);
    func_001BB2E0(body->angles.x);
    func_001BB380(body->angles.z);
    func_001BAB20(&point, &point);
    Vector3 offset;
    func_0014C4C0(&offset, &data_00257CE4->position, &point);
    func_001BB5E0();
    func_001BAC00(&offset, &offset);
    func_001BAA50();
    int heading = (short)(func_0014C7D0(offset.x, offset.z) - 0x8000);
    if (heading != yaw) {
        yaw = (short)data_00257CE8->func_000C1450(yaw, heading, 0x3c);
        if (body->func_000C5B70(effect)) {
            body->func_000C5B40(effect, &body->position);
        } else {
            effect = body->func_000C5B10(0x28, &body->position);
        }
    } else {
        body->func_000C5B50(&effect);
    }
    int angle;
    if (offset.y > 0.0f) {
        angle = func_0014C7D0(offset.y, func_0014C820(offset.z * offset.z + offset.x * offset.x));
        if (angle > 0xaaa) {
            angle = 0xaaa;
        }
    } else if (offset.y < 0.0f) {
        angle = func_0014C7D0(offset.y, func_0014C820(offset.z * offset.z + offset.x * offset.x));
        if (angle < -0x2b3) {
            angle = -0x2b3;
        }
    } else {
        angle = 0;
    }
    pitch = data_00257CE8->func_000C1450(pitch, angle, 0x3c);
}
