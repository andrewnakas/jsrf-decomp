struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C3BE0 {
    int x;
    int y;
    int z;
};

struct Direction_000C3BE0 {
    Vector3 vector;
    float unknown_0c;
};

// A player (objects 0x2c to 0x4b): position 0xca4, angles 0xcbc, the value at 0xcd4.
struct Player_000C3BE0 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0xc];
    Angles_000C3BE0 angles;
    char unknown_cc8[0xc];
    float value_cd4;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);

struct Object_000C3BE0 {
    virtual ~Object_000C3BE0() {}

    unsigned int count;
    Vector3 points[4];
    float ranges[4];
    Angles_000C3BE0 angles[4];
    Direction_000C3BE0 directions[4];

    void func_000C3BE0();
};

// Takes the position, the value at 0xcd4 and the angles of each player 0x2c..0x4b in turn, turns (0, 0, 1) by
// the angles into the direction, and stops after four.
void Object_000C3BE0::func_000C3BE0()
{
    count = 0;
    for (int id = 0x2c; id <= 0x4b; id++) {
        Player_000C3BE0 *player = (Player_000C3BE0 *)data_0022FCE0->func_000128C0(id);
        if (player != 0) {
            points[count] = player->position;
            ranges[count] = player->value_cd4;
            Angles_000C3BE0 *source = &player->angles;
            angles[count] = *source;
            func_001BAA00();
            Direction_000C3BE0 forward;
            forward.vector.x = 0.0f;
            forward.vector.y = 0.0f;
            forward.vector.z = 1.0f;
            forward.unknown_0c = 0.0f;
            func_001BB2E0(source->x);
            func_001BB380(player->angles.z);
            func_001BB330(player->angles.y);
            func_001BAC00(&directions[count].vector, &forward.vector);
            func_001BAA50();
        }
        if (++count >= 4) {
            break;
        }
    }
}
