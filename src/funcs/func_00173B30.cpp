/* sym: ??0Object_001E3D88@@QAE@PAUUnknown@@@Z = 0x00173B30 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The system library's process heap and heap free.
void *__stdcall func_0014A838();
int __stdcall func_0014A821(void *heap, unsigned long flags, void *memory);

// The number of live objects of the library's RIFF file classes.
extern long data_002651A4;

// The class whose table is at 0x1E3D88: the one the MRIFFFile factory (0x1E3CD8) creates for the interface 0x1E3CF0
// (0x28 bytes). Slots 5 to 9 hold the same functions as the table at 0x1E3FE4 and slots 10 to 17 the same as
// 0x1E3D30 (the linker folded the identical functions).
struct Object_001E3D88 {
    Object_001E3D88(Unknown *outer);
    virtual long __stdcall func_00173A40(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00173480();
    virtual long __stdcall func_001734B0(void *argument1, void *argument2, void *argument3, void *argument4,
                                         void *argument5);
    virtual long __stdcall func_00173950(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_001773A0(void *argument1, void *argument2);
    virtual long __stdcall func_001773C0(void *argument);
    virtual long __stdcall func_001773E0(void *argument);
    virtual long __stdcall func_00177400(void *argument1, void *argument2);
    virtual long __stdcall func_001775E0(void *argument);
    virtual long __stdcall func_00173210(void *argument);
    virtual long __stdcall func_00173230(void *argument);
    virtual long __stdcall func_00173250(void *argument);
    virtual long __stdcall func_00173270(void *argument);
    virtual long __stdcall func_00173290(void *argument);
    virtual long __stdcall func_001732B0(void *argument);
    virtual long __stdcall func_001732D0();
    virtual long __stdcall func_001732F0(void *argument);
    virtual long __stdcall func_00173910(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_00173930(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_001739C0(void *argument);
    virtual long __stdcall func_001738D0(unsigned long *first, unsigned long *second, unsigned long *third);

    // Lets go of the inner object, frees the buffer with the process heap, lets go of the controlling object and
    // counts the object out (0x1739E0, called by the deleting destructor 0x173B10).
    virtual ~Object_001E3D88()
    {
        if (inner) {
            inner->slot2();
            inner = 0;
        }
        if (buffer) {
            func_0014A821(func_0014A838(), 0, buffer);
            buffer = 0;
        }
        if (outer) {
            outer->slot2();
            outer = 0;
        }
        _InterlockedDecrement(&data_002651A4);
    }

    Unknown *outer;
    long references;
    Unknown *inner;
    void *buffer;
    unsigned long unknown_14;
    unsigned long unknown_18;
    bool unknown_1c;
    unsigned long unknown_20;
    unsigned long unknown_24;
};

// Constructor: one reference, no inner object and no buffer, the words at +0x14 and the flag at +0x1c zero; holds a
// reference to the controlling object, if any, and counts the object in.
Object_001E3D88::Object_001E3D88(Unknown *outer)
    : outer(outer), references(1), inner(0), buffer(0), unknown_14(0), unknown_18(0), unknown_1c(false)
{
    if (this->outer)
        this->outer->slot1();
    _InterlockedIncrement(&data_002651A4);
}
