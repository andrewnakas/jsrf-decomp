struct Object_000F2AA0 {
    char unknown_00[8];
    int state;
    char unknown_0c[0x24];
    int value_30;
    int slot;
    char unknown_38[0x30];
    int first;
    int second;

    void func_000F2970(int index, int flag);
    void func_000F3180();
};

// Entry 2 of the member-function table at 0x21b0f0: state 3, 0 at 0x30 and 0x34, then func_000F2970 for the
// indexes at 0x68 and 0x6c with flag 0.
void Object_000F2AA0::func_000F3180()
{
    state = 3;
    value_30 = 0;
    slot = 0;
    func_000F2970(first, 0);
    func_000F2970(second, 0);
}
