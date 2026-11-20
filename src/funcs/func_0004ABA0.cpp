struct Object_0004ABA0 {
    char unknown_0000[0x58];
    int unknown_0058;
    int state;

    void func_0004ABA0();
};

int func_00025680();
int func_000256A0(unsigned int index, int argument);

// State handler (table at 0x1F9888): starts action 0 once object 7 is idle and goes to state 1.
void Object_0004ABA0::func_0004ABA0()
{
    if (!func_00025680() && func_000256A0(0, unknown_0058)) {
        state = 1;
    }
}
