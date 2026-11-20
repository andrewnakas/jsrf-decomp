struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;

    void func_0004AE70();
};

int func_001167F0();

// State handler (table at 0x1F9888): goes to state 0x16 when func_001167F0 returns 2.
void Object_0004ABA0::func_0004AE70()
{
    if (func_001167F0() == 2) {
        state = 0x16;
    }
}
