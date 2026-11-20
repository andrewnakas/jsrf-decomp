/* sym: ??0Object_001E202C@@QAE@PAUUnknown@@@Z = 0x00166330 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);
extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// What slots 3 and 7 keep and give out (0x5c bytes, its size first).
struct Description {
    unsigned long size;
    unsigned long unknown_04;
    unsigned long values[4];
    void *entries[8];
    char block[0x20];
    unsigned long last;
};

struct Values;
struct Info;

// The number of live objects of the library's input classes.
extern long data_0026517C;

// The class whose table is at 0x1E202C (0x8c bytes).
struct Object_001E202C {
    Object_001E202C(Unknown *outer);
    virtual long __stdcall func_001662A0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00165E90();
    virtual long __stdcall func_00165EC0(const Description *description);
    virtual long __stdcall func_00165F20(const Values *values);
    virtual long __stdcall func_00165F70(Values *values);
    virtual long __stdcall func_00165FD0(Info *info);
    virtual long __stdcall func_00166020(Description *description);
    virtual long __stdcall func_00166060(void *argument);
    virtual long __stdcall func_001663E0(void *argument);
    virtual long __stdcall func_00166240(int value);
    virtual long __stdcall func_00166270(int *value);

    // Lets go of the controlling object and counts the object out (inlined into the deleting destructor,
    // 0x1663A0).
    virtual __forceinline ~Object_001E202C()
    {
        if (outer) {
            outer->slot2();
            outer = 0;
        }
        _InterlockedDecrement(&data_0026517C);
    }

    Unknown *outer;
    long references;
    unsigned long first;
    unsigned long second;
    unsigned long fourth;
    int value;
    unsigned long third;
    unsigned long unknown_20;
    unsigned long unknown_24;
    unsigned long unknown_28;
    unsigned int count;
    Description description;
};

// Constructor: one reference, the words zero, the value at +0x18 20 and an empty description; holds a reference to
// the controlling object, if any, and counts the object in.
Object_001E202C::Object_001E202C(Unknown *outer)
{
    this->outer = outer;
    references = 1;
    first = 0;
    second = 0;
    fourth = 0;
    value = 20;
    third = 0;
    unknown_20 = 0;
    unknown_24 = 0;
    unknown_28 = 0;
    if (outer)
        outer->slot1();
    memset(&description, 0, sizeof(description));
    _InterlockedIncrement(&data_0026517C);
}
