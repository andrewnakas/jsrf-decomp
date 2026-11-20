struct Object_0004EF90 {
    virtual ~Object_0004EF90();
    virtual void func_0004EF90();

    char unknown_04[0x40];
    unsigned int state;
};

extern void (Object_0004EF90::*data_001FA008[])();

// Slot 1 of the table at 0x1CAAF8: runs the handler of the current state (21 states, table at 0x1FA008).
void Object_0004EF90::func_0004EF90()
{
    if (state < 0x15) {
        (this->*data_001FA008[state])();
    }
}
