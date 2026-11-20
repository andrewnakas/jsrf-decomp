struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
int func_0014C7D0(float x, float z);
float __fastcall func_0014CB60(const Vector3 *from, const Vector3 *to);

// The point in front of the player that the camera looks at, in the player's frame.
extern Vector3 data_00215418;

struct Node {
    Node *func_00011BD0();
};

// The camera's parent (the player): position 0xca4, angles 0xcbc and 0xcc4, heading 0x1164.
struct Player_000A3E50 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0xc];
    int angles[3];
    char unknown_cc8[0x49c];
    int heading;
};

struct Object_000A4D80 {
    char unknown_000[0x114];
    int angle;
    int target_angle;
    float height;
    float target_height;
    float distance;
    float target_distance;
    int value_12c;
    char unknown_130[0xdc];
    Vector3 eye;

    void func_000A3E50();
};

// A handler of the member-function table at 0x215534: finds the point data_00215418 in the player's frame and keeps
// the headings (func_0014C7D0), heights and distances from the player of the eye at 0x20c and of that point.
void Object_000A4D80::func_000A3E50()
{
    Player_000A3E50 *player = (Player_000A3E50 *)((Node *)this)->func_00011BD0();
    func_001BAA00();
    func_001BAAA0(&player->position.x);
    func_001BB2E0(player->angles[0]);
    func_001BB380(player->angles[2]);
    func_001BB330(player->heading + 0x8000);
    Vector3 point;
    func_001BAB20(&point, &data_00215418);
    func_001BAA50();
    Vector3 fromEye;
    fromEye.x = eye.x - player->position.x;
    fromEye.z = eye.z - player->position.z;
    Vector3 fromPoint;
    fromPoint.x = point.x - player->position.x;
    fromPoint.z = point.z - player->position.z;
    angle = func_0014C7D0(fromEye.x, fromEye.z);
    target_angle = func_0014C7D0(fromPoint.x, fromPoint.z);
    height = eye.y - player->position.y;
    target_height = point.y - player->position.y;
    distance = func_0014CB60(&player->position, &eye);
    target_distance = func_0014CB60(&player->position, &point);
    value_12c = 0;
}
