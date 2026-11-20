struct Motion_0005F060;

int func_0005E7B0(void *target, int first, int frame, int second, int time);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);

// The body the motions drive.
struct Body_000F0690 {
    char unknown_00[8];
    void *target;
};

struct Holder_000EDC30 {
    Body_000F0690 *body;
};

// The motions: 0 run, 1 overlay, 2 pose, 3 and 4 blends, 5 the special one.
struct Source_000EDC30 {
    Motion_0005F060 *motions[6];
};

struct Owner_000F0690 {
    char unknown_00[0x54];
    int turn;
    char unknown_58[4];
    float speed;
    char unknown_60[0x44];
    unsigned int flags;
};

// The class whose table is at 0x1CEFAC (constructor func_000EDC30); slot 8 (func_000EFB20) calls this.
struct Object_000EDC30 {
    char unknown_000[4];
    Owner_000F0690 *owner;
    char unknown_008[0xd8];
    int turn;
    int lean;
    char unknown_0e8[0xc];
    Holder_000EDC30 *holder;
    Source_000EDC30 *source;
    int handle_0fc;
    float time;
    char unknown_104[0xc];
    float pose;
    float overlay;

    void func_000F0690();
};

// Plays the body's motions: the special one (5) while the owner's state is 0x2000000, else the run (0, at 0.16 of
// the owner's speed) or the pose (2) by the sign of 0x110; then blends in the turn (3) and lean (4) weights and the
// overlay (1) while its time at 0x114 runs. Nothing while the owner's flag 0x100 is set.
void Object_000EDC30::func_000F0690()
{
    if (owner->flags & 0x100) {
        return;
    }
    if (owner->flags == 0x2000000) {
        func_0005E7B0(holder->body->target, handle_0fc, 0, (int)source->motions[5], *(int *)&time);
        func_0005E030(source->motions[5], &time, 0.5f, 1);
    } else if (pose < 0.0f) {
        float speed = owner->speed * 0.16f;
        func_0005E030(source->motions[0], &time, speed, 0);
        func_0005E7B0(holder->body->target, handle_0fc, 0, (int)source->motions[0], *(int *)&time);
    } else {
        func_0005E7B0(holder->body->target, handle_0fc, 0, (int)source->motions[2], *(int *)&pose);
    }
    int value = turn;
    if (value != owner->turn) {
        func_0005EAF0(holder->body->target, (Motion_0005F060 *)handle_0fc, 0.0f, (Motion_0005F060 *)handle_0fc, 0.0f,
                      source->motions[3], value * 3.0517578e-05f + 1.0f);
    }
    value = lean;
    if (value) {
        float weight;
        if (value < 0) {
            weight = value * 0.001447178f + 1.0f;
            if (weight < 0.0f) {
                weight = 0.0f;
            }
        } else {
            weight = value * 0.00036630037f + 1.0f;
            if (weight > 2.0f) {
                weight = 2.0f;
            }
        }
        func_0005EAF0(holder->body->target, (Motion_0005F060 *)handle_0fc, 0.0f, (Motion_0005F060 *)handle_0fc, 0.0f,
                      source->motions[4], weight);
    }
    if (overlay >= 0.0f) {
        func_0005EAF0(holder->body->target, (Motion_0005F060 *)handle_0fc, 0.0f, (Motion_0005F060 *)handle_0fc, 0.0f,
                      source->motions[1], overlay);
        func_0005E030(source->motions[1], &overlay, 0.5f, 1);
    }
}
