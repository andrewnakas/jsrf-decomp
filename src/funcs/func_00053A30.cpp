void func_00024620(unsigned int color, float step);
void func_0004E9B0(int first, int second, int third);

struct Object_0004ABA0 {
    char unknown_00[0x4c];
    int unknown_4c;
    char unknown_50[0x4];
    int unknown_54;
    char unknown_58[0x4];
    int state;

    void func_00053A30();
};

// State handler 0x5f of the table at 0x1F9888: fades to black over 60 frames (func_00024620), runs func_0004E9B0 with
// the words at +0x4c and +0x54 and 1, and moves to state 0x60.
void Object_0004ABA0::func_00053A30()
{
    func_00024620(0xff000000, 1.0f / 60.0f);
    func_0004E9B0(unknown_4c, unknown_54, 1);
    state = 0x60;
}
