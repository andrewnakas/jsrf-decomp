struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
void func_0005E7B0(void *target, int first, int second, int third, int fourth);

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

struct Owner_000DCBC0 {
    char unknown_00[0x44];
    float x;
    float y;
    float z;
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Owner_000DCBC0 *owner;
    char unknown_008[0x13c];
    float x;
    float y;
    float z;
    char unknown_150[0x30];
    Holder_000DCBC0 *holder;
    char unknown_184[0xc];
    Set_000DCBC0 *set;
    Motion_0005F060 *motion;
    int blend_handle;
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

    void func_000DF450();
};

// A handler of the table at 0x217A20: blends the model's handle at 0x1a8 in (func_0005E7B0) and starts motion 19
// at time 0 with a blend of 0.8 (phase 1). Then, while the blend is above 0, lowers it by 0.2 (to no less than 0)
// into the weight at 0x1b8; once it is gone, drops the blend handle and plays the motion once at half speed. Gives
// 1 at 0x1c0 while the owner is off both axes from the point at 0x144.
void Object_000DCBC0::func_000DF450()
{
    if (phase == 0) {
        func_0005E7B0(holder->model->target, handle_1a8, 0, value_1a0, 0);
        motion = set->motions[19];
        blend_handle = handle_1a8;
        blend = 0.8f;
        weight = 0.8f;
        time = 0.0f;
        time_1b0 = 0.0f;
        phase++;
        return;
    }
    if (blend <= 0.0f) {
        blend_handle = 0;
        func_0005E030(motion, &time, 0.5f, 0);
    } else {
        blend -= 0.2f;
        if (blend < 0.0f) {
            blend = 0.0f;
        }
        weight = blend;
    }
    if ((owner->z - z) * (owner->x - x) != 0.0f) {
        next = 1;
    }
}
