struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
float __fastcall func_0014CB60(const Vector3 *a, const Vector3 *b);

struct Set_000D0680 {
    Motion_0005F060 *motions[32];
};

struct Owner_000D0680 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x54];
    unsigned int flags;
};

struct Object_000D0680 {
    char unknown_000[0x4];
    Owner_000D0680 *owner;
    char unknown_008[0x28];
    Vector3 target;
    char unknown_03c[0x1c];
    Set_000D0680 *set_b;
    Motion_0005F060 *motion_b;
    char unknown_060[0x8];
    Set_000D0680 *set;
    Motion_0005F060 *motion;
    Motion_0005F060 *blend;
    char unknown_074[0xc];
    float time;
    float time_84;
    char unknown_088[4];
    float weight;
    float time_90;
    char unknown_094[0x8];
    int phase;

    void func_000D0C10();
};

// A handler of the table at 0x216730 (entry 1): on phase 0 starts motion 5 of the set at 0x58 (4 without the owner's
// flag 0x2000000) with the times at 0x80 and 0x90 cleared (phase 1). Standing on the target at 0x30 it plays motion 1
// (0) of the set at 0x68 at half speed without a blend; away from it, motion 5 (3) blended with motion 4 (2), timed at
// 0x90 and copied to 0x84 and 0x80, with weight 1 - 1.08 * distance below 0.9259 (else no blend).
void Object_000D0680::func_000D0C10()
{
    float distance = func_0014CB60(&owner->position, &target);
    if (phase == 0) {
        if (owner->flags & 0x2000000) {
            motion_b = set_b->motions[5];
        } else {
            motion_b = set_b->motions[4];
        }
        time = 0;
        time_90 = 0;
        phase = 1;
    }
    if (distance == 0.0f) {
        if (owner->flags & 0x2000000) {
            motion = set->motions[1];
        } else {
            motion = set->motions[0];
        }
        blend = 0;
        func_0005E030(motion, &time, 0.5f, 0);
        return;
    }
    if (owner->flags & 0x2000000) {
        motion = set->motions[5];
        blend = set->motions[4];
    } else {
        motion = set->motions[3];
        blend = set->motions[2];
    }
    func_0005E030(motion, &time_90, 0.5f, 0);
    time = time_84 = time_90;
    if (distance < 0.9259259f) {
        weight = 1.0f - distance * 1.08f;
    } else {
        blend = 0;
    }
}
