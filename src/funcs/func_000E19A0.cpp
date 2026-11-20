struct Motion_0005F060;

void func_0005E7B0(void *target, int first, int second, int third, int fourth);
void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *third, float thirdTime);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

// The model (0x8: the target the motions pose).
struct Model_000E19A0 {
    char unknown_00[8];
    void *target;
};

// The models at 0xb8.
struct Holder_000E19A0 {
    Model_000E19A0 *models[1];
};

// The owner at 0x4: flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000E0440 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0x90];
    int count;
    char unknown_09c[0x1c];
    Holder_000E19A0 *holder;
    Motion_0005F060 **motions;
    Motion_0005F060 *block;
    Motion_0005F060 *blend;
    float blendTime;
    float time;
    float time_d0;

    void func_000E19A0();
};

// Unless the owner has flag 0x100: poses model 0 with motion 0 at the time at 0xcc (blended from the motion at 0xc4
// when there is one) and advances it at half speed (func_0005E030); with the owner's flag 0x2000000 motion 1 at 0xd0
// too; and while the count at 0x98 is above 0 motion 2 with the weight count / 8192 (at most 1).
void Object_000E0440::func_000E19A0()
{
    if (owner->flags & 0x100) {
        return;
    }
    if (!blend) {
        func_0005E7B0(holder->models[0]->target, (int)block, 0, (int)motions[0], *(int *)&time);
    } else {
        func_0005EAF0(holder->models[0]->target, block, 0.0f, blend, blendTime, motions[0], time);
    }
    func_0005E030(motions[0], &time, 0.5f, 0);
    if (owner->flags & 0x2000000) {
        func_0005EAF0(holder->models[0]->target, block, 0.0f, block, 0.0f, motions[1], time_d0);
        func_0005E030(motions[1], &time_d0, 0.5f, 0);
    }
    int frames = count;
    if (frames > 0) {
        float weight = frames * 0.00012207031f;
        if (weight > 1.0f) {
            weight = 1.0f;
        }
        func_0005EAF0(holder->models[0]->target, block, 0.0f, block, 0.0f, motions[2], weight);
    }
}
