struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// The object above the camera's owner: two stick values at 0x8c8 and 0x8cc.
struct Holder_000A49C0 {
    char unknown_000[0x8c8];
    float stickX;
    float stickY;
};

struct Node {
    char unknown_00[0x24];
    Holder_000A49C0 *parent;

    Node *func_00011BD0();
};

// The camera (only the fields this handler uses).
struct Object_000A4D80 {
    char unknown_000[0x130];
    int yawBase;
    int yaw;
    int pitch;
    float nearDistance;
    float farDistance;
    float time;
    int phase;
    float height;
    int turnX;
    int turnY;
    char unknown_158[0x8c];
    Vector3 target;
    char unknown_1f0[0x1c];
    Vector3 eye;
    Vector3 focus;

    void func_000A49C0();
};

// A handler (entry 14) of the member-function table at data_002155AC. Phase 0 runs the time at 0x144 up by 1/12 to
// 1, then phase 1; phase 1 turns the yaw at 0x134 by the owner's parent's stick x (held within +-0x2aaa, else eased
// back to 0 by 0x13e) and the pitch at 0x138 by its stick y. Then from the focus at 0x218, turned by the pitch and the
// yaw plus 0x130, places the eye at 0x20c that far back (eased from 0x13c to 0x140 by the time) and the target at
// 0x1e4 the height at 0x14c along.
void Object_000A4D80::func_000A49C0()
{
    Holder_000A49C0 *holder = ((Node *)this)->func_00011BD0()->parent;
    switch (phase) {
    case 0:
        time += 0.083333336f;
        if (time > 1.0f) {
            time = 1.0f;
            phase = 1;
        }
        break;
    case 1:
        turnX = (int)(holder->stickX * -318.56668f);
        if (turnX != 0) {
            yaw += turnX;
            if (yaw < -0x2aaa) {
                yaw = -0x2aaa;
            }
            if (yaw > 0x2aaa) {
                yaw = 0x2aaa;
            }
        } else {
            if (yaw > 0) {
                yaw -= 0x13e;
                if (yaw < 0) {
                    yaw = 0;
                }
            }
            if (yaw < 0) {
                yaw += 0x13e;
                if (yaw > 0) {
                    yaw = 0;
                }
            }
        }
        turnY = (int)(holder->stickY * 318.56668f);
        pitch += turnY;
        break;
    }
    float rest = 1.0f - time;
    float distance = (1.0f - rest * rest) * (farDistance - nearDistance) + nearDistance;
    func_001BAA00();
    func_001BAAA0(&focus.x);
    func_001BB330(pitch);
    func_001BB2E0(yaw + yawBase);
    Vector3 offset;
    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = distance;
    func_001BAB20(&eye, &offset);
    offset.z = height;
    func_001BAB20(&target, &offset);
    func_001BAA50();
}
