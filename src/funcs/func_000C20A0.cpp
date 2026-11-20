struct Object_000C20A0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void func_000C20A0();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();

    char unknown_04[0x30];
    unsigned int state;
};

// Virtual (slot 11 of the vtable at data_001CDC60). Unless the state at 0x34 is 0, 1 or 6: when virtual slot
// 16 reports true, the state becomes 5.
void Object_000C20A0::func_000C20A0()
{
    if (state > 1 && state != 6 && slot16()) {
        state = 5;
    }
}
