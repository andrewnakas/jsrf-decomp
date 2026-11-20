struct Target_0010F4B0 {
    char unknown_00[0x48];
    unsigned int flags;
};

// Sets or clears the top flag bit at 0x48 of the target, when there is one.
void func_0010F4B0(Target_0010F4B0 *target, int set)
{
    if (target) {
        if (set) {
            target->flags |= 0x80000000;
        } else {
            target->flags &= 0x7fffffff;
        }
    }
}
