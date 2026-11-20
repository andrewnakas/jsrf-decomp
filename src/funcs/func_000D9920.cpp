struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
float func_0014C7F0(float value);

struct Set_000D8A40 {
    Motion_0005F060 *motions[32];
};

struct Owner_000D9920 {
    char unknown_00[0x5c];
    float speed;
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Owner_000D9920 *owner;
    char unknown_008[0xa8];
    Set_000D8A40 *set;
    Motion_0005F060 *motion;
    Motion_0005F060 *blend_motion;
    char unknown_0bc[0x10];
    float time;
    float time_d0;
    char unknown_0d4[0x4];
    float weight;
    char unknown_0dc[0x18];
    float turn_time;
    float pace;

    void func_000D9920();
};

// Runs with motion 22 blended with motion 6, both from the time at 0xf4: the blend weight at 0xf8 (copied to 0xd8)
// follows the owner's speed (0x5c) times 1.44, at most 1, by 0.1 a frame at most; then steps motion 22 at 0.6.
void Object_000D8A40::func_000D9920()
{
    float speed = owner->speed;
    motion = set->motions[22];
    blend_motion = set->motions[6];
    time_d0 = time = turn_time;
    float target = speed * 1.44f;
    if (target > 1.0f) {
        target = 1.0f;
    }
    float delta = target - pace;
    if (func_0014C7F0(delta) < 0.1f) {
        pace = target;
    } else if (delta > 0.0f) {
        pace += 0.1f;
    } else {
        pace -= 0.1f;
    }
    weight = pace;
    func_0005E030(set->motions[22], &turn_time, 0.6f, 0);
}
