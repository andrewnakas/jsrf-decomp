void func_00024620(unsigned int color, float rate);
int func_00119540(int group, int index, void *position);

// The node class whose table is at 0x1CB0F8 (object 0x12af; constructor 0x67B60, destructor 0x67980).
struct Object_00067980 {
    char unknown_000[0x98];
    int state;
    char unknown_09c[0xc];
    int step;

    void func_000673D0(int first, int second);
    void func_00068570();
};

// Steps 0 and 1 go to state 8 with a fade to black (rate 1/12); step 2 runs func_000673D0(2, 0) and goes back to step
// 1. Every step plays sound 8/2 (func_00119540).
void Object_00067980::func_00068570()
{
    switch (step) {
    case 0:
        state = 8;
        func_00024620(0xff000000, 1.0f / 12.0f);
        break;
    case 1:
        state = 8;
        func_00024620(0xff000000, 1.0f / 12.0f);
        break;
    case 2:
        func_000673D0(2, 0);
        step = 1;
        break;
    }
    func_00119540(8, 2, 0);
}
