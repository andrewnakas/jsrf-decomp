struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

// The owner type of the Object_000CC600 family; func_000C5B10 calls its callback at 0xe8.
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
};

struct Set_000ECB50 {
    Motion_0005F060 *motions[32];
};

// The object func_000ECB50 builds (Node and a chain link at 0x44); this is a handler of the table at 0x258520 its
// slot 1 (func_000ECDB0) runs, filled in by the dynamic initializer func_0018C0C0.
struct Object_000ECB50 {
    char unknown_000[0x48];
    Vector3 position;
    char unknown_054[0x3c];
    unsigned int flags;
    char unknown_094[0x1c];
    Object_000C5B50 *owner;
    char unknown_0b4[0x74];
    int next;
    int phase;
    char unknown_130[4];
    int index;
    char unknown_138[0xc];
    Set_000ECB50 *set;
    Motion_0005F060 *motion;
    Motion_0005F060 *motion_b;
    char unknown_150[4];
    float time;
    float time_b;

    void func_000EC570();
};

// Entry 4 of the handlers at 0x258520: plays the motion at 0x148 at half speed once. After 480 calls, once it has
// reached its last frame: state 2, motion 2 of the set at 0x144 as the second one at time 0, and message 0x31 with
// the position to the owner at 0xb0. Before that, the flag 0x2000000 gives state 1 with motion 8 + index restarted
// (and the flag dropped).
void Object_000ECB50::func_000EC570()
{
    func_0005E030(motion, &time, 0.5f, 0);
    if (++phase > 480) {
        if (motion->frames - 1.0f <= time) {
            next = 2;
            motion_b = set->motions[2];
            time_b = 0.0f;
            owner->func_000C5B10(0x31, &position);
        }
    } else if (flags & 0x2000000) {
        next = 1;
        motion = set->motions[8 + index];
        time = 0.0f;
        flags &= ~0x2000000;
    }
}
