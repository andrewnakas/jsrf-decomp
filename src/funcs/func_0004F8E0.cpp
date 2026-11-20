int func_00025680();
int func_000256A0(unsigned int index, int argument);

struct Object_0004EF90 {
    char unknown_00[0x44];
    unsigned int state;

    void func_0004F8E0();
};

// State handler 18 of the table at 0x1FA008: unless func_00025680 says so, runs action 0x14 and goes to state 0x13.
void Object_0004EF90::func_0004F8E0()
{
    if (!func_00025680()) {
        func_000256A0(0x14, 0);
        state = 0x13;
    }
}
