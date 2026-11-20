struct Object_000F2AA0 {
    char unknown_00[8];
    int state;
    char unknown_0c[0x24];
    int value_30;
    int slot;

    void func_000F2970(int index, int flag);
    void func_000F3300();
};

// A handler of the member-function table at 0x21b0f0 (entry 8): state 9, 0 at 0x30, slot 2 at 0x34, then
// func_000F2970(2, 0).
void Object_000F2AA0::func_000F3300()
{
    state = 9;
    value_30 = 0;
    slot = 2;
    func_000F2970(2, 0);
}
