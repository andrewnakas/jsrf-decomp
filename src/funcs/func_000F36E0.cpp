struct Object_000F2AA0 {
    char unknown_00[8];
    int state;
    char unknown_0c[0x24];
    int value_30;

    void func_000F2AA0(int index, int flag);
    void func_000F36E0();
};

void Object_000F2AA0::func_000F36E0()
{
    state = 21;
    value_30 = 0;
    func_000F2AA0(0, 0);
}
