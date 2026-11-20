struct Surface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual unsigned long __stdcall slot3(int which);
    virtual long __stdcall slot4(void **data, unsigned long flags);
};

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159510(Surface **holder, void **data, unsigned long *third,
                                         unsigned long *first);  // slot 6
};

// Slot 6: locks the holder's surface (its slot 4) and hands out the data and, where asked, its values 3 and 1
// (slot 3); the lock's error otherwise.
long __stdcall Object_001E1640::func_00159510(Surface **holder, void **data, unsigned long *third,
                                              unsigned long *first)
{
    Surface *surface = *holder;
    void *locked = 0;
    long result = surface->slot4(&locked, 0);
    if (result < 0)
        return result;
    if (data)
        *data = locked;
    if (third)
        *third = surface->slot3(3);
    if (first)
        *first = surface->slot3(1);
    return 0;
}
