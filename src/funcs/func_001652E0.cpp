struct Guid;
struct Unknown;

// The objects the class keeps in its vector at +0x118 (slot 1 adds a reference).
struct Registered {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
};

// A std::vector of pointers.
struct RegisteredList {
    void func_00161780(Registered *const &value);

    char allocator;
    Registered **first;
    Registered **last;
    Registered **end;
};

// The class whose table is at 0x1E19E0.
struct Object_001E19E0 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall func_001652E0(void *argument);

    Unknown *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long block[0x41];
    unsigned long unknown_114;
    RegisteredList items;
};

// Slot 4: keeps the object in the vector at +0x118 with a reference added (through the append 0x161780); 1 when it is
// already there. 0x80070057 (E_INVALIDARG) without an object, 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E19E0::func_001652E0(void *argument)
{
    if (unknown_0c) {
        if (argument) {
            for (Registered **entry = items.first; entry != items.last; ++entry) {
                if (*entry == argument)
                    return 1;
            }
            ((Registered *)argument)->slot1();
            items.func_00161780(reinterpret_cast<Registered *const &>(argument));
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
