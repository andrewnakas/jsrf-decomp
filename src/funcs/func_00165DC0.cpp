/* sym: ??0Object_001E2008@@QAE@PAUUnknown@@@Z = 0x00165DC0 */
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

// The number of live objects of the library's input classes.
extern long data_0026517C;

struct Info;

// The class whose table is at 0x1E2008 (0x950 bytes).
struct Object_001E2008 {
    Object_001E2008(Unknown *outer);
    virtual long __stdcall func_00165D30(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00165570();
    virtual long __stdcall func_001655E0(void *argument);
    virtual long __stdcall func_00165670(Info *info);
    virtual long __stdcall func_00165C70(const void *data);
    virtual long __stdcall func_00165CD0(int value);
    virtual long __stdcall func_00165D00(int *value);

    // Lets go of the controlling object and counts the object out (inlined into the deleting destructor,
    // 0x165E50).
    virtual __forceinline ~Object_001E2008()
    {
        if (outer) {
            outer->slot2();
            outer = 0;
        }
        _InterlockedDecrement(&data_0026517C);
    }

    Unknown *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long first;
    char table1[0x100];
    char table2[0x400];
    char table3[0x400];
    unsigned long second;
    unsigned long third;
    char unknown_91c[0x2c];
    unsigned long fourth;
    int value;
};

// Constructor: one reference, the words and the three tables zero, the value at +0x94c 20; holds a reference to
// the controlling object, if any, and counts the object in.
Object_001E2008::Object_001E2008(Unknown *outer)
{
    this->outer = outer;
    references = 1;
    unknown_0c = 0;
    first = 0;
    second = 0;
    third = 0;
    fourth = 0;
    value = 20;
    if (outer)
        outer->slot1();
    memset(table1, 0, sizeof(table1));
    memset(table2, 0, sizeof(table2));
    memset(table3, 0, sizeof(table3));
    memset(unknown_91c, 0, sizeof(unknown_91c));
    _InterlockedIncrement(&data_0026517C);
}
