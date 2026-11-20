struct Guid;

// The system library's wait for several objects (0x145C8C) and close (0x145585).
unsigned long __stdcall func_00145C8C(unsigned long count, void **handles, int all, unsigned long timeout);
int __stdcall func_00145585(void *handle);

// The worker object at +0x3c (slot 4 gives out its event).
struct Worker {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall slot4(void **event);
};

// The MThread class whose table is at 0x1E41D8 (the table at 0x1E420C holds the same slot 9, folded).
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
    virtual long __stdcall func_0017A9B0(unsigned long timeout);

    void *outer;
    long references;
    void *thread;
    char unknown_10[0x2c];
    Worker *worker;
};

// Slot 9: waits up to `timeout` for the thread or the worker's event. When the thread ends it is closed and E_FAIL
// returned; S_OK for the event, S_FALSE on the timeout, E_FAIL for a failed wait. 0x800401F0 (not
// initialised) without a thread.
long __stdcall Object_001E41D8::func_0017A9B0(unsigned long timeout)
{
    if (thread) {
        void *event;
        worker->slot4(&event);
        void *handles[2];
        handles[0] = thread;
        handles[1] = event;
        unsigned long result = func_00145C8C(2, handles, 0, timeout);
        if (result == 0) {
            func_00145585(thread);
            thread = 0;
            return 0x80004005;
        }
        if (result == 1)
            return 0;
        return result == 0x102 ? 1 : 0x80004005;
    }
    return 0x800401F0;
}
