// The object at data_00257CE8; this function does not use it.
struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// Moves a 16-bit angle toward the target by at most the step, along the shorter way round.
int Object_000C1440::func_000C1450(int current, int target, int step)
{
    int difference = (short)(target - current);
    if (difference > step) {
        return current + step;
    }
    if (difference < -step) {
        return current - step;
    }
    return target;
}
