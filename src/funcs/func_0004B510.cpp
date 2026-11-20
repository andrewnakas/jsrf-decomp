struct Object_0004ABA0 {
    char unknown_00[0x5c];
    int state;
    char unknown_60[0xf5c];
    int timer;

    void func_0004B510();
};

// State handler (table at 0x1F9888): starts a 180-frame wait and goes to state 0x33.
void Object_0004ABA0::func_0004B510()
{
    timer = 180;
    state = 0x33;
}
