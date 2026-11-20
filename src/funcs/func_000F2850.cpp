struct Object_000F2AA0 {
    char unknown_00[8];
    int state;
    int value_0c;
    char unknown_10[0x58];
    int first;
    int second;

    void func_000F2420(int value, int flag);
    void func_000F2850();
};

// A handler (0x21B104): func_000F2420 with the values at 0x68 and 0x6c (each with 1), then 6 at 8 and 0x10e
// at 0xc.
void Object_000F2AA0::func_000F2850()
{
    func_000F2420(first, 1);
    func_000F2420(second, 1);
    state = 6;
    value_0c = 0x10e;
}
