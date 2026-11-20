struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
void func_0005E7B0(void *target, int first, int second, int third, int fourth);

struct Set_000D8A40 {
    Motion_0005F060 *motions[32];
};

struct Model_000D8A40 {
    int unknown_00;
    int unknown_04;
    void *target;
};

struct Holder_000D8A40 {
    Model_000D8A40 *model;
};

struct Owner_000D9A90 {
    char unknown_00[0x44];
    float x;
    float y;
    float z;
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Owner_000D9A90 *owner;
    char unknown_008[0x28];
    float x;
    float y;
    float z;
    char unknown_03c[0x68];
    Holder_000D8A40 *holder;
    char unknown_0a8[0x8];
    Set_000D8A40 *set;
    Motion_0005F060 *motion;
    int blend_handle;
    char unknown_0bc[0x4];
    int value_c0;
    char unknown_0c4[0x4];
    int handle_c8;
    float time;
    float time_d0;
    char unknown_0d4[0x4];
    float weight;
    float blend;
    int next;
    char unknown_0e4[0x4];
    int phase;

    void func_000D9A90();
};

// A handler of the table at 0x2173C0: blends the model's handle at 0xc8 in (func_0005E7B0) and starts motion 16
// at time 0 with a blend of 0.8 (phase 1). Then, while the blend is above 0, lowers it by 0.2 (to no less than 0)
// into the weight at 0xd8; once it is gone, drops the blend handle and plays the motion once at half speed. Gives 1
// at 0xe0 while the owner is off both axes.
void Object_000D8A40::func_000D9A90()
{
    if (phase == 0) {
        func_0005E7B0(holder->model->target, handle_c8, 0, value_c0, 0);
        motion = set->motions[16];
        blend_handle = handle_c8;
        blend = 0.8f;
        weight = 0.8f;
        time = 0.0f;
        time_d0 = 0.0f;
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
