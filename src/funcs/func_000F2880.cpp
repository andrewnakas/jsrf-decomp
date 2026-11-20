struct Object_000F2AA0 {
    char unknown_00[8];
    int state;
    int timer;
    char unknown_10[0x24];
    int slot;

    void func_000F2420(int index, int flag);
    void func_000F2880();
};

// Entry 11 of the member-function table at 0x21b0f0: func_000F2420 for the slot at 0x34 with flag 1, then state
// 12 and the timer at 0xc set to 150.
void Object_000F2AA0::func_000F2880()
{
    func_000F2420(slot, 1);
    state = 12;
    timer = 150;
}
