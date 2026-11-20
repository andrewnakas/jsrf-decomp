/* sym: ??0Object_001E3C80@@QAE@PAUUnknown@@@Z = 0x00172BE0 */
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

// A 0x18-byte block whose first word is its size.
struct Block {
    unsigned long size;
    unsigned long words[5];
};

struct Info;

// The number of live objects of the library's RIFF file class.
extern long data_00265198;

// The class whose table is at 0x1E3C80 (0x30 bytes).
struct Object_001E3C80 {
    Object_001E3C80(Unknown *outer);
    virtual long __stdcall func_00172B50(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00165570();
    virtual long __stdcall func_00172820(void *handle);
    virtual long __stdcall func_00172870();
    virtual long __stdcall func_00172850();
    virtual long __stdcall func_00172AD0(const Block *block);
    virtual long __stdcall func_00172B20(Info *info);

    // Lets go of the controlling object and counts the object out (inlined into the deleting destructor,
    // 0x172C30).
    virtual __forceinline ~Object_001E3C80()
    {
        if (outer) {
            outer->slot2();
            outer = 0;
        }
        _InterlockedDecrement(&data_00265198);
    }

    Unknown *outer;
    long references;
    void *handle;
    Block block;
    int low;
    int high;
};

// Constructor: one reference, no handle, the block and both words zero; holds a reference to the controlling
// object, if any, and counts the object in.
Object_001E3C80::Object_001E3C80(Unknown *outer)
{
    this->outer = outer;
    references = 1;
    handle = 0;
    if (outer)
        outer->slot1();
    memset(&block, 0, sizeof(block));
    low = 0;
    high = 0;
    _InterlockedIncrement(&data_00265198);
}
