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

    void func_000F2AA0(int index, int value);
    void func_000F3700();
};

// A handler of the table at 0x21B0F0: when the timer runs out, func_000F2AA0(count, 1) and the count goes up; under
// 2, state 21 and func_000F2AA0(1, 0), else state 25.
void Object_000F2AA0::func_000F3700()
{
    if (--timer <= 0) {
        func_000F2AA0(count, 1);
        if (++count < 2) {
            state = 0x15;
            func_000F2AA0(1, 0);
        } else {
            state = 0x19;
        }
    }
}
