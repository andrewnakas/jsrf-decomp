struct Interface_00265110 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27(int kind, int value);
};

extern Interface_00265110 *data_00265110;

struct Voice {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8(int value);
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual long __stdcall slot15(unsigned long first, unsigned long second);
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual long __stdcall slot23(unsigned long first, unsigned long second);
};

// What slot 22 of 0x1E1640 is handed: a voice and flags at +0x10.
struct Entry {
    Voice *voice;
    unsigned long unknown_04[3];
    unsigned long flags;
};

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159650(Entry *entry, unsigned long first, unsigned long second);  // slot 22
};

// Slot 22: sets slot 27 (6, -1) of the object at data_00265110, then runs the entry's voice (its slots 9 and 8 (0))
// and hands it the two values through slot 23 when flag 1 is set, else slot 15.
long __stdcall Object_001E1640::func_00159650(Entry *entry, unsigned long first, unsigned long second)
{
    data_00265110->slot27(6, -1);
    Voice *voice = entry->voice;
    if (entry->flags & 1) {
        voice->slot9();
        voice->slot8(0);
        return voice->slot23(first, second);
    }
    voice->slot9();
    voice->slot8(0);
    return voice->slot15(first, second);
}
