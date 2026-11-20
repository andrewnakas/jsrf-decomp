struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

// The object behind id 0x2c: a position at 0xca4, values at 0xcd4, 0xdf4 and 0xe50 and a vector at 0xde8.
struct Object_000A1C50 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0x24];
    int value_cd4;
    char unknown_cd8[0x110];
    Vector3 vector_de8;
    int value_df4;
    char unknown_df8[0x58];
    int value_e50;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000BFF60 {
    int func_000BFF80(Vector3 *position);
};

extern Object_000BFF60 *data_00257CE0;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

// The object in data_00257CE4: the box at 0, the point at 0x7c with the two before it, a motion at 0xd0.
struct Object_000C1270 {
    int box;
    char unknown_04[0x78];
    Vector3 point;
    Vector3 point_88;
    Vector3 point_94;
    Vector3 point_a0;
    int value_ac;
    int value_b0;
    int value_b4;
    Vector3 vector_b8;
    int value_c4;
    char unknown_c8[8];
    Motion_0005F060 *motion;
    float time;

    void func_000C0F70();
    void func_000C1050();
};

// Follows object 0x2c: shifts the points (0x7c to 0x88 to 0x94, the old 0x88 also to 0xa0), takes its position as
// the point, keeps the old 0xac at 0xb0, copies its values 0xe50, 0xcd4, 0xde8 and 0xdf4, and takes the box under it
// (func_000BFF80 of data_00257CE0); without it the box is -1. Then the motion steps at half speed (func_0005E030) and
// func_000C0F70 runs.
void Object_000C1270::func_000C1050()
{
    Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(0x2c);
    if (player) {
        point_94 = point_88;
        point_88 = point;
        point = player->position;
        point_a0 = point_94;
        value_b0 = value_ac;
        value_ac = player->value_e50;
        value_b4 = player->value_cd4;
        vector_b8 = player->vector_de8;
        value_c4 = player->value_df4;
        box = data_00257CE0->func_000BFF80(&player->position);
    } else {
        box = -1;
    }
    func_0005E030(motion, &time, 0.5f, 0);
    func_000C0F70();
}
