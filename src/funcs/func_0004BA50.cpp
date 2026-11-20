struct Object_0004ABA0 {
    char unknown_00[0x5c];
    int state;
    char unknown_60[0xf5c];
    int timer;

    void func_0004BA50();
};

// State handler (table at 0x1F9888): goes to state 0x4a when the wait runs out.
void Object_0004ABA0::func_0004BA50()
{
    if (--timer == 0) {
        state = 0x4a;
    }
}
