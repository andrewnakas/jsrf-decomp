struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void func_001BAA50();
void func_001BAA60(float x, float y, float z);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);
int func_0014C7D0(float x, float z);
float func_0014C820(float value);

struct Node {
    Node *func_00011BD0();
};

// The camera's parent (the player): position 0xca4, angles 0xcbc.
struct Player_000A4890 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0xc];
    int angles[3];
};

struct Object_000A4D80 {
    char unknown_000[0x130];
    int pitch;
    int value_134;
    int heading;
    float distance;
    float value_140;
    int value_144;
    int value_148;
    float distance_14c;
    int value_150;
    int value_154;
    char unknown_158[0x8c];
    Vector3 eye;
    Vector3 point_1f0;
    char unknown_1fc[0x1c];
    Vector3 target;

    void func_000A4890();
};

// A handler of the member-function table at 0x215534: takes the point 14 above the player in its frame as the
// target at 0x218 and keeps the pitch and heading from it to the eye at 0x1e4, the eye's distance from it and from
// the point at 0x1f0.
void Object_000A4D80::func_000A4890()
{
    Player_000A4890 *player = (Player_000A4890 *)((Node *)this)->func_00011BD0();
    func_001BAA00();
    func_001BAAA0(&player->position.x);
    func_001BB2E0(player->angles[0]);
    func_001BB380(player->angles[2]);
    func_001BB330(player->angles[1]);
    func_001BAA60(0.0f, 14.0f, 0.0f);
    func_001BAB20(&target, 0);
    func_001BAA50();
    Vector3 offset;
    offset.x = eye.x - target.x;
    offset.y = eye.y - target.y;
    offset.z = eye.z - target.z;
    pitch = func_0014C7D0(offset.y, func_0014C820(offset.x * offset.x + offset.z * offset.z));
    value_134 = 0;
    heading = func_0014C7D0(offset.x, offset.z);
    distance = func_0014C530(&target, &eye);
    value_140 = 1.0f;
    value_144 = 0;
    distance_14c = func_0014C530(&point_1f0, &eye);
    value_148 = 0;
    value_150 = 0;
    value_154 = 0;
}
