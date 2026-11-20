struct Vector3 {
    float x;
    float y;
    float z;
};

int func_0004A7F0(int first, int second);
void func_001BA9C0();
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void func_001BB670(float angle);

// The offset of the camera's focus from the player.
extern Vector3 data_0021543C;

struct Node {
    Node *func_00011BD0();
};

// The player (only the fields used here).
struct Object_000A1C50 {
    char unknown_0000[0xca4];
    Vector3 position;
    char unknown_0cb0[0x4a0];
    int yaw;
    int pitch;
};

// The camera (only the fields this handler uses).
struct Object_000A4D80 {
    char unknown_000[0xf8];
    int yaw;
    int pitch;
    int turnFrom;
    int turnTo;
    float distanceFrom;
    float distanceTo;
    float time;
    char unknown_114[0xd0];
    Vector3 target;
    Vector3 anchor;
    char unknown_1fc[0x10];
    Vector3 eye;
    Vector3 focus;

    void func_000A44E0();
};

// A handler (entry 7) of the member-function table at data_002155AC: eases (1 - (1 - t)^2 of the time at 0x110, which
// runs up by 1/60 to 1) the turn from 0x100 toward 0x104 and the distance from 0x108 toward 0x10c. The focus at
// 0x218 is data_0021543C in the player's frame (position, yaw 0x1150, pitch 0x1154); the eye at 0x20c is that far
// back from it, turned by 0xf8, 0xfc and the eased turn. Copies the eye to 0x1e4 and the focus to 0x1f0.
void Object_000A4D80::func_000A44E0()
{
    Object_000A1C50 *player = (Object_000A1C50 *)((Node *)this)->func_00011BD0();
    float rest = 1.0f - time;
    float ease = 1.0f - rest * rest;
    int turn = (int)(func_0004A7F0(turnFrom, turnTo) * ease) + turnFrom;
    float distance = (distanceTo - distanceFrom) * ease + distanceFrom;
    func_001BAA00();
    func_001BAAA0(&player->position.x);
    func_001BA9C0();
    func_001BB2E0(player->yaw);
    func_001BB380(player->pitch);
    func_001BAB20(&focus, &data_0021543C);
    func_001BAA50();
    func_001BA9C0();
    func_001BB2E0(yaw);
    func_001BB380(pitch);
    func_001BB330(turn);
    func_001BB670(distance);
    func_001BAB20(&eye, 0);
    func_001BAA50();
    func_001BAA50();
    time += 0.016666668f;
    if (time > 1.0f) {
        time = 1.0f;
    }
    target = eye;
    anchor = focus;
}
