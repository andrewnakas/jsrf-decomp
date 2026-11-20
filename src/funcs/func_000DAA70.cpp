struct Object_000DAAB0 {
    virtual void func_000DAA70();
    virtual void func_000DAAB0();

    int unknown_04;
    int state;
    float time;
    char unknown_10[4];
    int mode;
    unsigned int count;
};

// Virtual (slot 0 of the vtable at data_001CE6E0): in mode 1, the count at 0x18 becomes 15 and the state 1;
// otherwise, while the time at 0xc is below 100, the count becomes 0 and the state 1.
void Object_000DAAB0::func_000DAA70()
{
    if (mode == 1) {
        count = 15;
        state = 1;
    } else if (time < 100.0f) {
        count = 0;
        state = 1;
    }
}
