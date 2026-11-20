struct Guid;

// One 0x5c-byte description of the array slot 15 goes through.
struct Description {
    char unknown[0x5c];
};

// What slot 7 gives out for a description (slot 8 takes it; slot 2 lets go of it).
struct Created {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The class whose table is at 0x1E19E0 (0x144 bytes).
struct Object_001E19E0 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall slot7(Description *description, Created **created);
    virtual long __stdcall slot8(Created *created);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual long __stdcall func_00163CD0(void *argument1, void *argument2, void *argument3);

    void *outer;
    long references;
    unsigned long unknown_0c;
};

// Slot 15: for each of the `count` 0x5c-byte descriptions in the second argument, makes an object with slot 7 and
// hands it to slot 8 (letting go of it afterwards), stopping at the first failure; gives out how many went through and
// returns the last result. 0x80070057 (E_INVALIDARG) without a count or descriptions, 0x800401F0 (not initialised)
// while +0xc is null.
long __stdcall Object_001E19E0::func_00163CD0(void *argument1, void *argument2, void *argument3)
{
    long result;
    if (unknown_0c) {
        if (argument1 && argument2) {
            unsigned int count = (unsigned int)argument1;
            Description *description = (Description *)argument2;
            unsigned int done = 0;
            for (; done < count; done++, description++) {
                Created *created;
                result = slot7(description, &created);
                if (result < 0)
                    break;
                result = slot8(created);
                if (created) {
                    created->slot2();
                    created = 0;
                }
                if (result < 0)
                    break;
            }
            if (argument3)
                *(unsigned int *)argument3 = done;
        } else {
            result = 0x80070057;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
