// The three writers (SSE): destination in ecx, first in edx, then the words at +0xC and +0x10.
void __fastcall func_0015A6A0(void *destination, unsigned long first, unsigned long third, unsigned long fourth);
void __fastcall func_0015A720(void *destination, unsigned long first, unsigned long third, unsigned long fourth);
void __fastcall func_0015A7B0(void *destination, unsigned long first, unsigned long third, unsigned long fourth);

struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual long __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual long __stdcall slot8(unsigned long flags);
    virtual long __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual long __stdcall slot13(unsigned int count);
};

// A class whose table is at 0x1E144C (11 slots; Release 0x157DB0).
struct Object_001E144C {
    virtual void __stdcall func_0015A960(unsigned long first, int kind);  // slot 9

    Buffer *buffer;
    unsigned long value_08;
    unsigned long value_0C;
    unsigned long value_10;
};

// Slot 9: locks the buffer at +4, fills it from first with the writer kind picks (0, 1 or 2; the words at +0xC and
// +0x10 too), unlocks it and starts it again (slots 8, 9 and 13 with 2, or 1 for kind 2).
void __stdcall Object_001E144C::func_0015A960(unsigned long first, int kind)
{
    void *data = 0;
    switch (kind) {
    case 0:
        if (buffer->slot4(&data, 0) < 0)
            return;
        func_0015A6A0(data, first, value_0C, value_10);
        buffer->slot5();
        buffer->slot8(0);
        buffer->slot9();
        buffer->slot13(2);
        break;
    case 1:
        if (buffer->slot4(&data, 0) < 0)
            return;
        func_0015A720(data, first, value_0C, value_10);
        buffer->slot5();
        buffer->slot8(0);
        buffer->slot9();
        buffer->slot13(2);
        break;
    case 2:
        if (buffer->slot4(&data, 0) < 0)
            return;
        func_0015A7B0(data, first, value_0C, value_10);
        buffer->slot5();
        buffer->slot8(0);
        buffer->slot9();
        buffer->slot13(1);
        break;
    }
}
