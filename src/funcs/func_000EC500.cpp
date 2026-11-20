struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

// The object func_000ECB50 builds (Node and a chain link at 0x44); this is a handler of the table at 0x258520 its
// slot 1 (func_000ECDB0) runs, filled in by the dynamic initializer func_0018C0C0.
struct Object_000ECB50 {
    char unknown_000[0x128];
    int next;
    int phase;
    char unknown_130[0x18];
    Motion_0005F060 *motion;
    Motion_0005F060 *motion_b;
    char unknown_150[4];
    float time;
    float time_b;

    void func_000EC500();
};

// Entry 3 of the handlers at 0x258520: plays the motion at 0x148 at half speed once and the one at 0x14c looping;
// when the second wraps, moves to state 4 and clears it, its time and the phase.
void Object_000ECB50::func_000EC500()
{
    func_0005E030(motion, &time, 0.5f, 0);
    if (func_0005E030(motion_b, &time_b, 0.5f, 1)) {
        next = 4;
        motion_b = 0;
        time_b = 0.0f;
        phase = 0;
    }
}
