int func_0004A7F0(int from, int to);

// The object at 0x2a0 of the player: the turn step (0x60), the widest turn it follows (0x64) and its scale (0x68).
struct Object_00094780 {
    char unknown_00[0x60];
    int step;
    int range;
    float scale;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x2a0];
    Object_00094780 *object_2a0;
    char unknown_2a4[0x1c0];
    int value_464;
    char unknown_468[0x858];
    int heading;

    float func_0007F820();
    int func_0007F850();
    int func_0008A1D0(int heading);
    void func_0009A090();
};

// Above half input (func_0007F820), turns the heading at 0xcc0 toward the wanted one (func_0007F850, or
// func_0008A1D0 with 0x464 set): the scaled difference (func_0004A7F0) is followed when it is narrower than the range
// at 0x64 of the object at 0x2a0, at most by the step at 0x60.
void Object_000A1C50::func_0009A090()
{
    if (func_0007F820() > 0.5f) {
        int wanted = func_0007F850();
        if (value_464) {
            wanted = func_0008A1D0(heading);
        }
        int turn = (int)(func_0004A7F0(wanted, heading) * object_2a0->scale);
        if ((turn < 0 ? -turn : turn) < object_2a0->range) {
            int step = object_2a0->step;
            if (turn > step) {
                heading -= step;
            } else if (turn < -step) {
                heading += step;
            } else {
                heading -= turn;
            }
        }
    }
}
