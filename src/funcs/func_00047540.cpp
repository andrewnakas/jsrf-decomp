struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void func_00047540();

    char unknown_04[0x20];
    unsigned int flags;
};

// Slot 4 of the table at 0x1CA490: sets flag 0x10 and runs slot 3.
void Object_00047470::func_00047540()
{
    flags |= 0x10;
    slot3();
}
