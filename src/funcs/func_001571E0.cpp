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
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual float __stdcall slot34(unsigned long index);
    virtual float __stdcall slot35(unsigned long index);
};

extern Interface_00265110 *data_00265110;

// A vertex of the quad: two words, then the three values the slot writes, then three more words.
struct Vertex {
    unsigned long unknown_00[2];
    float width;
    float height;
    unsigned long value;
    unsigned long unknown_14[3];
};

struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(Vertex **data, unsigned long flags);
    virtual void __stdcall slot5();
};

// A class whose table is at 0x1E141C (12 slots).
struct Object_001E141C {
    virtual long __stdcall func_001571E0(unsigned long value, unsigned long index);  // slot 6

    char unknown_04[0x1010];
    Buffer *buffer;
};

// Slot 6: writes the two sizes data_00265110 gives for the index (its slots 34 and 35) and the value into the
// four vertices of the buffer at +0x1014 (locked through its slot 4, unlocked through slot 5).
long __stdcall Object_001E141C::func_001571E0(unsigned long value, unsigned long index)
{
    float width = data_00265110->slot34(index);
    float height = data_00265110->slot35(index);
    Vertex *data = 0;
    long result = buffer->slot4(&data, 0);
    if (result < 0)
        return result;
    data[0].width = width;
    data[0].height = height;
    data[0].value = value;
    data[1].width = width;
    data[1].height = height;
    data[1].value = value;
    data[2].width = width;
    data[2].height = height;
    data[2].value = value;
    data[3].width = width;
    data[3].height = height;
    data[3].value = value;
    buffer->slot5();
    return 0;
}
