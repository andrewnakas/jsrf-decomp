int func_000256C0(unsigned int index, int argument);

struct Object_0004EF90 {
    char unknown_00[0x44];
    unsigned int state;

    void func_0004F1C0();
};

// State handler 9 of the table at 0x1FA008: goes to state 2 once func_000256C0(0x19, 2) says so.
void Object_0004EF90::func_0004F1C0()
{
    if (func_000256C0(0x19, 2)) {
        state = 2;
    }
}
