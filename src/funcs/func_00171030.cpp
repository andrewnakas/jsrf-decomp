/* sym: ??0Object_001E3C80@@QAE@PAUUnknown@@@Z = 0x00172BE0 */
struct Guid;
struct Unknown;
struct SoundBuffer;

// DirectSound's library code: calls slot 1 (AddRef) of the buffer object.
unsigned long __stdcall func_0019E4F7(SoundBuffer *buffer);

// The class whose table is at 0x1E3C80 (0x30 bytes): the object slot 14 makes.
struct Object_001E3C80 {
    Object_001E3C80(Unknown *outer);
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00172820(void *argument);

    char unknown_04[0x2c];
};

struct Object_001E3C08;

// Prepares the buffer (0x2c6 bytes of code; only slot 14 calls it).
long __stdcall func_00170D60(Object_001E3C08 *self);

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
    virtual long __stdcall func_00171030();

    char unknown_04[0xc];
    SoundBuffer *buffer;
    SoundBuffer *heldBuffer;
    unsigned long unknown_18;
    unsigned long flags;
    char unknown_20[0x818];
    Object_001E3C80 *child;
};

// Slot 14: makes the 0x1E3C80 object at +0x838 (its slot 3 takes this object) and prepares the buffer (0x170D60);
// with flag 0x10 it then keeps a reference to the buffer at +0x14. E_FAIL when there is a buffer already; if the
// constructor throws, its exception handler frees the memory.
long __stdcall Object_001E3C08::func_00171030()
{
    if (buffer)
        return 0x80004005;
    child = new Object_001E3C80(0);
    child->func_00172820(this);
    long result = func_00170D60(this);
    if (result >= 0) {
        if (flags & 0x10) {
            func_0019E4F7(buffer);
            heldBuffer = buffer;
        }
        result = 0;
    }
    return result;
}
