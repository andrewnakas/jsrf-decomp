// A motion: its frame count at +0x2.
struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

// Steps the time by the speed. Without flags it wraps the time into [0, frames) and returns 0; with flags it holds
// the time at the last frame or at 0 and returns 1 when it had to (otherwise 0).
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int flags)
{
    speed += *time;
    *time = speed;
    if (!flags) {
        while (*time >= motion->frames)
            *time -= motion->frames;
        while (*time < 0.0f)
            *time += motion->frames;
        return 0;
    }
    float last = motion->frames - 1.0f;
    if (speed > last) {
        *time = last;
        return 1;
    }
    if (speed < 0.0f) {
        *time = 0.0f;
        return 1;
    }
    return 0;
}
