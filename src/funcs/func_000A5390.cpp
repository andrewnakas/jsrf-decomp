struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
int func_0014C7D0(float x, float z);
float __fastcall func_0014CB60(const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C620(int angle);
float __fastcall func_0014C640(int angle);
int func_0004A820(int from, int to, int step);
void func_001BB650(float distance);

int func_0004A7F0(int first, int second);

// The eye's and the focus's points (on the floor plane) in the frame that looks at the player's spot, and the step
// the turn eases by.
extern Vector3 data_002153E8;
extern Vector3 data_002153F4;
extern int data_002153D4;

#define ABS(x) ((x) < 0 ? -(x) : (x))

struct Node {
    Node *func_00011BD0();
};

// The camera's parent (the player): position 0xca4, the spot it looks at 0xfdc.
struct Player_000A5390 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0x32c];
    Vector3 spot;
};

struct Object_000A4D80 {
    char unknown_000[0xec];
    int yaw;
    char unknown_0f0[0x10c];
    int roll;
    int turn;

    void func_000A5390(Vector3 *eye, Vector3 *focus);
};

// Turns 0xec toward the heading from the player to the spot at 0xfdc (within 0x71c of it, 0x222 a frame),
// and places the eye and the focus at data_002153E8 and data_002153F4 (heights cleared) in the frame at the player
// turned by it; their heights come from the same points in that frame pitched by the angle the spot is below the
// player plus 18, less 0x38e and kept within 0x2aaa (0 when smaller). 0x200 eases toward data_002153D4 and 0x1fc
// toward 0, 0xb6 a frame each.
void Object_000A4D80::func_000A5390(Vector3 *eye, Vector3 *focus)
{
    int step = data_002153D4;
    Player_000A5390 *player = (Player_000A5390 *)((Node *)this)->func_00011BD0();
    Player_000A5390 *owner = (Player_000A5390 *)((Node *)this)->func_00011BD0();
    int heading = func_0014C7D0(owner->spot.x - owner->position.x, owner->spot.z - owner->position.z);
    int difference = func_0004A7F0(yaw, heading);
    if (difference < -0x71c) {
        int next = yaw - 0x222;
        int rest = func_0004A7F0(next, heading);
        if (rest < -0x71c) {
            yaw = next;
        } else {
            yaw = rest + next + 0x71c;
        }
    }
    if (difference > 0x71c) {
        int next = yaw + 0x222;
        int rest = func_0004A7F0(next, heading);
        if (rest > 0x71c) {
            yaw = next;
        } else {
            yaw = rest + next - 0x71c;
        }
    }
    Vector3 first = data_002153E8;
    first.y = 0.0f;
    Vector3 second = data_002153F4;
    second.y = 0.0f;
    func_001BAA00();
    func_001BAAA0(&player->position.x);
    func_001BB330(yaw);
    Vector3 eyePoint;
    Vector3 focusPoint;
    func_001BAB20(&eyePoint, &first);
    func_001BAB20(&focusPoint, &second);
    func_001BAA50();
    eye->x = eyePoint.x;
    eye->z = eyePoint.z;
    focus->x = focusPoint.x;
    focus->z = focusPoint.z;
    float distance = func_0014CB60(&player->position, &player->spot);
    int pitch = func_0014C7D0(data_002153E8.y + player->position.y - player->spot.y, distance);
    if (ABS(pitch) < 0x38e) {
        pitch = 0;
    } else {
        if (pitch > 0) {
            pitch -= 0x38e;
            if (pitch > 0x2aaa) {
                pitch = 0x2aaa;
            }
        }
        if (pitch < 0) {
            pitch += 0x38e;
            if (pitch < -0x2aaa) {
                pitch = -0x2aaa;
            }
        }
    }
    func_001BAA00();
    func_001BAAA0(&player->position.x);
    func_001BB650(data_002153E8.y);
    func_001BB2E0(pitch);
    func_001BAB20(&eyePoint, &first);
    func_001BAB20(&focusPoint, &second);
    func_001BAA50();
    eye->y = eyePoint.y;
    focus->y = focusPoint.y;
    turn = func_0004A820(turn, step, 0xb6);
    roll = func_0004A820(roll, 0, 0xb6);
}
