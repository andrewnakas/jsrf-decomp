struct Object_000F2AA0 {
    char unknown_00[8];
    int state;
    int value_0c;
    char unknown_10[0x20];
    int value_30;

    void func_000F2500(int value);
    void func_000F2900();
};

// A handler of the table at 0x21B140 (entry 3): func_000F2500 with the value at 0x30, then 0x18 at 8 and 0x78
// at 0xc.
void Object_000F2AA0::func_000F2900()
{
    func_000F2500(value_30);
    state = 0x18;
    value_0c = 0x78;
}
