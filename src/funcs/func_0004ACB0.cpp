struct Info_0004ACB0 {
    int unknown_00;
    char unknown_04[0x18];
    int unknown_1c;
};

struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0xfe0];
    Info_0004ACB0 *info;

    void func_0004ACB0();
};

int func_00025680();
int func_000256A0(unsigned int index, int argument);

// State handler (table at 0x1F9888): starts action 4 once object 7 is idle and goes to state 12.
void Object_0004ABA0::func_0004ACB0()
{
    if (!func_00025680() && func_000256A0(4, info->unknown_00)) {
        state = 12;
    }
}
