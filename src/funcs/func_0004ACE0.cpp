struct Info_0004ACE0 {
    int unknown_00;
    char unknown_04[0x18];
    int unknown_1c;
};

struct Object_0004ABA0 {
    char unknown_0000[0x48];
    int unknown_0048;
    char unknown_004c[0x10];
    int state;
    char unknown_0060[0xfe0];
    Info_0004ACE0 *info;

    void func_0004ACE0();
};

int func_000256C0(unsigned int index, int argument);

// State handler (table at 0x1F9888): goes to state 13 when action 4 reports done.
void Object_0004ABA0::func_0004ACE0()
{
    if (func_000256C0(4, info->unknown_00)) {
        unknown_0048 = 2;
        state = 13;
    }
}
