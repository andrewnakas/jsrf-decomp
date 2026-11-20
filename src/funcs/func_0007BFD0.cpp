int func_000256C0(unsigned int index, int argument);
int func_00025680();
int func_000256A0(unsigned int index, int argument);
void func_0006F760();

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007BFD0();
};

// State handler 1 of the table at 0x20D2B8: unless func_000256C0 (10, 0) says so already, runs func_000256A0 (10, 0)
// when func_00025680 allows; once func_000256C0 (10, 0) says so, func_0006F760 and state 2.
void Object_0007C250::func_0007BFD0()
{
    if (!func_000256C0(10, 0) && !func_00025680())
        func_000256A0(10, 0);
    if (func_000256C0(10, 0)) {
        func_0006F760();
        state = 2;
    }
}
