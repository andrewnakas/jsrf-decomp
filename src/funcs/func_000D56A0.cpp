struct Motion_0005F060;

struct Set_000D27F0 {
    Motion_0005F060 *motions[64];
};

struct Object_000D27F0 {
    char unknown_000[0x80];
    int kind;
    char unknown_084[0x4];
    int mode;
    char unknown_08c[0xe74];
    Set_000D27F0 *set;
    Motion_0005F060 *motion;
    char unknown_f08[0x14];
    float time;
    char unknown_f20[0x10];
    int next;
    char unknown_f34[0x8];
    int value_f3c;

    void func_000D56A0();
};

// A handler of the table at 0x216DC8: takes, by the mode at 0x88, motion 44 (mode 0, clearing 0xf3c), 4 or 6 (mode
// 1) or 51 or 53 (mode 2), the first for kind 0x12 at 0x80, at time 0, with 0 at 0xf30. Any other mode reads an index
// that was never set.
void Object_000D27F0::func_000D56A0()
{
    int index;
    switch (mode) {
    case 0:
        index = 44;
        value_f3c = 0;
        break;
    case 1:
        index = kind == 0x12 ? 4 : 6;
        break;
    case 2:
        index = kind == 0x12 ? 51 : 53;
        break;
    }
    motion = set->motions[index];
    time = 0.0f;
    next = 0;
}
