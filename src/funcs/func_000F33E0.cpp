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

    void func_000F2970(int index, int value);
    void func_000F33E0();
};

// A handler of the table at 0x21B0F0: state 15, the count and +0x34 cleared, then func_000F2970(i, 0) for i = 0, 1, 2.
void Object_000F2AA0::func_000F33E0()
{
    state = 0xf;
    count = 0;
    value_34 = 0;
    func_000F2970(0, 0);
    func_000F2970(1, 0);
    func_000F2970(2, 0);
}
