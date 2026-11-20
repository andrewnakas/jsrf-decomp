void func_0004E9B0(int first, int second, int third);
void func_00024600(int colour);

struct Object_0004ABA0 {
    char unknown_00[0x4c];
    int unknown_4c;
    int unknown_50;
    int unknown_54;
    int unknown_58;
    int state;

    void func_000539B0();
};

// State handler 0x5d of the table at 0x1F9888: func_0004E9B0 with the words at +0x4c and +0x54, func_00024600
// with 0xFF000000, then state 0x5e.
void Object_0004ABA0::func_000539B0()
{
    func_0004E9B0(unknown_4c, unknown_54, 1);
    func_00024600(0xff000000);
    state = 0x5e;
}
