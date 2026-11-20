/* sym: ??0Object_001E3F84@@QAE@PAUUnknown@@@Z = 0x00176CA0 */
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

// A 64-bit value as two words.
struct Pair {
    unsigned long low;
    unsigned long high;
};

// The system library's close, process heap and heap free.
int __stdcall func_00145585(void *handle);
void *__stdcall func_0014A838();
int __stdcall func_0014A821(void *heap, unsigned long flags, void *memory);

// The number of live MFile2 objects.
extern long data_002651BC;

// The class's interface (the table at 0x1E3F84). The fields follow it at +4, so the 64-bit ones are not padded.
struct FileInterface {
    virtual long __stdcall func_00176C10(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_001766A0();
    virtual long __stdcall func_001766D0(void *argument);
    virtual long __stdcall func_00176850(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_00178D80(long offset, int origin);
    virtual long __stdcall func_00176800(unsigned __int64 *position);
    virtual long __stdcall func_00178E00(Pair *size);
    virtual long __stdcall func_001791C0(char *name, unsigned int size);
    virtual long __stdcall func_00179210(const Pair *size);
};

// The class whose table is at 0x1E3F84: the one the MFile2 factory (0x1E3F1C) creates for IID_IUnknown and the
// interface 0x1E3F64 (0x138 bytes).
struct Object_001E3F84 : FileInterface {
    Object_001E3F84(Unknown *outer);
    virtual long __stdcall func_00176C10(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_001766A0();
    virtual long __stdcall func_001766D0(void *argument);
    virtual long __stdcall func_00176850(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_00178D80(long offset, int origin);
    virtual long __stdcall func_00176800(unsigned __int64 *position);
    virtual long __stdcall func_00178E00(Pair *size);
    virtual long __stdcall func_001791C0(char *name, unsigned int size);
    virtual long __stdcall func_00179210(const Pair *size);

    // Frees the buffer, closes the file, lets go of the controlling object and counts the object out (0x176BB0,
    // called by the deleting destructor 0x176D10).
    virtual ~Object_001E3F84()
    {
        if (buffer) {
            func_0014A821(func_0014A838(), 0, buffer);
            buffer = 0;
        }
        if (file != (void *)-1)
            func_00145585(file);
        if (outer) {
            outer->slot2();
            outer = 0;
        }
        _InterlockedDecrement(&data_002651BC);
    }

    Unknown *outer;
    long references;
    void *file;
    unsigned __int64 size;
    unsigned __int64 position;
    void *buffer;
    unsigned long bufferSize;
    unsigned long unknown_28;
    unsigned long unknown_2c;
    unsigned long unknown_30;
    unsigned long unknown_34;
    char name[0x100];
};

// Constructor: one reference, no file (-1), no buffer yet but a buffer size of 0x1000, the size, the position and
// the words at +0x28 zero; holds a reference to the controlling object, if any, and counts the object in.
Object_001E3F84::Object_001E3F84(Unknown *outer)
{
    this->outer = outer;
    references = 1;
    file = (void *)-1;
    buffer = 0;
    bufferSize = 0x1000;
    if (outer)
        outer->slot1();
    position = 0;
    size = 0;
    unknown_28 = 0;
    unknown_2c = 0;
    unknown_30 = 0;
    unknown_34 = 0;
    _InterlockedIncrement(&data_002651BC);
}
