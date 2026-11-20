/* const: 0x10000 */
// Turns the 16-bit angle `current` towards `target` by at most `step` the short way round; returns `target` (masked)
// when it is within `step`.
int func_0004A820(int current, int target, int step)
{
    current &= 0xffff;
    target &= 0xffff;
    if (target > current) {
        if (target - current < 0x8000) {
            if (target - current < step)
                return target;
            return current + step;
        }
        if (current - target + 0x10000 < step)
            return target;
        return current - step;
    }
    if (current - target < 0x8000) {
        if (current - target < step)
            return target;
        return current - step;
    }
    if (target - current + 0x10000 < step)
        return target;
    return current + step;
}
