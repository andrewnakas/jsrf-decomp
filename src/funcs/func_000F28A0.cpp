struct Owner_000F2AA0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000F2AA0 {
    int unknown_00;
    Owner_000F2AA0 *owner;
    int state;
    int timer;
    char unknown_10[0x20];
    unsigned int count;
    int value_34;

    void func_000F2420(int index, int value);
    void func_000F28A0();
};

// A handler of the table at 0x21B0F0: func_000F2420(i, 1) for i = 0 to 2 while the count is 0, else for i = 1 to 3;
// state 18 and the timer at 120.
void Object_000F2AA0::func_000F28A0()
{
    if (count == 0) {
        func_000F2420(0, 1);
        func_000F2420(1, 1);
        func_000F2420(2, 1);
    } else {
        func_000F2420(1, 1);
        func_000F2420(2, 1);
        func_000F2420(3, 1);
    }
    state = 0x12;
    timer = 0x78;
}
