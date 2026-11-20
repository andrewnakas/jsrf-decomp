/* sym: ??0Object_001E1FE4@@QAE@PAUUnknown@@@Z = 0x001654E0 */
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

// A block of 0x13c bytes whose first word is its size.
struct Info {
    unsigned long size;
    char data[0x138];
};

// The number of live objects of the library's input classes.
extern long data_0026517C;

// The class whose table is at 0x1E1FE4 (0x150 bytes).
struct Object_001E1FE4 {
    Object_001E1FE4(Unknown *outer);
    virtual long __stdcall func_00165450(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00165570();
    virtual long __stdcall func_00165350(const Info *info);
    virtual long __stdcall func_00165380(int *first, int *second);
    virtual long __stdcall func_001653B0(char *name, unsigned int size);
    virtual long __stdcall func_00165400(int first, int second);
    virtual long __stdcall func_00165420(Info *info);

    // Lets go of the controlling object and counts the object out (inlined into the deleting destructor,
    // 0x165530).
    virtual __forceinline ~Object_001E1FE4()
    {
        if (outer) {
            outer->slot2();
            outer = 0;
        }
        _InterlockedDecrement(&data_0026517C);
    }

    Unknown *outer;
    long references;
    int first;
    int second;
    Info info;
};

// Constructor: one reference, both values zero, an empty block; holds a reference to the controlling object, if
// any, and counts the object in.
Object_001E1FE4::Object_001E1FE4(Unknown *outer)
{
    this->outer = outer;
    references = 1;
    first = 0;
    second = 0;
    if (outer)
        outer->slot1();
    memset(&info, 0, sizeof(info));
    _InterlockedIncrement(&data_0026517C);
}
