struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
float func_0014C7F0(float value);

struct Set_000DCBC0 {
    Motion_0005F060 *motions[32];
};

struct Owner_000DCBC0 {
    char unknown_00[0x5c];
    float speed;
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Owner_000DCBC0 *owner;
    char unknown_008[0x188];
    Set_000DCBC0 *set;
    Motion_0005F060 *motion;
    Motion_0005F060 *blend_motion;
    char unknown_19c[0x10];
    float time;
    float time_1b0;
    char unknown_1b4[0x4];
    float weight;
    char unknown_1bc[0x10];
    float run_time;
    float pace;

    void func_000E0000();
};

// Runs with motion 32 blended with motion 12, both from the time at 0x1cc: the blend weight at 0x1d0 (copied to
// 0x1b8) follows the owner's speed (0x5c) times 1.44, at most 1, by 0.1 a frame at most; then steps motion 32 at
// half speed.
void Object_000DCBC0::func_000E0000()
{
    float speed = owner->speed;
    motion = set->motions[32];
    blend_motion = set->motions[12];
    time_1b0 = time = run_time;
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
    func_0005E030(set->motions[32], &run_time, 0.5f, 0);
}
