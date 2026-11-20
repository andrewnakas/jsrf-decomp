struct Object_00081860 {
    virtual ~Object_00081860();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);
    virtual void slot4();
    virtual void slot5();
    virtual void func_00082790(int argument);

    char unknown_04[0xe4c];
    int unknown_e50;

    void func_00081860(int argument);
};

// Slot 6 of the table at 0x1CCFF8: passes its argument to func_00081860 when the field at +0xe50 is 0x1b.
void Object_00081860::func_00082790(int argument)
{
    if (unknown_e50 == 0x1b) {
        func_00081860(argument);
    }
}
