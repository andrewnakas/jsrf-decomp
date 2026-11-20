// A path: its point count at +0x4.
struct Path_00050860 {
    int unknown_00;
    unsigned int count;
};

// Steps the time along the path by the step. Without the flag it wraps the time into [0, count) and returns 0; with
// it the time stops at the last point or at 0 and the result is 1 when it had to (otherwise 0).
int func_0005DF50(Path_00050860 *path, float *time, float step, int flag)
{
    step += *time;
    *time = step;
    if (!flag) {
        while (*time >= path->count)
            *time -= path->count;
        while (*time < 0.0f)
            *time += path->count;
        return 0;
    }
    float last = path->count - 1.0f;
    if (step > last) {
        *time = last;
        return 1;
    }
    if (step < 0.0f) {
        *time = 0.0f;
        return 1;
    }
    return 0;
}
