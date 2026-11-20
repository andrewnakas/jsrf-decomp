struct Object_000865D0 {
    virtual ~Object_000865D0();
    virtual void slot1();
    virtual void func_000865D0();
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
    virtual void slot17();

    char unknown_04[0x94];
    int unknown_98;
};

// Slot 2 of the tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210: runs slot 17 unless the field at +0x98 is set.
void Object_000865D0::func_000865D0()
{
    if (!unknown_98) {
        slot17();
    }
}
