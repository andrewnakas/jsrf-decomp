struct Object_00045DB0 {
    virtual ~Object_00045DB0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void func_00045DB0();

    char unknown_04[0x74];
    int unknown_78;
};

// Slot 5 of the table at 0x1CA788: runs slot 2 while the field at +0x78 is 100.
void Object_00045DB0::func_00045DB0()
{
    if (unknown_78 == 100) {
        slot2();
    }
}
