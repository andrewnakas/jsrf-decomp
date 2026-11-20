struct Guid;

// An object a voice gives out (slot 2 lets go of it).
struct Part {
    virtual void slot0();
    virtual void slot1();
    virtual unsigned long __stdcall slot2();
};

// One of the objects in MGameSound8's list.
struct Voice {
    virtual void slot0();
    virtual void slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(void *argument, Part *part);
    virtual long __stdcall slot7(void *argument, Part **part);
    virtual void slot8();
    virtual long __stdcall slot9(Part *part, Part **result);
};

// The list at +0x1c (a std::vector of pointers: the executable carries its "vector<T> too long").
struct VoiceList {
    char allocator;
    Voice **first;
    Voice **last;
    Voice **end;

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
};

// MGameSound8's first interface: the table at 0x1E3A70.
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall func_00168AF0(unsigned int index, Voice **voice);
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
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual long __stdcall func_00168260(unsigned int index, void *argument1, void *argument2);
};

// MGameSound8's second interface, at +4: the table at 0x1E3A5C.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates (0x2c
// bytes).
struct MGameSound8 : FirstInterface, SecondInterface {
    virtual long __stdcall func_00168AF0(unsigned int index, Voice **voice);
    virtual long __stdcall func_00168260(unsigned int index, void *argument1, void *argument2);

    void *outer;
    long references;
    char unknown_10[0xc];
    VoiceList voices;
};

// Slot 34: takes entry `index` of the list (slot 5), has its slot 7 make an object from the first argument and its
// slot 9 a second one from that, and passes the second argument and the second object to its slot 6. Lets go of
// everything it took (retail keeps the stores of 0 after the releases, 0x1682D5 and 0x1682EB).
long __stdcall MGameSound8::func_00168260(unsigned int index, void *argument1, void *argument2)
{
    Voice *voice;
    long result = func_00168AF0(index, &voice);
    if (result >= 0) {
        Part *first;
        result = voice->slot7(argument1, &first);
        if (result >= 0) {
            Part *second;
            result = voice->slot9(first, &second);
            if (result >= 0) {
                result = voice->slot6(argument2, second);
                if (second) {
                    second->slot2();
                    second = 0;
                }
            }
            if (first) {
                first->slot2();
                first = 0;
            }
        }
        if (voice)
            voice->slot2();
    }
    return result;
}
