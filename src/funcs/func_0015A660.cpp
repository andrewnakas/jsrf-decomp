struct Voice {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual long __stdcall slot8(unsigned long flags);
    virtual long __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual long __stdcall slot15(int offset, unsigned long flags);
};

// A class whose table is at 0x1E144C (11 slots; Release 0x157DB0).
struct Object_001E144C {
    virtual long __stdcall func_0015A660(int position);  // slot 10

    Voice *voice;
    int position;
};

// Stops the object at +4 and starts it again at the position (the one at +8 for -1), in bytes.
long __stdcall Object_001E144C::func_0015A660(int position)
{
    if (position == -1)
        position = this->position;
    voice->slot8(0);
    voice->slot9();
    return voice->slot15(position * 2, 0);
}
