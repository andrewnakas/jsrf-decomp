struct Object_00081860 {
    virtual ~Object_00081860();
    virtual void slot1();
    virtual void slot2();
    virtual void func_00082770(int argument);

    char unknown_04[0xe4c];
    int unknown_e50;

    void func_00081860(int argument);
};

// Slot 3 of the table at 0x1CCFF8: passes its argument to func_00081860 unless the field at +0xe50 is 0x1b.
void Object_00081860::func_00082770(int argument)
{
    if (unknown_e50 != 0x1b) {
        func_00081860(argument);
    }
}
