struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
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
float func_0004A8A0(float from, float to, float rate);

// The camera's offset behind the player (in the player's frame) and the step its turn eases by.
extern Vector3 data_002153A0;
extern int data_002153AC;
// The point the camera circles, in the player's frame.
extern Vector3 data_002153DC;

struct Node {
    Node *func_00011BD0();
};

// The camera's parent (the player): position 0xca4, angles 0xcbc to 0xcc4, a side flag at 0xe00.
struct Player_000A3E50 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0xc];
    int angles[3];
    char unknown_cc8[0x138];
    int side;
};

struct Object_000A4D80 {
    char unknown_000[0xe8];
    float distance;
    char unknown_0ec[0xf8];
    Vector3 target;
    char unknown_1f0[0xc];
    int roll;
    int turn;

    void func_000A3890(Vector3 *out, Vector3 *center);
};

// Puts data_002153DC and data_002153A0 in the player's frame (the second turned half round): the first is the centre,
// the second the point behind. The eye goes around the centre from the target's heading toward the point's by at
// most 0x111 (func_0004A820), at the distance of the point eased from 0xe8 (func_0004A8A0) and kept between 33 and
// 38, at the point's height. 0x200 eases toward data_002153AC and 0x1fc toward +-0x4000 by the player's side, 0xb6 a
// frame each.
void Object_000A4D80::func_000A3890(Vector3 *out, Vector3 *center)
{
    Vector3 offset = data_002153A0;
    int step = data_002153AC;
    Player_000A3E50 *player = (Player_000A3E50 *)((Node *)this)->func_00011BD0();
    func_001BA9C0();
    func_001BAAA0(&player->position.x);
    func_001BB2E0(player->angles[0]);
    func_001BB380(player->angles[2]);
    func_001BB330(player->angles[1] + 0x8000);
    Vector3 point;
    func_001BAB20(&point, &offset);
    func_001BAB20(center, &data_002153DC);
    func_001BAA50();
    int angle = func_0014C7D0(target.x - center->x, target.z - center->z);
    int to = func_0014C7D0(point.x - center->x, point.z - center->z);
    angle = func_0004A820(angle, to, 0x111);
    func_0014CB60(&target, center);
    float range = func_0014CB60(&point, center);
    range = func_0004A8A0(distance, range, 0.46296296f);
    if (range < 33.0f) {
        range = 33.0f;
    } else if (range > 38.0f) {
        range = 38.0f;
    }
    out->x = func_0014C620(angle) * range + center->x;
    out->y = point.y;
    out->z = func_0014C640(angle) * range + center->z;
    turn = func_0004A820(turn, step, 0xb6);
    if (player->side) {
        roll = func_0004A820(roll, 0x4000, 0xb6);
    } else {
        roll = func_0004A820(roll, -0x4000, 0xb6);
    }
}
