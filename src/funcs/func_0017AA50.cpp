struct Guid;

// The system library's thread function (kernel import #224).
unsigned long __stdcall func_00147DD2(void *thread);

// The object at +0x3c.
struct Worker {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall slot7();
};

// The objects in the list at +0x40.
struct Client {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// A std::vector of pointers.
struct ClientList {
    char allocator;
    Client **first;
    Client **last;
    Client **end;
};

// The class whose table is at 0x1E41D8: the one the MThread factory (0x1E4190) creates for IID_IUnknown.
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
    virtual long __stdcall func_0017AA50();

    char unknown_04[8];
    void *thread;
    char unknown_10[4];
    int value;
    char unknown_18[0x24];
    Worker *worker;
    ClientList list;
};

// Slot 10: calls slot 7 of the object at +0x3c and hands the thread (+0xc) to 0x147DD2. 0x800401F0 (not initialised)
// without a thread.
long __stdcall Object_001E41D8::func_0017AA50()
{
    if (thread) {
        worker->slot7();
        func_00147DD2(thread);
        return 0;
    }
    return 0x800401F0;
}
