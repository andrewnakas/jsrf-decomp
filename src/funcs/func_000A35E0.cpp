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

int func_0004A7F0(int first, int second);

// The camera's points in the player's frame: behind (on foot), beside (while 0xe04 is set), the centres for each
// and the step the turn eases by.
extern Vector3 data_002153B0;
extern Vector3 data_002153BC;
extern Vector3 data_002153C8;
extern int data_002153D4;
extern Vector3 data_002153DC;

#define ABS(x) ((x) < 0 ? -(x) : (x))

struct Node {
    Node *func_00011BD0();
};

// The camera's parent (the player): position 0xca4, angles 0xcbc to 0xcc4, a side flag at 0xe00.
struct Player_000A3E50 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0xc];
    int angles[3];
    char unknown_cc8[0x13c];
    int turning;
    int heading;
    char unknown_e0c[0x314];
    int lean;
    char unknown_1124[0x24];
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

    void func_000A35E0(Vector3 *out, Vector3 *center);
};

// Like func_000A3890, with data_002153B0 behind and data_002153DC as the centre; while the player turns (0xe04) the
// frame is turned by 0xe08 only, the point is data_002153BC put 15 to the side of 0x1148 and 35 up (20 down when
// 0x1120 is not negative) around data_002153C8, and the turn goes by 0x555 when over 0x1555 off, else 0x222. 0x200
// eases toward data_002153D4 and 0x1fc toward 0, 0xb6 a frame each.
void Object_000A4D80::func_000A35E0(Vector3 *out, Vector3 *center)
{
    int step = data_002153D4;
    Player_000A3E50 *player = (Player_000A3E50 *)((Node *)this)->func_00011BD0();
    func_001BA9C0();
    func_001BAAA0(&player->position.x);
    Vector3 point;
    int angle;
    if (player->turning) {
        func_001BB330(player->heading);
        Vector3 offset = data_002153BC;
        if (player->lean < 0) {
            offset.y = 35.0f;
        } else {
            offset.y = -20.0f;
        }
        if (player->side) {
            offset.x = 15.0f;
        } else {
            offset.x = -15.0f;
        }
        func_001BAB20(&point, &offset);
        func_001BAB20(center, &data_002153C8);
        int from = func_0014C7D0(target.x - center->x, target.z - center->z);
        int to = func_0014C7D0(point.x - center->x, point.z - center->z);
        if (ABS(func_0004A7F0(from, to)) > 0x1555) {
            angle = func_0004A820(from, to, 0x555);
        } else {
            angle = func_0004A820(from, to, 0x222);
        }
    } else {
        func_001BB2E0(player->angles[0]);
        func_001BB380(player->angles[2]);
        func_001BB330(player->angles[1] + 0x8000);
        func_001BAB20(&point, &data_002153B0);
        func_001BAB20(center, &data_002153DC);
        angle = func_0014C7D0(target.x - center->x, target.z - center->z);
        int to = func_0014C7D0(point.x - center->x, point.z - center->z);
        angle = func_0004A820(angle, to, 0x111);
    }
    func_001BAA50();
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
    roll = func_0004A820(roll, 0, 0xb6);
}
