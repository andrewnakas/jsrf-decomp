struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
int func_0005E7B0(void *target, int first, int second, int third, int fourth);

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

struct Owner_000D9BA0 {
    char unknown_00[0x5c];
    float speed;
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Owner_000D9BA0 *owner;
    char unknown_008[0x9c];
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
    char unknown_0ec[0x8];
    float turn_time;
    float value_f8;

    void func_000D9920();
    void func_000D9BA0();
};

// A handler of the table at 0x2173C0: blends the model's handle at 0xc8 in (func_0005E7B0), takes motion 22 and
// steps it once at half speed from the time at 0xf4 (kept at 0xcc), with a blend of 0.8 (phase 1). Then gives 0 at
// 0xe0 when the owner's value at 0x5c is 0; otherwise, while the blend is above 0, lowers it by 0.2 (to no less
// than 0) into the weight at 0xd8 and plays the motion at 0.35, and once it is gone goes on with func_000D9920.
void Object_000D8A40::func_000D9BA0()
{
    if (phase == 0) {
        func_0005E7B0(holder->model->target, handle_c8, 0, value_c0, 0);
        motion = set->motions[22];
        func_0005E030(motion, &turn_time, 0.5f, 0);
        time = turn_time;
        blend_handle = handle_c8;
        blend = 0.8f;
        weight = 0.8f;
        time_d0 = 0.0f;
        value_f8 = 0.0f;
        phase++;
        return;
    }
    if (owner->speed == 0.0f) {
        next = 0;
        return;
    }
    if (blend > 0.0f) {
        blend -= 0.2f;
        if (blend < 0.0f) {
            blend = 0.0f;
        }
        weight = blend;
        value_f8 = 0.0f;
        func_0005E030(motion, &turn_time, 0.35f, 0);
        return;
    }
    func_000D9920();
}
