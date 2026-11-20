struct Part_000C5910 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int argument);
};

struct Object_000C5910 {
    virtual void slot0();
    virtual void slot1();
    virtual void func_000C5910();
    virtual void func_000C5940(int argument);

    char unknown_004[0xd0];
    Part_000C5910 *first;
    Part_000C5910 *second;
};

// Virtual (slot 3 of the vtable at data_001CDFF0). Passes the argument to slot 2 of the two parts at 0xd4
// and 0xd8 that exist.
void Object_000C5910::func_000C5940(int argument)
{
    if (first) {
        first->slot2(argument);
    }
    if (second) {
        second->slot2(argument);
    }
}
