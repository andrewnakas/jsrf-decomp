struct Guid;

// The objects in the list at +0x40.
struct Listener {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(int value);
    virtual long __stdcall slot7(int value);
};

// The class whose table is at 0x1E420C: the one the MThread factory (0x1E4190) creates for the interface 0x1E41A8.
struct Object_001E420C {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall slot5(unsigned int index, Listener **listener);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual long __stdcall func_0017B770(unsigned int index, int set, int value);

    char unknown_04[8];
    void *thread;
};

// Slot 13: takes entry `index` of the list with slot 5 and passes the value on to its slot 6 (`set` non-zero) or slot
// 7, then lets go of it; anything but 0 from slot 5 is returned as it is. 0x800401F0 (not initialised) without a thread
// (+0xc).
long __stdcall Object_001E420C::func_0017B770(unsigned int index, int set, int value)
{
    long result;
    if (thread) {
        Listener *listener;
        result = slot5(index, &listener);
        if (result == 0) {
            if (set)
                result = listener->slot6(value);
            else
                result = listener->slot7(value);
            if (listener)
                listener->slot2();
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
