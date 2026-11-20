struct Object_000461A0 {
    virtual ~Object_000461A0();
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
    virtual void slot11();
    virtual void func_000461A0(int argument);

};

// Slot 12 (and 15) of the table at 0x1CA788: runs slot 1 whatever the argument.
void Object_000461A0::func_000461A0(int)
{
    slot1();
}
