struct Info_0004AC50 {
    int unknown_00;
    char unknown_04[0x18];
    int unknown_1c;
};

struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0xfe0];
    Info_0004AC50 *info;

    void func_0004AC50();
};

int func_000256C0(unsigned int index, int argument);

// State handler (table at 0x1F9888): goes to state 7 when action 0x1a reports done.
void Object_0004ABA0::func_0004AC50()
{
    if (func_000256C0(0x1a, info->unknown_1c)) {
        state = 7;
    }
}
