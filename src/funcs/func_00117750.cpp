struct Object_00117510 {
    virtual ~Object_00117510();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);
    virtual void func_00117750();

    char unknown_004[0x408];
    int value_40c;
};

void func_001168F0();

// Slot 4 of the table at 0x1D7778: calls func_001168F0 and sets the word at +0x40c to -1.
void Object_00117510::func_00117750()
{
    func_001168F0();
    value_40c = -1;
}
