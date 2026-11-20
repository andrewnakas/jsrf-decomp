struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Object_000C1440 {
    int func_000C1440(int from, int to);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1440.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;

struct Owner_000D9A10 {
    char unknown_00[0x54];
    int angle;
};

struct Set_000D8A40 {
    Motion_0005F060 *motions[32];
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Owner_000D9A10 *owner;
    char unknown_008[0x5c];
    int angle;
    char unknown_068[0x48];
    Set_000D8A40 *set;
    char unknown_0b4[0x8];
    Motion_0005F060 *turn;
    char unknown_0c0[0x14];
    float turn_last;
    char unknown_0d8[0x1c];
    float turn_time;

    void func_000D9A10();
};

// Turns toward the owner's angle at 0x54: with no difference from the angle at 0x64 clears the turn motion (0xbc);
// otherwise takes motion 15 (difference above 0) or 14 (below), keeps the previous turn time at 0xd4 and plays the
// motion on from the time at 0xf4 at half speed, without looping.
void Object_000D8A40::func_000D9A10()
{
    int difference = data_00257CE8->func_000C1440(angle, owner->angle);
    if (difference != 0) {
        if (difference >= 0) {
            turn = set->motions[15];
        } else {
            turn = set->motions[14];
        }
        turn_last = turn_time;
        func_0005E030(turn, &turn_time, 0.5f, 0);
    } else {
        turn = 0;
    }
}
