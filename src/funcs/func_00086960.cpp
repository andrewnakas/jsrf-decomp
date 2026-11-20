struct Object_00086960 {
    virtual ~Object_00086960();
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void func_00086960();

    char unknown_004[0x94];
    int unknown_098;
    char unknown_09c[0x88];
    unsigned int count;
};

// Slot 17 of the table at 0x1CD170 (func_000865D0, slot 2 of the same table, calls it): sets the field at +0x98
// once the count at +0x124 is above zero.
void Object_00086960::func_00086960()
{
    if (count > 0) {
        unknown_098 = 1;
    }
}
