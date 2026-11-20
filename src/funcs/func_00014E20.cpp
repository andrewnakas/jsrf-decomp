struct Object_00065730 {
    int func_00066FF0();
};

extern Object_00065730 data_001FB8E8;

struct Object_00014A80 {
    char unknown_00[8];
    int type;
    char unknown_0c[0x48];
    int current;
    int total;

    void func_00014E20(int value);
};

// Called by the player (0x80BD0) on 0x1EB938. With type 2, moves the value at +0x54 to `value` and adds the step to
// the running total at +0x58, taking the shorter way round a circle of func_00066FF0's size (of 0x1FB8E8).
void Object_00014A80::func_00014E20(int value)
{
    if (type == 2 && value != current) {
        int step = value - current;
        int size = data_001FB8E8.func_00066FF0();
        int half = size >> 1;
        if (step <= -half) {
            step += size;
        } else if (step >= half) {
            step -= size;
        }
        total += step;
        current = value;
    }
}
