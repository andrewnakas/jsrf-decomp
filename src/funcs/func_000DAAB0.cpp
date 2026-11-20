struct Object_000DAAB0 {
    virtual void func_000DAA70();
    virtual void func_000DAAB0();

    int unknown_04;
    int state;
    char unknown_0c[0xc];
    unsigned int count;
};

// Virtual (slot 1 of the vtable at data_001CE6E0, which func_000DAB10 stores). Counts up at 0x18 from 1; past
// 60 the state at 8 becomes 2.
void Object_000DAAB0::func_000DAAB0()
{
    if (count > 60) {
        state = 2;
    } else if (count == 0) {
        count = 1;
    } else {
        count++;
    }
}
