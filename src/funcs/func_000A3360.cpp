struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void func_001BAA60(float x, float y, float z);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB380(int angle);
float __fastcall func_0014CB60(const Vector3 *from, const Vector3 *to);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
int func_0004A820(int from, int to, int step);

struct Node {
    Node *func_00011BD0();
};

// The camera's parent (the player): position 0xca4, angles 0xcbc to 0xcc4, the floor's height at 0xdfc.
struct Player_000A3E50 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0xc];
    int angles[3];
    char unknown_cc8[0x134];
    float floor;
};

struct Object_000A4D80 {
    char unknown_000[0x1e4];
    Vector3 target;
    char unknown_1f0[0xc];
    int roll;
    int turn;

    void func_000A3360(Vector3 *eye, Vector3 *focus);
};

// Keeps the camera on the line from the player to the target at 0x1e4, 33 to 38 from the player: the eye there
// and the focus 38 nearer, both at the player's height (or the floor's when the player is 5 above it) turned by the
// player's yaw and pitch, the eye 18 and the focus 14 higher (more by how far the player is above the floor plus 20
// or 10). 0x200 eases toward 0x3555 and 0x1fc toward 0, 0xb6 a frame each.
void Object_000A4D80::func_000A3360(Vector3 *eye, Vector3 *focus)
{
    Player_000A3E50 *player = (Player_000A3E50 *)((Node *)this)->func_00011BD0();
    float height;
    if (player->position.y + 5.0f < player->floor) {
        height = player->position.y;
    } else {
        height = player->floor;
    }
    float distance = func_0014CB60(&target, &player->position);
    if (distance > 38.0f) {
        distance = 38.0f;
    } else if (distance < 33.0f) {
        distance = 33.0f;
    }
    Vector3 direction;
    direction.x = target.x - player->position.x;
    direction.y = 0.0f;
    direction.z = target.z - player->position.z;
    func_0014C410(&direction, &direction);
    Vector3 away;
    away.x = direction.x * distance + player->position.x;
    away.z = direction.z * distance + player->position.z;
    Vector3 close;
    close.x = away.x - direction.x * 38.0f;
    close.z = away.z - direction.z * 38.0f;
    Vector3 offset;
    Vector3 point;
    float above = player->position.y - (player->floor + 20.0f);
    if (above > 0.0f) {
        offset.y = above + 18.0f;
    } else {
        offset.y = 18.0f;
    }
    offset.x = 0.0f;
    offset.z = 0.0f;
    func_001BA9C0();
    func_001BAA60(player->position.x, height, player->position.z);
    func_001BB2E0(player->angles[0]);
    func_001BB380(player->angles[2]);
    func_001BAB20(&point, &offset);
    func_001BAA50();
    eye->x = away.x;
    eye->y = point.y;
    eye->z = away.z;
    above = player->position.y - (player->floor + 10.0f);
    if (above > 0.0f) {
        offset.y = above + 14.0f;
    } else {
        offset.y = 14.0f;
    }
    offset.x = 0.0f;
    offset.z = 0.0f;
    func_001BA9C0();
    func_001BAA60(player->position.x, height, player->position.z);
    func_001BB2E0(player->angles[0]);
    func_001BB380(player->angles[2]);
    func_001BAB20(&point, &offset);
    func_001BAA50();
    focus->x = close.x;
    focus->y = point.y;
    focus->z = close.z;
    turn = func_0004A820(turn, 0x3555, 0xb6);
    roll = func_0004A820(roll, 0, 0xb6);
}
