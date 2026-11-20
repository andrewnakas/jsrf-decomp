struct Object_000CD1E0 {
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
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void func_000CD1E0();

    int unknown_04;
    int state;
    char unknown_0c[0x68];
    void (Object_000CD1E0::**handlers)();
};

// Virtual (slot 17): runs the handler for the current state from the table at 0x74, then slot 8.
void Object_000CD1E0::func_000CD1E0()
{
    (this->*handlers[state])();
    slot8();
}
