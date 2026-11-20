struct Owner_000CBF90 {
    char unknown_00[0x68];
    int value_68;
    char unknown_6c[0x38];
    unsigned int flags;
};

struct Object_000CCE00 {
    virtual void slot0();
    virtual void func_000CD050();
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
    virtual void func_000CBF90();

    Owner_000CBF90 *owner;
    int state;
};

// Virtual (slot 13 of the vtable at data_001CE320, the class of func_000CD050): clears the owner's field
// at 0x68 and its flags 0x20000 and 0x400, then state 2.
void Object_000CCE00::func_000CBF90()
{
    owner->value_68 = 0;
    owner->flags &= ~0x20000;
    owner->flags &= ~0x400;
    state = 2;
}
