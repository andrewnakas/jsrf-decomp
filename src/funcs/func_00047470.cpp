struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470();

    char unknown_04[0x20];
    unsigned int flags;
};

// Slot 2 of the table at 0x1CA490: sets flag 0x10 and runs slot 1.
void Object_00047470::func_00047470()
{
    flags |= 0x10;
    slot1();
}
