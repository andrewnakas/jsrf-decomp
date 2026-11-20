struct Object_000F2AA0 {
    char unknown_00[8];
    int state;
    char unknown_0c[0x24];
    int value_30;

    void func_000F2AA0(int index, int flag);
    void func_000F3750();
};

// State 27, clears the field at 0x30, then func_000F2AA0(0, 0) and func_000F2AA0(1, 0).
void Object_000F2AA0::func_000F3750()
{
    state = 27;
    value_30 = 0;
    func_000F2AA0(0, 0);
    func_000F2AA0(1, 0);
}
