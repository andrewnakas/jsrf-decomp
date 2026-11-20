struct Guid;

// The object at +0xc.
struct Stream {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall slot7(unsigned __int64 *size);
    virtual void slot8();
    virtual long __stdcall slot9(unsigned long *value);
};

// The class whose table is at 0x1E3FB0: the one the MFile2 factory (0x1E3F1C) creates for the interface 0x1E3F34.
struct Object_001E3FB0 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall func_00177120(unsigned long *value);

    char unknown_04[8];
    Stream *stream;
    unsigned long first;
    unsigned long second;
};

// Slot 9: asks the object at +0xc for its 64-bit size (slot 7) and then for the value (slot 9); when the word at +0x14
// equalled that size, it takes the new value. E_INVALIDARG for a null pointer, 0x800401F0 (not initialised) without the
// object.
long __stdcall Object_001E3FB0::func_00177120(unsigned long *value)
{
    long result;
    if (stream) {
        if (value) {
            unsigned __int64 size;
            result = stream->slot7(&size);
            if (result >= 0) {
                result = stream->slot9(value);
                if (result >= 0) {
                    if (second == size)
                        second = *value;
                }
            }
        } else {
            result = 0x80070057;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
