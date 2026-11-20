struct Vector3 {
    float x;
    float y;
    float z;
};

struct Point_000D1700 {
    Vector3 position;
    char unknown_0c[0xc];
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x60];
    float value_60;
    char unknown_64[0x40];
    unsigned int flags;
};

// The class (constructor func_000D27F0) whose slot 0 runs the member-function table at 0x2169e0.
struct Object_000D27F0 {
    char unknown_000[0x4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[8];
    Vector3 position;
    char unknown_020[0x10];
    unsigned int count_30;
    char unknown_034[4];
    unsigned int index_38;
    unsigned int step_3c;
    char unknown_040[0x50];
    Vector3 path[300];
    char unknown_ea0[0x1c];
    unsigned int next;
    unsigned int total;
    char unknown_ec4[0x10];
    Vector3 start;
    char unknown_ee0[0x50];
    int value_f30;
    char unknown_f34[4];
    int mode_f38;

    int func_000D2120(Point_000D1700 *point, int range);
    void func_000D38D0(int value);
    void func_000D3DE0();
};

// Walks the path at 0x90: while points are left, takes the next one as the position at 0x14 and steers toward it
// (func_000D2120, range 0x222); at the end, in mode 2 (0xf38), goes back to the start at 0xed4 in state 9 with 6 at
// 0xf30, moves the index at 0x38 by the step at 0x3c (wrapping within 0x30), sets the owner's 0x60 to 0.1 and clears
// its flag 0x8000000. Then func_000D38D0(3).
void Object_000D27F0::func_000D3DE0()
{
    if (next < total - 1) {
        next++;
        position = path[next];
        func_000D2120((Point_000D1700 *)&position, 0x222);
    } else if (mode_f38 == 2) {
        position = start;
        state = 9;
        value_f30 = 6;
        index_38 += step_3c;
        index_38 = index_38 == -1 ? count_30 - 1 : index_38;
        index_38 = index_38 < count_30 ? index_38 : 0;
        owner->value_60 = 0.1f;
        owner->flags &= ~0x8000000;
    }
    func_000D38D0(3);
}
