extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E4C94;
extern const Guid data_001E3E2C;
extern const Guid data_001E3E1C;

// Equal when they are the same object or have the same sixteen bytes (the out-of-line copy is at 0x15FA30).
inline bool operator==(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MemStream's first interface: the table at 0x1E3EA8 up to slot 16.
struct FirstInterface {
    virtual long __stdcall func_001753D0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00174C40();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
};

// MemStream's second interface, at +4: the table at 0x1E3E98 (the first three slots are adjustor thunks to
// MemStream's own).
struct SecondInterface {
    virtual long __stdcall func_001753D0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00174C40();
    virtual long __stdcall slot3(void *first, void *second);
};

// MemStream, the class its factory (table 0x1E3E80, after the "MUSASHI.MemStream.1" strings) creates. Its own table
// is 0x1E3EA8 (18 slots; the destructor is the last).
struct MemStream : FirstInterface, SecondInterface {
    virtual long __stdcall func_001753D0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00174C40();
    virtual ~MemStream();

    Unknown *outer;
    long references;
};

// QueryInterface (slot 0): IID_IUnknown (0x1E4C94) and the first interface (0x1E3E2C) give the object itself, the
// second interface (0x1E3E1C) the object at +4, each with a reference; anything else is asked of the controlling
// object at +8, or fails with E_NOINTERFACE.
long __stdcall MemStream::func_001753D0(const Guid &id, void **object)
{
    long result;
    if (id == data_001E4C94 || id == data_001E3E2C) {
        *object = this;
        func_00174C20();
        result = 0;
    } else if (id == data_001E3E1C) {
        SecondInterface *second = this;
        *object = second;
        second->func_00174C20();
        result = 0;
    } else if (outer) {
        return outer->slot0(id, object);
    } else {
        *object = 0;
        result = 0x80004002;
    }
    return result;
}
