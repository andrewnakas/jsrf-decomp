/* sym: ??0Object_001E4020@@QAE@PAUUnknown@@@Z = 0x00178B70 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);
extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);
void __cdecl operator delete(void *memory) throw();

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The number of live MFile2 objects.
extern long data_002651BC;

// The class whose table is at 0x1E4020: one of the classes the MFile2 factory (0x1E3F1C) creates (0x14c bytes). Its
// Release is MGameInput8's (the linker folded the identical functions).
struct Object_001E4020 {
    Object_001E4020(Unknown *outer);
    virtual long __stdcall func_001787A0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_0015FD40();
    virtual long __stdcall func_00178A00(void *argument1, void *argument2, void *argument3, void *argument4,
                                         void *argument5);
    virtual long __stdcall func_001782A0(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_00178070(void *argument1, void *argument2);
    virtual long __stdcall func_001780A0(void *argument);
    virtual long __stdcall func_001780D0(void *argument);
    virtual long __stdcall func_001783D0(char *text, void *argument);
    virtual long __stdcall func_00178670(void *argument);
    virtual long __stdcall func_00178420(void *argument);
    virtual long __stdcall func_00178520(void *argument);
    virtual long __stdcall func_00178610(void *argument);
    virtual long __stdcall func_00178640(void *argument);
    virtual long __stdcall func_00178700(void *argument);
    virtual long __stdcall func_00178100(int);
    virtual long __stdcall func_001786B0();
    virtual long __stdcall func_00178B30(int flush);

    // Lets go of the objects it holds (0x178000) and of the controlling object and counts the object out (inlined
    // into the deleting destructor 0x178BF0).
    virtual __forceinline ~Object_001E4020()
    {
        func_00178000();
        if (outer) {
            outer->slot2();
            outer = 0;
        }
        _InterlockedDecrement(&data_002651BC);
    }

    void func_00178000();

    Unknown *outer;
    long references;
    unsigned long unknown_0c[11];
    unsigned long unknown_38;
    unsigned long unknown_3c;
    unsigned long unknown_40[0x43];
};

// Constructor: one reference, the words at +0xc zero, 0x800 at +0x38 and 100 at +0x3c; holds a reference to the
// controlling object, if any, clears the block at +0x40 and counts the object in.
Object_001E4020::Object_001E4020(Unknown *outer) : outer(outer), references(1)
{
    unknown_0c[0] = 0;
    unknown_0c[1] = 0;
    unknown_0c[2] = 0;
    unknown_0c[3] = 0;
    unknown_0c[4] = 0;
    unknown_0c[5] = 0;
    unknown_0c[6] = 0;
    unknown_0c[7] = 0;
    unknown_0c[8] = 0;
    unknown_0c[9] = 0;
    unknown_0c[10] = 0;
    unknown_38 = 0x800;
    unknown_3c = 100;
    if (outer)
        outer->slot1();
    memset(unknown_40, 0, sizeof(unknown_40));
    _InterlockedIncrement(&data_002651BC);
}
