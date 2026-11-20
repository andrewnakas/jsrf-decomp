struct Object_000F2AA0 {
    char unknown_00[8];
    int state;
    int timer;

    void func_000F2AA0(int index, int flag);
    void func_000F3780();
};

// Counts the timer at 0xc down; when it runs out: func_000F2AA0(0, 1), func_000F2AA0(1, 1), state 31.
void Object_000F2AA0::func_000F3780()
{
    if (--timer <= 0) {
        func_000F2AA0(0, 1);
        func_000F2AA0(1, 1);
        state = 31;
    }
}
