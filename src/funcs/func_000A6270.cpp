struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};
extern Game *data_0022FCE0;

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
void func_001BAA00();
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB380(int angle);
void func_001BB5E0();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();
int func_0014C7D0(float x, float z);

// The player the rig follows: position at 0xca4, its angles at 0xcbc/0xcc4, their copies at 0xcc8/0xcd0 and the
// heading at 0xe0c.
struct Player_000A6270 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0xc];
    int pitch;
    char unknown_cc0[4];
    int yaw;
    int pitch_cc8;
    char unknown_ccc[4];
    int yaw_cd0;
    int unknown_cd4;
    char unknown_cd8[4];
    int unknown_cdc;
    char unknown_ce0[0x12c];
    int heading;
};

// The camera rig (Object_000A6980's layout): the values at 0x8b4/0x8b8 and its target at 0x8d4.
struct Object_000A6340 {
    char unknown_000[0x8b4];
    int first;
    int second;
    char unknown_8bc[0x18];
    int target_id;

    void func_000A6270(Vector3 *target, int first, int second);
};

// Keeps the two values at 0x8b4/0x8b8 and turns the target's player to face the point: the offset from the player
// to it, through the matrix of the player's angles (func_001BB2E0/func_001BB380, func_001BB5E0), gives the heading
// at 0xe0c (func_0014C7D0); the angles are copied to 0xcc8/0xcd0 and 0xcd4/0xcdc cleared.
void Object_000A6340::func_000A6270(Vector3 *target, int first, int second)
{
    this->first = first;
    this->second = second;
    Player_000A6270 *player = (Player_000A6270 *)data_0022FCE0->func_000128C0(target_id);
    if (player) {
        Vector3 offset;
        func_0014C4C0(&offset, target, &player->position);
        func_001BAA00();
        func_001BB2E0(player->pitch);
        func_001BB380(player->yaw);
        func_001BB5E0();
        Vector3 local;
        func_001BAC00(&local, &offset);
        func_001BAA50();
        player->heading = func_0014C7D0(local.x, local.z);
        player->pitch_cc8 = player->pitch;
        player->yaw_cd0 = player->yaw;
        player->unknown_cd4 = 0;
        player->unknown_cdc = 0;
    }
}
