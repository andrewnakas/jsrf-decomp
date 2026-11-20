struct Info_000C7910 {
    char unknown_00[4];
    float top;
    char unknown_08[8];
    float rise;
    float fall;
};

struct Speed_000C7910 {
    char unknown_00[0x30];
    Info_000C7910 *info;
};

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240).
struct Object_000C7910 {
    char unknown_00[0x60];
    float value_60;
    char unknown_64[0x2c];
    unsigned int flags;
    char unknown_94[0x320];
    Speed_000C7910 *speed;

    void func_000C9E40(float target);
};

// Moves the value at 0x60 toward target: up by the rise at 0x10 of the speed info (capped at target), down by
// the fall at 0x14. Under flag 0x10 the target is twice the top speed at 4 and the rise four times as large.
void Object_000C7910::func_000C9E40(float target)
{
    Info_000C7910 *info = speed->info;
    float rise = info->rise;
    if (flags & 0x10) {
        target = info->top + info->top;
        rise *= 4.0f;
    }
    if (value_60 < target) {
        value_60 += rise;
        if (value_60 > target)
            value_60 = target;
    } else if (value_60 > target) {
        value_60 -= info->fall;
    }
}
