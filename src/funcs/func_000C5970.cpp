struct Part_000C5910 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int argument);
    virtual void slot3(int argument);
};

struct Object_000C5910 {
    virtual void slot0();
    virtual void slot1();
    virtual void func_000C5910();
    virtual void func_000C5940(int argument);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void func_000C5970(int argument);

    char unknown_004[0xd0];
    Part_000C5910 *first;
    Part_000C5910 *second;
};

// Virtual (slot 12 of the vtable at data_001CDFF0). Passes the argument to slot 3 of the two parts at 0xd4
// and 0xd8 that exist.
void Object_000C5910::func_000C5970(int argument)
{
    if (first) {
        first->slot3(argument);
    }
    if (second) {
        second->slot3(argument);
    }
}
