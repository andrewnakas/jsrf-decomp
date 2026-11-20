struct Vector3 {
    float x;
    float y;
    float z;
};

// The engine's larger of two ints.
int __fastcall func_0014C840(int first, int second);

// The Node child func_000E45D0 builds (with a chain link at 0x44); this is a handler of the member pointers at
// 0x258470, filled in by the dynamic initializer func_0018BF30.
struct Object_000E45D0 {
    char unknown_000[0xcc];
    Vector3 target_0cc;
    unsigned int index;
    char unknown_0dc[0x68];
    int value_144;
    unsigned int value_148;
    char unknown_14c[0x10];
    Vector3 *targets;
    unsigned int count;

    int func_000E4370();
    void func_000E4A00();
};

// Entry 0 of the handlers at 0x258470: when func_000E4370 gives no turn, aims at the next of the points at 0x15c
// (wrapping at the count at 0x160); otherwise 0x144 drops toward 15 for turns under 0x888 either way and grows toward
// 60 for larger ones. Then counts 0x148 down to 0.
void Object_000E45D0::func_000E4A00()
{
    int turn = func_000E4370();
    if (turn == 0) {
        if (++index >= count) {
            index = 0;
        }
        target_0cc = targets[index];
    } else if (func_0014C840(turn, -turn) < 0x888) {
        if (--value_144 < 15) {
            value_144 = 15;
        }
    } else if (value_144 < 60) {
        value_144++;
    }
    if (value_148 > 0) {
        value_148--;
    }
}
