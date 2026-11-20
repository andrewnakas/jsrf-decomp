struct Object_0004ABA0 {
    char unknown_0000[0x58];
    int unknown_0058;
    int state;

    void func_0004ABD0();
};

int func_00025680();
int func_000256A0(unsigned int index, int argument);

// State handler (table at 0x1F9888): starts action 0x1d once object 7 is idle and goes to state 4.
void Object_0004ABA0::func_0004ABD0()
{
    if (!func_00025680() && func_000256A0(0x1d, unknown_0058)) {
        state = 4;
    }
}
