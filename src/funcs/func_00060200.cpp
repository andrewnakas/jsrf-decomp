struct Object_00060200 {
    virtual ~Object_00060200();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);
    virtual void slot4();
    virtual void slot5();
    virtual void func_00060200(int argument);

    char unknown_04[0x160];
    int unknown_164;
};

// Slot 6 of the table at 0x1CB040: runs slot 3 (func_00064E30 in that table) unless the field at +0x164 is 1.
void Object_00060200::func_00060200(int argument)
{
    if (unknown_164 != 1) {
        slot3(argument);
    }
}
