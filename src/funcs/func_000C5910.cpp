struct Part_000C5910 {
    virtual void slot0();
    virtual void slot1();
};

struct Object_000C5910 {
    virtual void slot0();
    virtual void slot1();
    virtual void func_000C5910();

    char unknown_004[0xd0];
    Part_000C5910 *first;
    Part_000C5910 *second;
};

// Virtual (slot 2 of the vtable at data_001CDFF0). Calls slot 1 of the two parts at 0xd4 and 0xd8 that
// exist.
void Object_000C5910::func_000C5910()
{
    if (first) {
        first->slot1();
    }
    if (second) {
        second->slot1();
    }
}
