struct Guid;

int __stdcall func_00147CC0(void *thread, int value);

// The class whose table is at 0x1E420C: the one the MThread factory (0x1E4190) creates for the interface 0x1E41A8.
struct Object_001E420C {
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
    virtual void slot11();
    virtual long __stdcall func_0017B740(int value);

    char unknown_04[8];
    void *thread;
};

// Slot 12: passes the thread handle at +0xc and the value to func_00147CC0: S_OK when that returns non-zero, E_FAIL
// when it returns 0, 0x800401F0 (not initialised) without a handle.
long __stdcall Object_001E420C::func_0017B740(int value)
{
    if (thread)
        return func_00147CC0(thread, value) ? 0 : 0x80004005;
    return 0x800401F0;
}
