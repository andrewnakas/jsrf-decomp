struct Object_000F55E0 {
    virtual void func_000F5600();

    char unknown_004[0xb8];
    int state;
    char unknown_0c0[0x18];
    int timer;
    char unknown_x[0x94];
    int mode;
};

// Virtual: slot 30 of the vtable at data_001CF220 (stored by func_000F5E70 and func_000F60C0); also
// listed at 0x1ceb38. When the mode at 0x170 is 2: state 7, timer at 0xd8 = 0.
void Object_000F55E0::func_000F5600()
{
    if (mode == 2) {
        state = 7;
        timer = 0;
    }
}
