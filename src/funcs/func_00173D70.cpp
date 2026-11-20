struct Guid;

// What slot 6 fills in (0x14 bytes); its second word is compared with the position.
struct Status {
    unsigned long unknown_00;
    long size;
    unsigned long unknown_08[3];
};

// The class whose table is at 0x1E3DE4.
struct Object_001E3DE4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(Status *status);
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall func_00173D70(long *position);

    char unknown_04[0x10];
    long position;
};

// Slot 9: asks slot 6 for the status, copies the position (+0x14) out when asked and returns S_FALSE (1) when it is at
// or past the size in the status, else 0; a failure of slot 6 is returned as it is.
long __stdcall Object_001E3DE4::func_00173D70(long *position)
{
    Status status;
    long result = slot6(&status);
    if (result < 0)
        return result;
    if (position)
        *position = this->position;
    return this->position >= status.size;
}
