/* sym: ??0Object_001E3D30@@QAE@PAUUnknown@@@Z = 0x00173440 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The number of live objects of the library's RIFF file classes.
extern long data_002651A4;

// The class whose table is at 0x1E3D30: the one the MRIFFFile factory (0x1E3CD8) creates for IID_IUnknown and the
// interface 0x1E3D10 (0x118 bytes). Most of its slots pass the call on to the object at +0xc; slots 5, 6, 7 and 9
// hold the same functions as the table at 0x1E3FE4 and slots 10 to 17 the same as 0x1E3D88 (the linker folded the
// identical functions).
struct Object_001E3D30 {
    Object_001E3D30(Unknown *outer);
    virtual long __stdcall func_00173370(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00173010();
    virtual long __stdcall func_001730E0(void *argument1, void *argument2, void *argument3, void *argument4,
                                         void *argument5);
    virtual long __stdcall func_001731A0(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_001773A0(void *argument1, void *argument2);
    virtual long __stdcall func_001773C0(void *argument);
    virtual long __stdcall func_001773E0(void *argument);
    virtual long __stdcall func_001731C0(char *buffer, unsigned int size);
    virtual long __stdcall func_001775E0(void *argument);
    virtual long __stdcall func_00173210(void *argument);
    virtual long __stdcall func_00173230(void *argument);
    virtual long __stdcall func_00173250(void *argument);
    virtual long __stdcall func_00173270(void *argument);
    virtual long __stdcall func_00173290(void *argument);
    virtual long __stdcall func_001732B0(void *argument);
    virtual long __stdcall func_001732D0();
    virtual long __stdcall func_001732F0(void *argument);
    virtual long __stdcall func_00173160(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_00173180(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_001504B0(void *argument);

    // Lets go of the second object, the inner object and the controlling object and counts the object out (0x173310,
    // called by the deleting destructor 0x173420).
    virtual ~Object_001E3D30()
    {
        if (second) {
            second->slot2();
            second = 0;
        }
        if (inner) {
            inner->slot2();
            inner = 0;
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
    Unknown *second;
    char name[0x104];
};

// Constructor: one reference, no inner or second object; holds a reference to the controlling object, if any, and
// counts the object in.
Object_001E3D30::Object_001E3D30(Unknown *outer) : outer(outer), references(1), inner(0), second(0)
{
    if (this->outer)
        this->outer->slot1();
    _InterlockedIncrement(&data_002651A4);
}
