struct Object_000A4D80 {
    char unknown_000[0xc];
    int state;
    char unknown_010[0xe4];
    int value_f4;
    char unknown_0f8[0x140];
    int value_238;

    void func_000A58C0();
};

// Entry 2 of the camera node's member-function table at 0x215534 (called by func_000A5070 on a mode change):
// clears 0xf4 and 0x238, state 4.
void Object_000A4D80::func_000A58C0()
{
    value_f4 = 0;
    state = 4;
    value_238 = 0;
}
