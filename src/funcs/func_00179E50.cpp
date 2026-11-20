/* sym: ??1Object_001E4130@@UAE@XZ = 0x00179E50 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);
void __cdecl operator delete(void *memory) throw();

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The objects in the list at +0x10.
struct Listener;

// The system library's close.
int __stdcall func_00145585(void *handle);

// A std::vector of pointers.
struct ListenerList {
    ListenerList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~ListenerList()
    {
        if (first)
            operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }

    char allocator;
    Listener **first;
    Listener **last;
    Listener **end;
};

// The name at +0x20 (a std::string: the characters live in the 16-byte buffer while they fit).
struct String {
    String()
    {
        tidy();
    }
    ~String()
    {
        if (reserved >= 16)
            operator delete(pointer());
        tidy();
    }
    char *pointer()
    {
        return reserved >= 16 ? text.pointer : text.buffer;
    }
    void tidy()
    {
        reserved = 15;
        pointer()[size = 0] = 0;
    }

    char allocator;
    union {
        char buffer[16];
        char *pointer;
    } text;
    unsigned int size;
    unsigned int reserved;
};

// The number of live MEvent objects.
extern long data_002651C8;

// The class whose table is at 0x1E4130: the one the MEvent factory (0x1E40C4) creates for the interface 0x1E40DC
// (0x3c bytes). Its Release is the one of 0x1E202C and slot 4 the one of 0x1E410C (the linker folded the identical
// functions).
struct Object_001E4130 {
    Object_001E4130(Unknown *outer);
    virtual long __stdcall func_00179A50(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00165E90();
    virtual long __stdcall func_00179FA0(void *attributes, int manual, int signalled, const char *name);
    virtual long __stdcall func_00179A20(void **event);
    virtual long __stdcall func_0017A3E0(void *argument1, void *argument2);
    virtual long __stdcall func_00179B80(int argument);
    virtual long __stdcall func_00179BD0(int argument);
    virtual long __stdcall func_0017A5C0(Listener *listener);
    virtual long __stdcall func_00179C70(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00179DB0(Listener *listener);
    virtual long __stdcall func_00179C20(char *buffer, unsigned int size);
    virtual ~Object_001E4130();

    Unknown *outer;
    long references;
    void *event;
    ListenerList listeners;
    String name;
};

// Destructor: lets go of every listener (slot 10 with none given), closes the event, lets go of the controlling
// object and counts the object out; the name and the list free their blocks.
Object_001E4130::~Object_001E4130()
{
    func_00179DB0(0);
    if (event) {
        func_00145585(event);
        event = 0;
    }
    if (outer) {
        outer->slot2();
        outer = 0;
    }
    _InterlockedDecrement(&data_002651C8);
}
