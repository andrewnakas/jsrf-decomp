struct Object_0004ABA0 {
    char unknown_00[0x5c];
    int state;
    char unknown_60[0xf5c];
    int timer;

    void func_0004B9D0();
};

// State handler (table at 0x1F9888): goes to state 0x44 when the wait runs out.
void Object_0004ABA0::func_0004B9D0()
{
    if (--timer == 0) {
        state = 0x44;
    }
}
