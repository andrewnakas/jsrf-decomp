struct Guid;

unsigned long __stdcall func_00147DAC(void *thread);

// The class whose table is at 0x1E41D8: the class the MThread factory (0x1E4190) creates for IID_IUnknown. The table
// at 0x1E420C holds the same function in slot 11.
struct Object_001E41D8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual long __stdcall func_0017AA80();

    char unknown_04[8];
    void *thread;
};

// Slot 11: passes the thread handle at +0xc to func_00147DAC (which hands it to kernel import #231), or fails with
// 0x800401F0 (not initialised) when there is none.
long __stdcall Object_001E41D8::func_0017AA80()
{
    if (thread) {
        func_00147DAC(thread);
        return 0;
    }
    return 0x800401F0;
}
