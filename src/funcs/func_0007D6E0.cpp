struct Object_0007C250 {
    virtual ~Object_0007C250();
    virtual void func_0007D6E0();

    char unknown_04[0x40];
    int step;
    int state;
};

extern void (Object_0007C250::*data_0020D3B8[])();

// Slot 1 of the table at 0x1CCEF8: runs the handler for the current step (table at 0x20D3B8) and advances the state.
void Object_0007C250::func_0007D6E0()
{
    (this->*data_0020D3B8[step])();
    state++;
}
