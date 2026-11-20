struct Guid;

// The class whose table is at 0x1E3C08 (30 slots, the same Release as 0x1E3B90).
struct Object_001E3C08 {
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual long __stdcall func_00170070(int *count);

    char unknown_04[0x3c8];
    int count;
};

// Slot 24: copies the word at +0x3cc, plus one, out when the pointer is not null.
long __stdcall Object_001E3C08::func_00170070(int *count)
{
    if (count)
        *count = this->count + 1;
    return 0;
}
