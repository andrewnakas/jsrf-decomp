struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
int func_0005E7B0(void *target, int first, int second, int third, int fourth);

struct Set_000DCBC0 {
    Motion_0005F060 *motions[32];
};

struct Model_000DCBC0 {
    int unknown_00;
    int unknown_04;
    void *target;
};

struct Holder_000DCBC0 {
    Model_000DCBC0 *model;
};

// The object a behaviour serves (at 0x4): its speed at 0x5c.
struct Owner_000DCBC0 {
    char unknown_00[0x5c];
    float speed;
};

float func_0014C7F0(float value);

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Owner_000DCBC0 *owner;
    char unknown_008[0x178];
    Holder_000DCBC0 *holder;
    char unknown_184[0xc];
    Set_000DCBC0 *set;
    Motion_0005F060 *motion;
    Motion_0005F060 *blend_motion;
    char unknown_19c[0x4];
    int value_1a0;
    char unknown_1a4[0x4];
    int handle_1a8;
    float time;
    float time_1b0;
    char unknown_1b4[0x4];
    float weight;
    float blend;
    int next;
    char unknown_1c4[0x4];
    int phase;
    float time_1cc;
    float pace;

    void func_000DF570();
};

// Entry 1 of the table at 0x217AB8: blends the model's handle at 0x1a8 in (func_0005E7B0), starts motion 32 at half
// speed and a blend of 0.8 (phase 1). Then, with the owner stopped, clears 0x1c0; while the blend is above 0, lowers it
// by 0.2 (to no less than 0) into the weight at 0x1b8 and plays at 0.35; once it is gone, runs motion 32 blended with
// motion 12 at a pace (0x1d0) that follows the owner's speed times 1.44 (at most 1) by steps of 0.1 and sets the
// playing speed to (pace * 0.3 + 0.7) / 2.
void Object_000DCBC0::func_000DF570()
{
    if (phase == 0) {
        func_0005E7B0(holder->model->target, handle_1a8, 0, value_1a0, 0);
        motion = set->motions[32];
        func_0005E030(motion, &time_1cc, 0.5f, 0);
        time = time_1cc;
        blend = 0.8f;
        weight = 0.8f;
        time_1b0 = 0.0f;
        pace = 0.0f;
        blend_motion = (Motion_0005F060 *)handle_1a8;
        phase++;
        return;
    }
    float speed = owner->speed;
    if (speed == 0.0f) {
        next = 0;
        return;
    }
    if (blend > 0.0f) {
        blend -= 0.2f;
        if (blend < 0.0f) {
            blend = 0.0f;
        }
        weight = blend;
        pace = 0.0f;
        func_0005E030(motion, &time_1cc, 0.35f, 0);
        return;
    }
    motion = set->motions[32];
    blend_motion = set->motions[12];
    time_1b0 = time = time_1cc;
    speed *= 1.44f;
    if (speed > 1.0f) {
        speed = 1.0f;
    }
    float delta = speed - pace;
    if (func_0014C7F0(delta) < 0.1f) {
        pace = speed;
    } else if (delta > 0.0f) {
        pace += 0.1f;
    } else {
        pace -= 0.1f;
    }
    weight = pace;
    func_0005E030(motion, &time_1cc, (weight * 0.3f + 0.7f) * 0.5f, 0);
}
